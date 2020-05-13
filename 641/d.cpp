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
	int a[n];
	int pos = 0;
	forn(i,0,n){
		cin >> a[i];
		if(a[i]==k)
			pos = 1;
	}
	if(!pos){
		cout << "no" << endl;return;
	}
	if(n==1){
		cout << "yes" << endl;return;
	}
	pos = 0;
	forn(i,0,n-1){
		if(a[i]>=k && a[i+1]>=k)
			pos = 1;
	}
	for(int i =1;i<n-1;i++){
		int c = 0;
		for(int j =-1;j<2;j++){
			if(a[i+j]>=k)
				c++;
		}
		if(c>=2)
		{
			pos = 1;break;
		}
	}

	cout << (pos?"yes":"no") << endl;


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
