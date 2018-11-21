#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[61][61];

int main(){
	ll n,m;
	cin>>n>>m;
	ll x1,y1,x2,y2;
	cin>>y1>>x1>>y2>>x2;
	dp[x1][y1]=1;
	for(ll j=1;j<=m;j++){
		for(ll i=1;i<=n;i++){
			if(i-2<=n&&i-2>=1&&j-1>=1&&j-1<=m)
				dp[i][j] = dp[i-2][j-1];
			if(i+2<=n&&i+2>=1&&j-1>=1&&j-1<=m)	
				dp[i][j] += dp[i+2][j-1];
			if(i-1<=n&&i-1>=1&&j-2>=1&&j-2<=m)	
				dp[i][j] += dp[i-1][j-2];
			if(i+1<=n&&i+1>=1&&j-2>=1&&j-2<=m)	
				dp[i][j] += dp[i+1][j-2];
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=m;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<dp[x2][y2]<<endl;
	return 0;	
}
