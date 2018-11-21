#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll num[50][50];
ll dp[50][50][10];

int main() {	
	int n,k;
	char a[50];
	cin >> n >> k;
	cin >> a;
	for(int i=0; i<n; i++) {
		num[i][i] = a[i]-'0';
		dp[i][i][0] = num[i][i];
		for(int j=i+1; j<n; j++) {
			num[i][j] = num[i][j-1]*10+(a[j]-'0');
			dp[i][j][0] = num[i][j];
		}
	}
	for(int i=0; i<n; i++) { 
		for(int j=i+1; j<n; j++) {//��i��j���� 
			for(int kk=1; kk<=k; kk++) {//�˺Ÿ��� 
				for(int m=i; m<=j; m++) {//ö�ٽضϵ� 
					for(int used=0; used<=kk; used++) {//ö�����ó˺Ÿ��� 
						dp[i][j][kk] = max (dp[i][j][kk],dp[i][m][used]*dp[m+1][j][kk-used-1]);
					}
				}
			}
		}
	}
	cout << dp[0][n-1][k]<<endl;
	return 0;
}

