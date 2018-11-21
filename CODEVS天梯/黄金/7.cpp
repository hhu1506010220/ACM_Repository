#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[40][40][40][40];
int w[400];
int e[5];

int main() {
	int a;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)scanf("%d",&w[i]);
	for(int i=0; i<m; i++) {
		scanf("%d",&a);
		e[a]++;
	}
	dp[0][0][0][0]=w[0];
	for(int i=0; i<=e[1]; i++)
		for(int j=0; j<=e[2]; j++)
			for(int k=0; k<=e[3]; k++)
				for(int l=0; l<=e[4]; l++) {
					int d=i+j*2+k*3+l*4;
					if(i)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]+w[d]);
					if(j)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]+w[d]);
					if(k)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]+w[d]);
					if(l)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]+w[d]);
				}
	printf("%d",dp[e[1]][e[2]][e[3]][e[4]]);
	return 0;
}

