#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;


typedef int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct node{
	// ll maxiwhole,maxipref,maxisuff;
	ll sum,pref,suff,ans;
};

node make_node(ll val) {
    node res;
    res.sum = val;
    res.pref = res.suff = res.ans = val;
    return res;
}
const int mxn = 1e5+10;
node tree[4*mxn];
// struct data {
//     int sum, pref, suff, ans;
// };

node combine(node l, node r) {
    node res;
    res.sum = l.sum + r.sum;
    // res.sum = max(res.sum,max(l.sum,r.sum));
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

void build(vector<ll>& a,ll v, ll tl, ll tr){
	if(tl==tr){
		tree[v] = make_node(a[tl]); return;
	}
	ll m = (tl+tr)/2;
	build(a,2*v, tl , m);
	build(a,2*v+1,m+1,tr);
	tree[v] = combine(tree[2*v],tree[2*v+1]);
}

node query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return make_node(0);
    if (l == tl && r == tr) 
        return tree[v];
    ll tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

// node query(ll v, ll tl, int tr, int l , int r){

// 	if(l>r)
// 		return make_node(INT_MIN);
// 	if(tl>=l && tr<=r)
// 		return tree[v];

// 	int m = (tl+tr)/2;
// 	return combine(query(2*v,tl,tm,l,r) , query(2*v+1,tm+1,tr,l,r));

	
// }

void solve(){
	ll n;
	cin >> n;
	// cin >> n;
	vector<ll> a(n);
	// ll pref[n+1],suff[n+1];
	for(ll i =0;i<n;i++)
		cin >> a[i];
	build(a,1,0,n-1);
	ll prefimax[n+1];
	ll suffimax[n+1];
	stack<pair<ll,ll > > s;
	// s.push(mp(a[0],0));
	for(ll i =0;i<n;i++){
		if(!s.empty()){
			while(!s.empty() && s.top().first<=a[i])
				s.pop();
		}

		if(!s.empty())
			prefimax[i] = s.top().second;
		else
			prefimax[i] = -1; // means this the max in the whole left
		s.push(mp(a[i],i));
	}

	while(!s.empty())
		s.pop();


	for(ll i =n-1;~i;--i){
		if(!s.empty()){
			while(!s.empty() && s.top().first<=a[i])
				s.pop();
		}

		if(!s.empty())
			suffimax[i] = s.top().second;
		else
			suffimax[i] = n; // means this the max in the whole left
		s.push(mp(a[i],i));
	}
	ll ans = 0;
	for(ll i =0;i<n;i++){
		ll r = suffimax[i];
		ll l = prefimax[i];
		// cout << r << " " << l << endl;
		node n1 = query(1,0,n-1,l+1,i-1);
		node n2 = query(1,0,n-1,i+1,r-1);
		// cout << n1.suff << " " << n2.pref << " " << a[i] << endl;
		ans = max(ans,n1.suff + n2.pref);
		// cout << ans << endl;
	}	
	cout << ans << endl;

}

int main(){
	fast;
	cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// int t;cin >> t;while(t--)
		solve();
}
