#include<bits/stdc++.h>
using namespace std;

int main(){
	int max1,max2;
	int t1=0,t2=0;
	cin>>max1>>max2;
	int n;
	int a1,a2,a3,a4;
	cin>>n;
	while(n--){
		cin>>a1>>a2>>a3>>a4;
		int sum = a1 + a3;
		if(a2==sum&&a4!=sum)
			max1--,t1++;
		if(a4==sum&&a2!=sum)
			max2--,t2++;
		if(max1==-1&&max2==-1){
			max1 = max2 = 0;	
		}
		if(max1==-1){
			cout<<"A"<<endl;
			cout<< t2<<endl;
			break;	
		}
		if(max2==-1){
			cout<<"B"<<endl;
			cout<<t1<<endl;
			break;	
		}
	}
	return 0;	
}
