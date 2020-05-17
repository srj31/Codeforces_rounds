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

double polyapothem(double n, double a)
{
 
	double pi=acos(-1);
	// Side and side length cannot be negative
	if (a < 0 && n < 0)
		return -1;
 
	// Degree converted to radians
	return a / (2 * tan((180 / n) * pi / 180));
}
 

void solve(){
	int n;
	cin >> n;
	cout << fixed << setprecision(15) << 2*polyapothem(2*n,1) << " his " << endl;
	double s = 1.0/tan(PI/(2.0*n));
	cout << fixed << setprecision(9) << s << endl;
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w",stdout);
	#endif

	int t;cin >> t;while(t--){
		solve();
	}
}
