#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int a[105];
int dp[105][105];

int main() {
	int n;
	cin>>n;
	a[0] = 0;
	int w;
	for(int i=1; i<=n; i++) {
		cin>>w;
		a[i] = a[i-1] + w;
		dp[i][i] = 0;
	}
	int _end;
	for(int i=1; i<=n; i++) { //起点
		for(int j=1; i+j<=n; j++) { //长度
			_end = i+j;
			dp[i][_end] = inf;
		}
	}
	for(int j=1; j<=n; j++) { //长度
		for(int i=1; i+j<=n; i++) { //起点
			_end = i+j;
			for(int k=i; k<=_end; k++) {
				dp[i][_end] = min(dp[i][_end],dp[i][k]+dp[k+1][_end]+a[_end]-a[i-1]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
