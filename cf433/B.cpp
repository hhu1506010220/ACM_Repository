#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,k;
	while(cin>>n>>k){
		int s = n-k;
		if(k==0)cout<<"0 0"<<endl;
		else if(k==n){
			cout<<"0 0"<<endl;	
		}
		else if(k*2<=s){
			cout<<"1 "<<k*2<<endl;	
		}
		else if(s>=k+1){
			cout<<"1 "<<s<<endl;	
		}
		else{
			cout<<"1 "<<s<<endl;
		}
		
	}
	return 0;	
}
