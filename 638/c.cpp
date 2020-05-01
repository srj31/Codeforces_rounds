#include<bits/stdc++.h>
#include<unordered_map>
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
	string s;
	cin >> s;
	unordered_map<int,int> c;
	int fc = 25;
	int lc = 0;
	for(int i =0;i<n;i++){
		c[s[i]-'a']++;fc=min(fc,s[i]-'a');
		lc=max(lc,s[i]-'a');
	}
	string ans1="",ansk="";
	if(lc==fc){
		//spread all of it;
		int amount = (c[lc]+k-1)/k;
		while(amount--){
			ansk+=char(lc+'a');
		}
	}
	else{//they are different
		int fck=fc;
		int cfreq= 0;
		for(int i =fc;i<=lc;i++){
			while(c[i]>0&&cfreq<k){
				c[i]--;
				cfreq++;
				
			}
			if(cfreq==k){
					fck = i;
					ansk+=char(fck+'a');
					break;
			}
			
		}
		// cout << char(fck+'a') << endl;
		if(fck==fc){
			int nc=fc;
			while(c[nc]<=0){
				nc++;
			}
			// cout << nc << endl;
			if(nc==lc){
				int amount=(c[nc]+k-1)/k;
				while(amount--){
					ansk+=char(nc+'a');
				}
			}
			else{
				//add everything else
				for(int i =nc;i<=lc;i++){
					int times = c[i];
					while(times>0){
						ansk+=char(i+'a');
						times--;
					}
				}
			}
			cout << ansk << endl;return;
		}
		else{
			cout<< char(fck+'a') << endl;return;
		}
		// for(int i=fck;i<=lc;i++){
		// 	if(c[i]>0){
		// 		while(c[i]>0){
		// 			ansk+=char(i+'a');
		// 			c[i]--;
		// 		}
		// 	}
		// }

	}
	cout << ansk << endl;
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