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
	for(int i=0; i<n; i++) {
		cin>>w;
		a[i] = w;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			dp[i][j] = 0;
		}
	}
	int _end;
	int maxn = 0;
	for(int j=1; j<=n; j++) {//长度 
		for(int i=0; i<n; i++) {//起始点
			_end =(i+j)%n;
			for(int k=i;k<i+j;k++){//截断点 
				int _en = k%n;
				if(k==i||k==i+j)dp[i][k]=0;
				else
					dp[i][_end] = max(dp[i][_end],dp[i][_en]+dp[_en][_end]+a[i]*a[_en]*a[_end]);	
			}
			maxn = max(maxn,dp[i][_end]);
		}
	}
	cout<<maxn<<endl;
	return 0;
}
