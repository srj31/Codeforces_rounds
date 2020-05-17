#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		//for every number divisble  by n there are n-1 numbers before;
		int group = k/(n-1);
		int more = k%(n-1);

		int ans = n*group;
		k-=ans;
		ans+=more;
		if(more==0)
			ans--;
		cout << ans << endl;
	}

}