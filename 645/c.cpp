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
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int dx = x2-x1;
	int dy = y2-y1;
	// ans  = (dx + dy)!/(dx)!(dy)!
	long long int n = min(dx,dy);
	long long int ans = n*(n+1)*(n+2)/6 + ;
	ans++;
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
