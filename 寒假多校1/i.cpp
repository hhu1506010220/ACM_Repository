#include<bits/stdc++.h>
using namespace std ;

int aa[11],bb[10]; 

int main(){
	int t;
	int a,b;
	int tem ,cnt ,temp;
	bool flag =1 ;
	scanf("%d",&t);
	while(t--){
		cnt = 0;
		memset(aa,0,sizeof(aa));
		scanf("%d%d",&a,&b);
		tem=a;
		while(tem){
			aa[tem%10]=1;
			tem/=10;	
		}
		tem=b;
		while(tem){
			aa[tem%10]=1;
			tem/=10;	
		}
		for(int i=1;i<=1000;i++){
			flag = 1;
			if(i%a==0||i%b==0)
				continue;
			temp = i;
			memset(bb,0,sizeof(bb));
			while(temp){
				bb[temp%10]=1;
				temp/=10;	
			}
			for(int i=0;i<10;i++){
				if(aa[i]==bb[i]&&aa[i]){
					flag = 0;
					break;
				}
			}
			if(flag)cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
