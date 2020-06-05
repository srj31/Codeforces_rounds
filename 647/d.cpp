#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;


typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mxn = 5e5+10;

vi adj[mxn];
int vis[mxn];

bool dfs(int u ,int * vals){
	vis[u] = 1;
	int check[vals[u]+1];
	memset(check,0,sizeof(check));
	int cnt = 0;
	int pos = true;
	for(auto v:adj[u]){
		if(!vis[v]){
			pos&=dfs(v,vals);
		}
		if(vals[v]==vals[u]){
			pos&=false;
				// cout << u << " " << cnt << " " << vals[u] << " " << v<< endl;

		}
		if(vals[v]<vals[u]){
			if(check[vals[v]]==0){
				cnt++;
				check[vals[v]]++;

			}
		}
	}
	// cout << u << " " << cnt << " " << vals[u] << " "<< endl;

	if(cnt!=vals[u]-1){
		pos&=false;
	}
	return pos;
}

void solve(){
	int n,m;
	cin >> n >> m;

	for(int i =0;i<m;i++){
		int u,v;
		cin >> u >> v;
		--u,--v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int vals[n];
	map<int,vi> what;
	for(int i =0;i<n;i++){
		cin >> vals[i];
		what[vals[i]].pb(i);
	}
	vector<int> ans(n);
	int order = 0;
	for(auto e:what){
		int to_put = e.first;
		for(auto e2:e.second){
			ans[order]=e2;
			order++;
		}

	}

	bool pos  = dfs(0,vals);
	if(!pos){
		cout << -1 << endl;
	}
	else{
		for(int e: ans){
			cout << e+1 << " ";
		}
		cout << endl;
	}

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
