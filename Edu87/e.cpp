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
	int base = 1;
	while(base<=n)
		base*=2;

	vector<int> t(2*base);//count of value in this range
	for(int i =0;i<n;i++){
		int a;
		cin >> a;
		for(int j = a+base;j>=1;j/=2){
			t[j]++;
		}
	}
	while(k--){
		int b;
		cin >> b;
		if(b>0){
			for(int i = b+base;i>=1;i/=2)
				t[i]++;
		}
		else{
			int find = b*-1;
			int start = 1;
			int l = 0;int r = base+1;

			while(l<r){
				// cout << start << "  - "<< l << " " << r<< " "<< find << endl;			
				// cout << t[start] << endl;
				if(start>base) break;
				if(t[2*start]>=find){
					
					r = (l+r)/2;
					start*=2;
				}
				else{
					l = (l+r)/2;
					find-=t[2*start];
					start = start*2 + 1;
				}

			}
			// cout << l+1 << endl;
			for(int i = l+base;i>=1;i/=2){
				t[i]--;
			}

		}
	}
	if(t[1]<=0){
		cout << 0 << endl;
	}
	else{
		for(int i = 1+base;i<=n+base;i++){
			if(t[i]>0){
				cout << i-base << endl;
				return;
			}
		}
	}
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
	#endif

	// int t;cin >> t;while(t--)
		solve();
}
