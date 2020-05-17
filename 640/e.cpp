#include<bits/stdc++.h>
using namespace std;
const int mxn = 8e3+1;
const int INF = 8e6 + 5;


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i =0;i<n;i++)
			cin >> a[i];
		int pref[n+1];
		memset(pref,0,sizeof(pref));
		// memset(pos,0,sizeof(pos));
		pref[0] = 0;
		for(int i =1;i<=n;i++){
			pref[i] = pref[i-1]+a[i-1];
		}
		int pos[n+1];
		memset(pos,0,sizeof(pos));
		for(int i =1;i<=n;i++){
			for(int j = i-1;j>=1;j--){
				int sum = pref[i] - pref[j-1];
				if(sum<=n)
					pos[sum]= 1;
			}
		}
		int count = 0;
		for(int i =0;i<n;i++){
			
			if(pos[a[i]]) count++;
		}
		cout << count << endl;
	}
}