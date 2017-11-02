#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int cnt=0;
	for(int i=max(0,n-1000000);i<min(1000000000,n+1000000);i++){
		int tem = i;
		int ii = i;
		while(ii>0){
			tem+=(ii%10);
			ii/=10;
		}
//		cout<<tem<<" "<<i<<endl;
//		if(tem == i)cout<<i<<endl;	
		if(tem==n)cnt++;	
	}
	cout<<cnt<<endl;
	for(int i=max(0,n-1000000);i<min(1000000000,n+1000000);i++){
		int tem = i;
		int ii = i;
		while(ii>0){
			tem+=(ii%10);
			ii/=10;
		}
//		cout<<tem<<" "<<i<<endl;
//		if(tem == i)cout<<i<<endl;	
		if(tem==n)cout<<i<<endl;	
	}
	return 0;
}
