#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[51][51];
ll dp[51][51][51][51]; 
struct step{
	ll x,y;	
}s;

ll main(){
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin>>a[i][j];
			dp[i][j][i][j] = 0;	
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			for(ll k=1;k<=n;k++){
				for(ll l=1;l<=m;l++){
					// ��û���յ�ǰ�����ߵ�ͬһ���㣬���(i, j)���ܵ���(k, l)
					if((i<n||j<m)&&i==k&&j==l){
						continue;
					}
					// ����С���ж�����Ϊ��(i, j)��(k, l)����ʱ�����øж�ֵ�ض�һ���������ظ�����
					if(i<k&&j<l){
						continue;	
					}
					dp[i][j][k][l] = max(dp[i-1][j][k-1][l], max(dp[i-1][j][k][l-1],
									max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1])))+a[i][j]+a[k][l];
				}
			}
		}
	}
	cout<<dp[n][m][n][m]<<endl;
	return 0;
}
