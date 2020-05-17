#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;
#define PI 3.14159265


typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


void solve(){
	int n;
	cin >> n;
	double s = 0.5/tan(PI/(2.0*n));
	s*=sqrt(2);
	s+=1.0/sqrt(2);
	cout << fixed << setprecision(9) << s << endl;
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
