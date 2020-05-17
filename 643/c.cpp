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

void naive(ll a, ll b, ll c, ll d) {
	ll ans = 0;
	for (ll z = c; z <= d; z++) {
		for (ll y = b; y <= c; y++) {
			for (ll x = a; x <= b; x++) {
				if (x + y > z && x<=y) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}

void solve(){
	long long int a,b,c,d;
	cin >> a >> b >> c >> d;
	naive(a,b,c,d);
	long long int ans = 0;
	for(int z = c ; z<=d;z++){
		// find the lowest x for which it exists

		ll l = a,r=b;
		int pos = 0;
		while(l<=r){
			ll mid = (l+r)/2;
			if(z - mid < c){
				pos = 1;
				r = mid - 1;
			}
			else l = mid  + 1;
		}
		// have the smallest possible x;

		ll l2=a,r2 = b;
		int pos2=0;
		while(l2<=r2){
			ll mid = (l2 +r2)/2;
			if(z-mid<b){
				pos2 = 1;
				r2  = mid-1;
			}
			else
				l2 = mid+1;
		}

		// have the smallest x for which all y are true;
		if(pos2){
			ans+= (b-l2+1)*(c-b+1);
		}
		// cout << ans << endl;
		if(pos){
			// for l we have atleast one solution.
			ll x = l;
			ll y = z-x+1;
			ll nosol = c-y+1; // for l 
			// for l2-1 we will have solutions in AP;
			ll n = l2-l;
			ll finsol  = nosol + n-1;
			ans+= finsol*(finsol+1)/2 - (nosol-1)*(nosol)/2;

		}
		// cout << z << " " << l2 << " " << l << endl;
		// cout << ans << endl;
	}
	cout << ans << endl;
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
