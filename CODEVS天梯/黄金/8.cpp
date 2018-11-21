#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int dp[30005];
int in[30005],in2[30005];
int n;
void LCS1(int a[]){
	memset(dp,inf,sizeof(dp));
	for(int i=0;i<n;i++){
		*lower_bound(dp,dp+n,a[i]) = a[i];	
	}
	int ans = lower_bound(dp,dp+n,inf)-dp;
	printf("%d\n",ans);
}

void LCS2(int a[]){
	memset(dp,inf,sizeof(dp));
	for(int i=0;i<n;i++){
		*lower_bound(dp,dp+n,a[i]) = a[i];	
	}
	int ans = lower_bound(dp,dp+n,inf)-dp;
	printf("%d\n",ans);
}

int main(){
	freopen("in.txt","r",stdin);
	int aa;
	while(~scanf("%d",&aa)){
		in[n]=aa;
		in2[n]=aa;
		n++;	
	}
	for(int i=0;i<n/2;i++){
		int t = in[i];
		in[i] = in[n-i-1];
		in[n-i-1] = t;	
	}
	LCS1(in);
	LCS2(in2);
	return 0;
}
