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
	string s;
	cin >> s;
	// first one is 1 or 0
	int n = s.length();
	int dp[n+1][2];
	memset(dp,0,sizeof(dp));
	int ans = n + 1;
	for(int i =0;i<n;i++){
		// till ith position its 11s
		int cur1=0;
		int cur0 = 0;
		for(int j =0;j<=i;j++){
			if(s[j]=='0'){
				cur1++;
			}
			else
				cur0++;
		}
		for(int j = i+1;j<n;j++){
			if(s[j]=='0')
				cur0++;
			else cur1++;
		}
		// cout << cur0<< " " << cur1 << endl;
		ans = min(ans,min(cur0,cur1));
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
