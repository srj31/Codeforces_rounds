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
	long long int a1,k;
	cin >> a1 >> k;
	k--;
	while(k--){
		int mini = 10;
		int maxi = 0;
		ll cpy = a1;
		while(cpy>0){
			int d = cpy%10;
			mini = min(mini,d);
			maxi = max(maxi, d);
			cpy/=10;
		}
		// cout << mini <<" " << maxi << endl;
		if(mini == 0){
			cout << a1 << endl;
			return;
		}
		a1 += mini*maxi;
	}
	cout << a1 << endl;
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
