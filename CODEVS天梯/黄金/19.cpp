#include<bits/stdc++.h>
using namespace std;

int dp[205][11]; 

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		dp[i][1] = 1;	
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			if(j>i)break;
			//��i��������һ��  �� ����ӵ����������ȥ 
			dp[i][j] = dp[i-1][j-1]+dp[i-j][j];	
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
}
