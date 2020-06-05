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

	ll a,b;
	cin >> a >> b;
	if(a==b){
		cout << 0 << endl;return;
	}
	ll ans = 0;
	if(a>b)
		swap(a,b);
	if(b%a!=0)
		cout << -1 << endl;
	else{
		ll d = b/a;
		if(d%2!=0){
			cout << - 1 << endl;return;
		}

		if(d%8==0){
			while(d%8==0){
				ans++;
				d/=8;
			}
		}

		if(d%4==0){
			while(d%4==0){
				ans++;
				d/=4;
			}
		}

		if(d%2==0){
			while(d%2==0){
				ans++;
				d/=2;
			}
		}
		if(d!=1){
			cout << -1 << endl;return;
		}
		cout << ans << endl;
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
