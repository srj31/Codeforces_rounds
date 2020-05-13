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
const int mxN = 1e5;

vector<long long int> dp(mxN);

void solve(){
	int n;
	cin >> n;
	int count = 0;
	// cout << n <<endl;
	while(n>0){
		 int nh = upper_bound(dp.begin(),dp.end(),n) - dp.begin();
		 nh--;
		 // cout << nh << endl;
		 if(nh==0)
		 {
		 	break;
		 }
		 count++;
		 n-=dp[nh];
		 // cout << n << endl;
	}
	cout << count << endl;

}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	dp[1] = 2;
	dp[2] = 7;
	for(int i =3;i<mxN;i++){
		dp[i] = dp[i-1] + 2*i + i-1;
		// cout << dp[i] << endl;
	}
	int t;cin >> t;while(t--)
		solve();
}