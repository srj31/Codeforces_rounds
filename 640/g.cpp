#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n<=3){
			cout << - 1 << endl;
		}
		else{
			int start = 2;
			if(n%2)start = 1;

			while(start<n){
				cout << start << " ";
				start+=2;
			}
			cout << n << " ";
			cout << n-3 << " ";
			cout << n-1 << " ";
			start = n-5;
			if(n>4){
				while(start>0){
					cout << start << " ";
					start-=2;
				}
			
			}
			cout << endl;
		}

	}
}