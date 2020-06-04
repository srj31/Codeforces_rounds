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


void solve(){
	ll n,m,x,y;
	cin >> n >> m >> x >> y;
	ll best2 = min(2*x,y);
	string g[n];
	for(ll i =0;i<n;i++)
		cin >> g[i];
	ll ans = 0;
	for(ll i =0;i<n;i++){
		for(ll j =0;j<m-1;j++){
			if(g[i][j]=='.'){
				g[i][j]='*';
				if(g[i][j+1]=='.'){
					g[i][j+1] ='*';
					ans+=best2;
					// j++;
				}
				else{
					ans+=x;
				}
			}
		}
		if(g[i][m-1]=='.')
			ans+=x;
	}
	cout << ans << endl;
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
