#include<bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
	int n;
	cin>>n;
	int tem;
	memset(a,0,sizeof(a));
	while(n--){
		cin>>tem;	
		a[tem]++;
		if(n!=0)
			cout<<a[tem]<<" ";
		else
			cout<<a[tem]<<endl;
	}
	return 0;
}
