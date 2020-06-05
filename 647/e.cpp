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

const ll modi = 1e9+7;

ll binpow(ll a,ll b){
	ll res = 1;
	while(b>0){
		if(b&1){
			res = res*a%modi;
		}
		a= a*a%modi;
		b>>=1;
	}
	return res;
}

void solve(){
	ll n,p;
	cin >> n >> p;
	
	ll k[n];
	for(ll i =0;i<n;i++)
		cin >> k[i];
	if(p==1){
		cout << (n%2?1:0) << endl;return;
	}	
	sort(k,k+n,greater<ll>());
	// for(int i =0;i<n;i++)
	// 	cout << k[i] << " ";
	// cout << endl;
	string s,s0;
	for(ll i =0;i<k[0];i++){
		s+='0';
		s0+='0';
	}
	s = s+'1';
	s0+='0';
	ll bigie = k[0];
	// cout << s << endl;
	for(ll i =1;i<n;i++){
		if(k[i]>bigie){
			// then need to add to s;
			s[k[i]] = '1';
			bigie = k[i];
		}
		else if(k[i]==bigie){
			s = s0;
			bigie = 0;
		}
		else{
			// sub from it
			// cout << "before" << i << endl;
			// cout << s << endl;
			if(s[k[i]]!='0')
				s[k[i]]--;
			else{
				s[k[i]]='0'+p-1;
				for(ll j =k[i]+1;j<=bigie;j++){
					if(s[j]=='0')
						s[j] = '1'+p-1;
					else{
						s[j]--;
						if(j==bigie){
							bigie--;
							// break;
						}
						break;
					}
				}
			}
			// cout << "After" << i << endl;
			// cout << s << endl;
		}
	}
	// cout << s << endl;
	ll ans = 0;
	for(ll i =0;i<s.length();i++){
		if(s[i]=='1'){
			// cout << i << endl;
			// cout << p << " " <<  binpow(p,i) << endl;
			ans = (ans+binpow(p,i))%modi;
			// cout << ans << endl;
		}
		// cout << ans << " i " << i << endl;
	}
	cout << ans << endl;
	// cout << s << endl;
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
