#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;


long long int gcd(long long int a,long long int b) {
	return (b?gcd(b,a%b):a);
}


typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e5;

void solve(){
	long long int n;
	cin >> n;
	long long int a[n];
	forn(i,0,n) cin >> a[i];

	if(n==2){
		cout << a[0]*a[1]/gcd(a[0],a[1]) << endl;
		return ;
	}
	map<long long int,long long int> countp;
	map<long long int,pair<long long int,long long int > > maxip;
	for(long long int j =0;j<n;j++){
		long long int val = a[j];
		for(long long int i =2;i*i<=val;i++){
			long long int count = 0;
			// if(i==2)
			// 	cout << val << endl;
			if(val%i==0){
				while(val%i==0){
					count++;
					val/=i;
				}
				countp[i]++;
				if(maxip.find(i)!=maxip.end()){
					if(count<maxip[i].first){
						maxip[i].se = maxip[i].fi;
						maxip[i].first = count;
					}
					else if(count < maxip[i].se)
						maxip[i].se = count;
				}
				else{
					maxip[i].fi = count;
					maxip[i].se = inf;
				}
			}

			// if(i==2){
			// 	cout << count << " " << countp[i] << endl;
			// }
		}
		if(val>1){
			long long int i = val;
			long long int count = 1;
			countp[val]++;
			if(maxip.find(i)!=maxip.end()){
					if(count<maxip[i].first){
						maxip[i].se = maxip[i].fi;
						maxip[i].first = count;
					}
					else if(count < maxip[i].se)
						maxip[i].se = count;
				}
				else{
					maxip[i].fi = count;
					maxip[i].se = inf;
				}
		}
	}

	long long int ans = 1;
	for(auto e: countp){
		if(e.second>n-1){
			
			ans*=pow(e.first,maxip[e.first].second);
			
		}
		else if(e.second == n-1){
			ans*=pow(e.first,maxip[e.first].fi);
		}
	}
	cout << ans << endl;
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
