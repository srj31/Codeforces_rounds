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
	int n,x;
	cin >> n >> x;
	int cnt[2];
	int a[n];
	memset(cnt,0,sizeof(cnt));
	for(int i =0;i<n;i++){
		cin >> a[i];
		cnt[a[i]%2]++;
	}
	if(cnt[1]==0){
		cout <<"No" << endl;return;
	}
	if(cnt[1]%2==0)
		cnt[1]--;

	if(cnt[1]+cnt[0] >= x){
		if(x%2==0){
			if(cnt[0]>0){
				cout << "Yes" << endl;return;
			}
			else{
				cout << "No" << endl;return;
			}

		}
		else{
			cout << "Yes" << endl;return;
		}
	}
	cout << "No" << endl;

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
