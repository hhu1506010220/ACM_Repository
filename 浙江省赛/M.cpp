#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,k;
	scanf("%d",&t);
	int x;
	while(t--){
		scanf("%d%d",&n,&k);
		k %= 7 ;
		int flag = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(!flag){
				if((x+k)%7==0){
					flag = 1;
				}		
			}
		} 
		if(flag){
			printf("Yes\n");
		}else{
			printf("No\n");
		} 
	} 
	return 0;
} 
