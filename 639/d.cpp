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

vector<string> g; 
int vis[1001][1001];
int n,m;

bool pos(int i ,int j){
	if(i<0 || i>=n) return false;

	if(j<0 || j>=m) return false;

	if(g[i][j]!='#') return false;
	return true;
}
pair<int,int> moves[4] = {make_pair(-1,0),mp(1,0),mp(0,1),mp(0,-1)};
void dfs(int i,int j){
	vis[i][j] = 1;
	for(auto e:moves){
		int x,y;
		x= e.first;y=e.second;
		if(pos(i+x,j+y)){
			if(!vis[i+x][j+y])
				dfs(i+x,j+y);
		}
	}
}

void solve(){
	// int n,m;
	cin >> n >> m;
	g = vector<string> (n);
	int empty = 1;
	string em = "";
	for(int i =0;i<m;i++){
		em+='.';
	}
	for(int i =0;i<n;i++){
		cin >> g[i];
		if(g[i]!=em)
			empty = 0;
	}
	if(empty){
		cout << 0 << endl;
		return;
	}

	for(int i =0;i<n;i++){
		int row = 0;
		for(int j =0;j<m;j++){
			if(g[i][j]=='#'){
				row = 1;
			}
		}
		if(row == 0){
				// cout << 5 << endl;

			cout << -1 << endl;return;
		}	
	}

	for(int j = 0;j<m;j++){
		int col = 0;
		for(int i =0;i<n;i++){
			if(g[i][j]=='#')
				col = 1;
		}
		if(col == 0){
				// cout << 4 << endl;

			cout << -1 << endl;return;
		}
	}
	//check if continuous r
	for(int i =0;i<n;i++){
		int isblack = -1;
		for(int j =0;j<m;j++){
			if(isblack ==0 && g[i][j]=='#'){
				// cout << i << " " << j << endl;
				// cout << 3 << endl;

				cout << -1 << endl;return;
			}
			if(g[i][j]=='#'){
				isblack = 1;
			}
			else{
				if(isblack==1)isblack = 0;
			}
		}
			
	}

	for(int j = 0;j<m;j++){
		// int col = 0;
		int isb = -1;
		for(int i =0;i<n;i++){
			if(isb==0 && g[i][j]=='#'){
				// cout << 2 << endl;
				cout << -1 << endl;return;
			}
			if(g[i][j]=='#'){
				isb = 1;
			}
			else{
				if(isb==1) isb = 0;
			}
		}
		
	}
	int count = 0;
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if(!vis[i][j] && g[i][j]=='#'){
				// cout << i << " " << j << endl;
				dfs(i,j);
				count++;
			}
		}
	}
	// cout << 1 << endl;
	cout << count << endl;

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