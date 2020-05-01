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
	int n,k;
	cin >> n >> k;
	set<int>dis;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
		dis.insert(a[i]);
	}
	if(dis.size()>k){
		cout << -1 << endl;return;
	}
	vector<int> ans;
	vector<int>tofill;
	for(int i =1;i<=n;i++){
		if(dis.size()==k)break;
		if(dis.find(i)==dis.end()){
			dis.insert(i);
		}
	}
	for(auto e:dis){
		tofill.pb(e);
	}
	int curr = 0;
	int total = k;
	for(int i =0;i<n;i++){
		if(a[i]!=tofill[curr]){
			while(a[i]!=tofill[curr]){
				ans.pb(tofill[curr]);
				curr = (curr+1)%total;
			}
			

		}
		ans.pb(a[i]);
		curr = (curr+1)%total;
	}
	cout << ans.size() << endl;
	for(auto e:ans){
		cout << e << " ";
	}cout << endl;

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