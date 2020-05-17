#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i =0;i<n;i++){
			cin >> a[i];
		}
		int turn = 0;
		int count = 0;
		int ans[2];
		ans[1] = ans[0] = 0;
		int curr[2];
		curr[0] = curr[1] = 0;
		int start=0,end=n-1;
		while(true){
			count++;
			if(!turn){
				while(start<=end && curr[0]<=curr[1]){
					curr[0]+=a[start];
					start++;
				}
				ans[0]+=curr[0];
				if(start>end){
					break;
				}
			}
			else{
				while(start<=end && curr[1]<=curr[0]){
					curr[1]+=a[end];
					end--;
				}
				ans[1]+=curr[1];
				if(start>end)
					break;
			}
			turn^=1;
			curr[turn] = 0;
		}

		cout << count << " " << ans[0] << " " << ans[1] << endl;

	}
}