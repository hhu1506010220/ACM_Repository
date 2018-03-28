#include<bits/stdc++.h>
using namespace std;

int a[100];

int main(){
	int coun = 0;
	for(int i=1;i<=100000;i++){
		memset(a,0,sizeof(a));
		int t = i;
		int cnt =0;
		while(t){
			a[cnt++]=t%10;
			t/=10;
		}
//		for(int j=0;j<cnt;j++)
//			cout<<a[j]<<" ";
//		cout<<endl;
		int minn = 10;
		int tem = -1;
		for(int j=cnt-1;j>=0;j--){
			if(a[j]<minn){
				tem = j;
				minn = a[j];	
			}
		}
//		cout<<i<<" "<<minn<<" "<<tem<<endl;
		bool flag1=1,flag2=1;
		for(int j=cnt-2;j>=tem;j--){
			if(a[j]>=a[j+1]){
				flag1 = 0;
				break;
			}
		}
		for(int j=0;j<tem;j++){
			if(a[j]<=a[j+1]){
				flag2 = 0;
				break;
			}
		}	
		if(flag1&&flag2&&tem!=cnt-1&&tem!=0){
			coun++;
//			cout<<i<<endl;
		}
	}
	cout<<coun<<endl;
	return 0;	
}
