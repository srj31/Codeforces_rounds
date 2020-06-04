#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;

const int mxn = 1e3+10;
vector<vector<int> >  adj;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int lvl[mxn];
int sz[mxn];
void dfs(int u,int p =-1,int d=0){
	lvl[u] = d;
	sz[u]++;
	// cout << u << endl;
	for(auto v:adj[u]){
		if(v==p)continue;

		dfs(v,u,d+1);
		sz[u]+=sz[v];
	}
}
void solve(){

	int n,x;
	cin >> n >> x;
	--x;
	adj = vector<vector<int> > (n);
	vi ls;
	// cout << 1 << endl;
	for(int i =0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		--u , --v;
		adj[u].pb(v);adj[v].pb(u);
	}
	// cout << 2 << endl;
	memset(lvl,0,sizeof(lvl));
	memset(sz,0,sizeof(sz));

	// int root = x-1;
	int root = x;
	dfs(root);
	for(int i =0;i<n;i++){
		if(adj[i].size()<=1){
			ls.pb(i);
			if(i==x){
				cout << "Ayush" << endl;return;
			}
		}
	}
	// forn(i,0,n){
	// 	cout << lvl[i] << " ";
	// }
	// cout << endl;
	int moves = 0;
	for(auto v:adj[root]){
		moves+=sz[v];
	}
	if((moves+1)%2){
		cout << "Ashish" << endl;return;
	}
	else{
		cout << "Ayush" << endl;return;
	}

}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int t;cin >> t;while(t--)
		solve();
}
