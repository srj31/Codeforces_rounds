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
	long double h,c,t;
	cin >> h >> c >> t;
	long double diff;
	diff = abs((t) - ((h+c)/2.0));
	long long int ans = 2;
	if(abs(t-h)<diff){
		ans = 1;
		diff= abs(t-h);
	}
	// cout << ans << endl;
	// cout << ans << endl;
	long long int l = 2;long long int r = 1e15;
	while(l<=r){
		long long int m = l+(r-l)/2;
		long double temp =1.0* m*h + (m-1)*c; 
		temp/=(2*m-1);
		if(temp-t<0)
				r = m-1;
		else
				l = m+1;
		// else{
		// 	ans = 2*m-1;
		// 	// cout << ans << endl;
		// 	// return;
		// }

	}
	r-=2;
	if(r<0) r= 2;
	long double temp1 = 1.0*l*h+1.0*(l-1)*c;
	temp1/=(2*l-1);
	long double temp2  = 1.0*r*h+1.0*(r-1)*c;
	temp2/=(2*r-1);
	if(abs(temp1-t)<diff)
	{
		diff = abs(temp1-t);
		ans = 2*l-1;
	}
	else if(abs(temp1-t)==diff)
		ans = min(ans , 2*l-1);
	if(abs(temp2-t)<diff){
		ans = 2*r - 1;
	}
	else if(abs(temp2-t)==diff)
		ans = min(ans,2*l-1);

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
