#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[105][105];
ll dp[105][105];

int main(){
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i;j++){
			dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
		}
	}
	ll maxn = -999999999;
	for(ll i=1;i<=n;i++)
		maxn = max(maxn,dp[n][i]);
	cout<<maxn<<endl;	
	return 0;	
}
