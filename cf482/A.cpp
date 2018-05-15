#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin>>n;
	if(n==0){
		cout<<0<<endl;
		return 0;	
	}
	n++;
	long long cnt = 0;
	if(n%2==0)
		cnt = n/2;
	else{
		cnt = n;
	}	
	cout<<cnt<<endl;	

	return 0;
}
