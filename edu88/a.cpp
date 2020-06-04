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
	int n,m,k;
	cin >> n >> m >> k;
	int each = n/k;
	int ans = 0;
	if(each>=m)
		ans = m;
	else{
		if(m==each){
			ans = 0;
		}
		else{
			// max a player gets is each
			ans = each;
			// divide the rest of the jokers equally
			ans-= ceil((m-each)*1.0/(k-1));
		}
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
