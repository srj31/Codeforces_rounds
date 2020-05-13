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

const int mod = 1e9;
const int INF = 1e9;
const int mxN = 1e5;

void solve(){
	
	int n,m;
	cin >> n >> m;
	if(n==1 || m == 1){
		cout << "YES" << endl;return;
	}

	if(n==2 && m == 2){
		cout << "YES" << endl;return;
	}
	

	cout << "NO" << endl;return;
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