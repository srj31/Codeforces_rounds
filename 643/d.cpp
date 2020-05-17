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
	int n,s;
	cin >> n >> s;
	if(n==1){
		if(s!=1){
			cout << "YES" << endl;
			cout << s << endl;
			cout << s-1 << endl;
		}
		else{
			cout << "NO" << endl;
		}
		return;
	}

	vector<int> ans(n);
	for(int i =0;i<n-1;i++){
		ans[i] = 1;
		s-=1;
	}
	ans[n-1] = s;
	if(n-1>=s-1){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		for(auto e: ans){
			cout << e << " ";
		}
		cout << endl;
		cout << s-1 << endl;
	}

}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// int t;cin >> t;while(t--)
		solve();
}
