#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[8],b[8],sum[8];
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=7;i++)
			scanf("%d%d",&a[i],&b[i]);
		int maxn = 0;
		for(int i=1;i<=7;i++){
			maxn = max(maxn,a[i]+b[i]);	
		}
		if(maxn<=8)puts("0");
		else{
			for(int i=1;i<=7;i++){
				if(a[i]+b[i]==maxn){
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;	
}
