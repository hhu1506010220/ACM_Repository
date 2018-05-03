#include<bits/stdc++.h>
using namespace std;

int mp[1005][1005];
int dir[8][2]={2,-1,2,1,-2,1,-2,-1,1,-2,1,2,-1,2,-1,-2};
int n , m;

void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int dx = x+dir[i][0];
		int dy = y+dir[i][1];
		if(dx<0||dx>=n||dy<0||dy>=m||mp[dx][dy])
			continue;
		mp[dx][dy] = -mp[x][y];
		dfs(dx,dy);
	}
	return;
}

int main(){
	int ans = 0 ;
	cin>>n>>m;
	memset(mp,0,sizeof(mp));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!mp[i][j]){
				mp[i][j] = -1;
				dfs(i,j);	
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mp[i][j]==1)
				ans++;	
	cout<<max(ans,n*m-ans)<<endl;
	
	return 0;	
}
