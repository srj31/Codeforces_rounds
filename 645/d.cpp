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
	long long int n,k;
	cin >> n >> k;
	long long int dm[n];
	ll td[n+1];
	td[0] = 0;
	ll maxihugs[n+1];
	maxihugs[0] = 0;
	for(ll i =0;i<n;i++){
		cin >> dm[i];
		td[i+1] = dm[i] + td[i];
		maxihugs[i+1] = maxihugs[i] + (dm[i]*(dm[i]+1))/2;
	}

	long long int ans = 0;
	for(ll i =1;i<2*n;i++){
		ll todays = 0;
		if(i>n){
			todays = td[n] + td[i-n];
		}
		else
			todays = td[i];
		if(todays<k)
			continue;
		ll l =1,r =i;
		while(l<=r){
			ll m = (l+r)/2;
			ll checkdays = 0;
			if((m-1)>n)
				checkdays = td[n] + td[m-1-n];
			else
				checkdays = td[m-1];

			if(todays-checkdays>=k){
				l = m+1;
			}
			else
			 r=m-1;
		}
		ll to_remove = todays;
		if(r-1>n){
			to_remove -= td[n] + td[r-1-n];
		}
		else{
			to_remove -= td[r-1];
		}
		to_remove-=k;
		to_remove = (to_remove)*(to_remove+1)/2;		
		ll hugies;
		if(i>n){
			hugies = maxihugs[n] + maxihugs[i-n];
		}
		else
			hugies = maxihugs[i];

		if(r-1>n)
			hugies -= maxihugs[n] + maxihugs[r-1-n];
		else
			hugies -= maxihugs[r-1];

		hugies-=to_remove;
		ans = max(ans,hugies);
		// cout << ans << " " << i << "  " << r <<" " << hugies << " " << to_remove << endl;
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
