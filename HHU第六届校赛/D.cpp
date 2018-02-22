#include<bits/stdc++.h>
using namespace std;

int cnt[5]={0};
int a[1000005];

int main(){
	int n ;
	while(~scanf("%d",&n)){
		memset(cnt,0,sizeof(cnt));
		int res = 0;
		bool flag =1;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);	
			cnt[a[i]]++;
		}
		if(cnt[1]>cnt[2]){
			cnt[1]-=cnt[2];
			res+=cnt[2];
			cnt[3]+=cnt[2];
			cnt[2]=0;
			int tem = cnt[1]/3;
			if(cnt[1]%3==2){
				res+=tem*2;
				cnt[1]-=tem*3;
				cnt[3]+=tem;
				if(cnt[3]>=2){
					res+=2;	
				}
				else if(cnt[4]>=1){
					res+=2;
				}
				else{
					flag = 0;
				}					
			}
			else if(cnt[1]%3==1){
				res+=tem*2;
				cnt[1]-=tem*3;
				cnt[3]+=tem;
				if(cnt[3]>=1){
					res+=1;	
				}
				else if(cnt[4]>=2){
					res+=2;	
				}
				else{
					flag = 0;
				}
			}
			else{
				res+=tem*2;
			}
		}
		else if(cnt[1]<cnt[2]){
			cnt[2]-=cnt[1];
			res+=cnt[1];
			cnt[3]+=cnt[1];
			cnt[1]=0;
			int tem = cnt[2]*2/3;
			if(cnt[2]*2%3==1){
				res+=tem;
				cnt[2]-=((tem+1)/2);
				cnt[3]+=tem;
				if(cnt[3]>=1){
					res+=1;	
				}
				else if(cnt[4]>=1){
					res+=1;	
				}
				else{
					flag = 0;
				}		
			}
			else if(cnt[2]*2%3==2){
				res+=tem;
				cnt[2]-=((tem+1)/2);
				cnt[3]+=tem;
				if(cnt[4]>=1){
					res+=1;	
				}
				else if(cnt[3]>=2){
					res+=2;	
				}
				else{
					flag = 0;
				}				
			}
			else{
				res+=tem;					
			}
		}
		else{
			res+=cnt[1];			
		}
		if(flag)printf("%d\n",res);
		else printf("-1\n");
	}
	return 0;
}
