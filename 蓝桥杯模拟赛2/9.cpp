#include<bits/stdc++.h>
using namespace std;

long long  n,k, dp[305][305];

int main(){
	cin>>n>>k;
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i==1||j==1)dp[i][1] = dp[1][j] = 1;
			// i<jʱ �൱��i�ֳ�i�� 
			if(i<j)  dp[i][j] = dp[i][i];
			// i=jʱ ������� ÿ����1�� ������һ���Ѳ��� 
			else if(i==j){
				dp[i][j] = dp[i][j-1] +1 ;	
			}
			// i>jʱ ������� ��һ������ ����ÿ����һ��ʣ���i-j��ȥ��j�� 
			else {
				dp[i][j] = dp[i-j][j] + dp[i][j-1];	
			}
			
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
}
