#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;


typedef long long int ll;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


const ll INF = 1e15;
const ll mxn = 2e5+10;
vector<ll> adj[mxn];
ll msmatch[mxn];
ll zs[mxn][2],os[mxn][2];
struct node{
	ll a,b,c;
};
vector<node> val(mxn);

void dfs(ll u ,ll p=-1){
	if(val[u].b!=val[u].c)
		msmatch[u]=1;

	if(val[u].b ==1){
		os[u][0] = 1;
	}
	if(val[u].c==1)
		os[u][1] = 1;

	if(val[u].b==0)
		zs[u][0] = 1;
	if(val[u].c==0)
		zs[u][1] = 1;
	for(int v:adj[u]){
		if(v==p)continue;

		dfs(v,u);
		msmatch[u]+=msmatch[v];
		os[u][0] += os[v][0];
		os[u][1] +=os[v][1];
		zs[u][0] +=zs[v][0];
		zs[u][1] +=zs[v][1];

	}
	// cout << u << " " << os[u][1] << os[u][0] << zs[u][1] << zs[u][0] << endl;
}

ll dp[mxn];
void dfs2(ll u,ll p=-1){
	dp[u] = msmatch[u]*val[u].a;
	ll can = 1;
	ll cnt = 0;
	if(zs[u][0]!=zs[u][1] || os[u][1]!=os[u][0])
		can=0;
	ll another = 0;
	ll n = adj[u].size();
	vi should;
	vi ns;	
	for(int v:adj[u]){
		if(v==p)continue;

		dfs2(v,u);
	}
	if(!can)
		dp[u] = INF;
	else{
		for(int v:adj[u]){
			if(v==p) continue;

			if(dp[v]>val[u].a*msmatch[v]){
				should.pb(v);
			}
			else{
				ns.pb(v);
			}
		}
		for(int e:should){
			another+= val[u].a*msmatch[e];
		}
		for(int e:ns){
			another+= dp[e];
		}

		if(val[u].b!=val[u].c)
			another+= val[u].a;
		if(!can)
			dp[u] = INF;
		else
			dp[u] = min(dp[u],another);

	}
	

}

void solve(){
	ll n;
	cin >> n;
	// vector<node> val(n);
	for(ll i =0;i<n;i++){
		cin >> val[i].a >> val[i].b >> val[i].c;
	}
	for(ll i =0;i<n;i++){
		dp[i] = INF; 
	}
	for(ll i =0;i<n-1;i++){
		ll u,v;
		cin >> u >> v;
		--u , --v;
		adj[u].pb(v);adj[v].pb(u);
	}
	dfs(0);
	dfs2(0);

	forn(i,0,n)
		cout << dp[i] <<" " << i << endl;
	if(dp[0]>=INF){
		cout << -1 << endl;return;
	}
	cout << dp[0] << endl;
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// int t;cin >> t;while(t--)
		solve();
}
