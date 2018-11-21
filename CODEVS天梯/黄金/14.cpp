#include<bits/stdc++.h>
using namespace std;

struct ca{
	int x,y;	
}cant[10];
int dir[8][2]={
	1,2,
	1,-2,
	-1,2,
	-1,-2,
	2,1,
	2,-1,
	-2,1,
	-2,-1 
};
int dp[20][20];

int main(){
	memset(dp,0,sizeof(dp));
	int n,m;
	cin>>n>>m;
	n++,m++;
	int x,y;
	cin>>x>>y;
	x++,y++;
	int cnt = 0;
	for(int i=0;i<8;i++){
		int dx = x+dir[i][0];
		int dy = y+dir[i][1];
		if(dx>=1&&dx<=16&&dy>=1&&dy<=16){
			cant[cnt].x = dx;
			cant[cnt++].y = dy; 
		}
	}
	dp[1][1]=1;
	cant[cnt].x=x;cant[cnt++].y=y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bool flag = 1;
			for(int k=0;k<cnt;k++){
				if(i==cant[k].x&&j==cant[k].y){
					dp[i][j] = 0;
					flag = 0;
					break;
				}
			}
			if(!flag)continue;
			if(i==1&&j==1)continue;
			dp[i][j] = dp[i][j-1]+dp[i-1][j];
		}
	}
//	for(int i=0;i<cnt;i++)cout<<cant[i].x<<" "<<cant[i].y<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<dp[n][m]<<endl;
	return 0;
}
