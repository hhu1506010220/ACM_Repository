#include<bits/stdc++.h>
using namespace std;

int a[100000];

int main(){
	int temp,ans,cnt=0,cnt1=0,cnt0=0;
	bool flag = 1; 
	for(int i=1;i<=100000;i++){
		cnt0=0,cnt1=0;
		flag = 1;
		bool flagg = 1;
		temp = i;
		while(temp){
			ans = temp%2;
			if(ans){
				flag=0;
				cnt1++;
			}
			if(!ans&&flag){
				cnt0++;
			}
			if(!ans&&!flag){
				flagg = 0;
				break;	
			}
			temp/=2;
		}
//		if(i==6)cout<<cnt0<<" "<<cnt1<<endl;
		if(flagg&&cnt1==cnt0+1)
			a[cnt++]=i;
	}
//	for(int i=0;i<cnt;i++)cout<<a[i]<<endl;
	int n;
	scanf("%d",&n);
	flag =1;
	for(int i = n;i>=1;i--){
		for(int j = cnt-1;j>=0;j--){
			if(i%a[j]==0){
				printf("%d\n",a[j]);
				flag=0;
				break;	
			}
		}
		if(!flag)break;
	}
	return 0;	
}
