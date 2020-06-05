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
// limits are 2^10;

void solve(){
	int n;
	cin >> n;
	int a[n];
	set<int> s;
	int maxi = 0;
	forn(i,0,n){
		cin >> a[i];
		maxi= max(maxi,a[i]);
		s.insert(a[i]);
	}

	for(int i =1;i<=(1<<11);i++){
		set<int> s2;
		for(int j =0;j<n;j++){
			s2.insert(a[j]^i);
		}

		if(s2==s){
			cout << i << endl;return;
		}
	}

	cout << -1 << endl;

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
