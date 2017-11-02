#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	int cnn=1;
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		printf("Case #%d:",cnn++);
		for(int i = k+1;i<=2*k-1;i++)
			printf(" %d",i);
		for(int i = 1;i<=k-1;i++)
			printf(" %d",i);
		printf(" %d %d",k,2*k);
		for(int i = 2*k+1;i<=n;i++)
			printf(" %d",i);
		printf("\n");
	}
	return 0;	
}
