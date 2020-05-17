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
	ll a,b,c,d;
	ll ans = 0;
	cin >> a >> b >> c >> d;
	ll curr = 0;
	curr+=b;
	if(curr>=a){
		ans = curr;
		cout << ans << endl;
		return;
	}
	ans = curr;
	if(d>=c){
		cout << -1 << endl;return;
	}

	curr = c-d;
	ll more = a-ans;
	ans+= ceil(1.0*more/curr*1.0)*c;

	cout << ans << endl;
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w",stdout);
	#endif

	int t;cin >> t;while(t--)
		solve();
}
