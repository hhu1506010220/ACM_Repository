#include<bits/stdc++.h>
using namespace std;

int a[20];
int res =0 ,n,m;

void dfs(int x,int sum){
	res = max(res,sum);
	if(x==n) return ;
	for(int i=0;i<=1;i++){
		if(i){
			dfs(x+1,sum);	
		}
		else{
			dfs(x+1,(sum+a[x])%m);
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i]%=m;	
		}
		res = 0 ;
		dfs(0,0);
		printf("%d\n",res);
	}
	return 0;
}
