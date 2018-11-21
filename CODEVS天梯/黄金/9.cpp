#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f
using namespace std;

long long dp[30005];
long long in[30005];
long long n;
void LCS(long long a[]){
	memset(dp,inf,sizeof(dp));
	for(long long i=0;i<n;i++){
		*lower_bound(dp,dp+n,a[i]) = a[i];	
	}
	long long ans = lower_bound(dp,dp+n,inf)-dp;
	printf("%lld\n",ans);
}

int main(){
	cin>>n;
	for(long long i=0;i<n;i++)
		cin>>in[i];
	LCS(in);
	return 0;
}
