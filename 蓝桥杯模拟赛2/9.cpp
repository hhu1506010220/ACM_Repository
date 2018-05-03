#include<bits/stdc++.h>
using namespace std;

long long  n,k, dp[305][305];

int main(){
	cin>>n>>k;
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i==1||j==1)dp[i][1] = dp[1][j] = 1;
			// i<j时 相当于i分成i份 
			if(i<j)  dp[i][j] = dp[i][i];
			// i=j时 两种情况 每堆有1个 或者有一个堆不放 
			else if(i==j){
				dp[i][j] = dp[i][j-1] +1 ;	
			}
			// i>j时 两种情况 有一个不放 或者每堆有一个剩余的i-j再去放j堆 
			else {
				dp[i][j] = dp[i-j][j] + dp[i][j-1];	
			}
			
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
}
