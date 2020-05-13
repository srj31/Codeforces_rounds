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
	int n;
	cin >> n;
	int a[n];
	int moda[n];//how much each place will be changed by
	int flag = 1;
	vector<vector<int> > adj(n); // storing the in edges
	int check = -1;
	for(int i =0;i<n;i++){
		cin >> a[i];
		if(a[i]<0){
			a[i]+= ((-1*a[i]/n)+1)*n;
		}

		moda[i] = a[i]%n;
		// cout << (i+moda[i])%n << " " << i << endl;
		adj[(i+moda[i])%n].pb(i);
	}
	//all moda need to be same or else no
	for(int i =0;i<n;i++){
		if(adj[i].size()!=1){
			flag = 0;break;
		}
	}
	cout << (flag?"YES":"NO") << endl;
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