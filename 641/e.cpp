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

const int mxn = 1e3+1;
vector<string> adj(mxn);
long long int vis[mxn][mxn],dep[mxn][mxn];
int n,m;
set<pair<int,int> > ch;
int dx[4] = {-1,0,0,1}, dy[4] = {0,1,-1,0};

bool pos(int i, int j){
	if(i<0 || i >=n) return false;

	if(j<0 || j>=m) return false;

	return true;
}

void dfs(int i, int j){
	vis[i][j] = 1;
	for(int x= 0;x<4;x++){
		int nx = i + dx[x];
		int ny = j + dy[x];
		if(pos(nx,ny)){
			if(!vis[nx][ny]){
				if(adj[i][j]==adj[nx][ny]){
					dep[i][j] = 0;
					dep[nx][ny] = 0;
					dfs(nx,ny);
					ch.insert(make_pair(i,j));
					ch.insert(make_pair(nx,ny));
				}
			}
		}
	}

}

void solve(){
	int t;
	cin >> n >> m >> t;
	for(int i =0;i<n;i++){
		cin >> adj[i];
	}	
	memset(dep,0x3f,sizeof(dep));
	int cnt = 0; // to see if there were any changes in the first day
	for(int i =0;i<n;i++){
		forn(j,0,m){
			if(!vis[i][j]){
				dfs(i,j);
				cnt++;
			}
		}
	}

	// now could start bfs and assign the right depths
	set<pair<int, pair<int,int > > >points;
	for(auto e: ch){
		points.insert(make_pair(0,e));
	}

	while(!points.empty()){
		// cerr << 'i' << endl;
		pair<int,pair<int,int > > pt = *points.begin();
		points.erase(points.begin());
		int x = pt.second.first,y = pt.second.second;
		int d = pt.first;
		// cout << d << " " << x  << " " << y << endl;
		// cerr << x << " " << y << endl;
		for(int i =0;i<4;i++){
			int nx= x+dx[i],ny = y+dy[i];
			if(pos(nx,ny)){
				if(dep[nx][ny]>1+d){
					// cout << "here" << endl;
					points.insert(make_pair(d+1,make_pair(nx,ny)));
					dep[nx][ny] = 1 +d;
				}
			}
		}
	}
	// cout << 1 << endl;
	while(t--){
		ll x, y ,p;
		cin >> x >> y >> p;
		--x,--y;
		ll changes = dep[x][y];
		p-=changes;
		cerr << p << endl;
		if(p<=0){
			cout << adj[x][y] << endl;
		}
		else{
			char ch = adj[x][y];
			if(p%2)
				ch = ch ^'0' ^ '1';
			cout << char(ch) << endl;
		}
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
