#include<bits/stdc++.h>
using namespace std;

int a[1000005]; 

int main(){
	int n;
	cin>>n;
	a[0] = 5;
	a[1] = 11;
	if(n>=0){
		cout<<"5"<<endl;	
	}
	else{
		for(int i=2;i<=-n;i++){
			a[i] = a[i-1]+a[i-2]+1;
		}
		cout<<a[-n]<<endl;
	}
	
	return 0;	
}
