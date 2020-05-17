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

	string s;
	cin >> s;
	int cnt[4];
	memset(cnt,0,sizeof(cnt));
	vector<vector<int> > pos(4);
	int n = s.length();
	for(int i =0;i<n;i++){
		cnt[s[i]-'0']++;
		pos[s[i]-'0'].pb(i);
	}
	if((cnt[1]==0 )|| (cnt[2]==0) || (cnt[3]==0) )
	{
		cout <<  0 << endl;return;
	}
	int mini = n+1;
	for(int i =0;i<n-2;i++){
		if(lower_bound(pos[1].begin(),pos[1].end(),i)!=pos[1].end()){
			if(lower_bound(pos[2].begin(),pos[2].end(),i)!=pos[2].end() && lower_bound(pos[3].begin(),pos[3].end(),i)!=pos[3].end()){
			int pos1 = *lower_bound(pos[1].begin(),pos[1].end(),i);
			int pos2 = *lower_bound(pos[2].begin(),pos[2].end(),i);
			int pos3 = *lower_bound(pos[3].begin(),pos[3].end(),i);
			mini = min(mini,max(pos1,max(pos2,pos3))-i + 1);
			}
		}
		
		// mini = min(mini,max(pos1,max(pos2,pos3))-i);
	}
	// cout << cnt[1] << " " << cnt[2] << cnt[3] << endl;
	// 
	if((cnt[1]==0 )|| (cnt[2]==0) || (cnt[3]==0) )
	{
		mini = 0;
	}
	cout << mini << endl;

}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w",stdout);
	#endif

	int t;cin >> t;while(t--)
		solve();
}
