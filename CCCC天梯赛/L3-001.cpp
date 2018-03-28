#include<bits/stdc++.h>
#define inf 0x3f3f3f3f 
using namespace std;

int a[10005],dp[10005],pre[10005],ans[10005];

void print(int x){
	if(!pre[x]){
		printf("%d",ans[x]);
		return ;		
	}
	print(pre[x]);
	printf(" %d",ans[x]);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	memset(pre,-1,sizeof(pre));
	memset(ans,0,sizeof(ans));
	memset(dp,-inf,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=m;j>=a[i];j--){	
			if(dp[j]<=dp[j-a[i]]+1){
				dp[j] = dp[j-a[i]]+1;
				ans[j] = a[i];
				pre[j] = j-a[i]; 	
			}
		}
	}
	if(dp[m]<=0)
		puts("No Solution");
	else
		print(m);
	return 0;	
}
