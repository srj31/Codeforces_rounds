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
const int mxn = 1e6+10;

// vector<vector<int> > adj(mxn);
int dp[mxn];
int n;
int a[mxn];

void dfs(int v){
	if(v>n/2){
		// cout << v << " e nd " << endl;
		dp[v] = 1;
		return;
	}
	for(int i=v+v;i<=n;i+=v){
		dfs(i);
		// cout << v << ' ' << i << endl;

		if(a[v]<a[i]){
			// cout << "inc" << endl;
			dp[v] = max(dp[v],1+dp[i]);
		}
	}
}

void solve(){
	cin >> n;
	// int a[n+1];
	for(int i =1;i<=n;i++)
		cin >> a[i];
	int ans = 1;
	forn(i,0,n+1) dp[i] = 1;
	dfs(1);
	forn(i,1,n+1) {
		// cout << dp[i] << " ";
		ans = max(ans,dp[i]);
	}
	// cout << endl;
	cout << ans << endl;

}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// // primes[0] = primes[1] = 0;
	// for(int i =2;i<mxn;i++){
	// 	if(primes[i].size() == 0)continue;

	// 	for(int j = i+i;j<mxn;j+=i){
	// 		primes[j].pb(i);
	// 	}

	// }
	int t;cin >> t;while(t--)
		solve();
}
