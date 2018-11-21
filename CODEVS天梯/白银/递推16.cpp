#include<bits/stdc++.h>
using namespace std;

void hanota(int n,char l,char m, char r){
	if(n==1){
		cout<<n<<" from "<<l<<" to "<<r<<endl;
	}
	else{
		hanota(n-1,l,r,m);
		cout<<n<<" from "<<l<<" to "<<r<<endl;
		hanota(n-1,m,l,r);	
	}
}

int main(){
	int n;
	cin>>n;
	cout<<pow(2,n)-1<<endl;
	hanota(n,'A','B','C');
	return 0;	
}
