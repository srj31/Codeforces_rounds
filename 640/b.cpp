#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		if(n%2==1 && k%2==0)
			cout << "NO" << endl;
		else{
			if(n%2==1){
				if(n<k)
					cout << "NO" << endl;
				else{
					// n is odd and k is odd -> the parity of the integers has to be odd
					cout << "YES" << endl;
					while(k>1){
						cout << 1 << " ";
						k--;
						n--;
					}
					cout << n << endl;

				}
			}
			else{
				if(n<2*k){
					// then k has to be even 
					if(k%2 || n<k)
						cout << "NO" << endl;
					else{
						cout << "YES" << endl;
						while(k>1){
							cout << 1 << " ";
							k--;n--;
						}
						cout << n << endl;
					}
				}
				else{
					cout << "YES" << endl;
					while(k>1){
						cout << 2 << " ";
						k--;n-=2;
					}
					cout << n << endl;
				}
			}
		}
	}
}