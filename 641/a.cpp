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


const int modi = 1e9 + 7;
const int INF = 1e9;
const int mxN = 1e6;


// vector<int> primes(mxN+1,1); 
void solve(){
	long long int n,k;
	cin >> n >> k;
	long long int ans = 0;
	if(n&1){
		k--;
		int pr = 0;
		for(int i =3;i*i<=n;i++){
			if(n%i==0){
				pr = i;break;
			}
		}
		if(pr==0)
			pr = n;
		ans = n + pr;

		ans += (k)*2;
	}
	else{
		ans = n;
		ans+=2*k;
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
