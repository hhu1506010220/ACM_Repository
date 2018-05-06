#include<bits/stdc++.h>
using namespace std;

char mp[505][505];
char view[505][505];
int vis[505][505];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,k;

void dfs(int x,int y) {
	view[x][y]='0';
	for(int i=0; i<8; i++) {
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(xx<1||yy<1||xx>n||yy>m) continue;
		if(mp[xx][yy]=='*') continue;
		if(!vis[xx][yy]&&mp[xx][yy]=='.') {
			vis[xx][yy]=1;
			dfs(xx,yy);
		} else if(mp[xx][yy]>='1'&&mp[xx][yy]<='8'){
			view[xx][yy]=mp[xx][yy];
		}
	}
}

int main() {
	int t;
	cin>>t;
	char s;
	int x,y;
	while(t--) {
		memset(vis,0,sizeof(vis));
		memset(mp,0,sizeof(mp));
		memset(view,0,sizeof(view));
		int step = 1;
		cin>>n>>m>>k;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>mp[i][j];
				view[i][j] = '.';
			}
		}
		bool flag = 1;
		for(int i=1; i<=k; i++) {
			cin>>x>>y;
			if(!flag)continue;
			if(mp[x][y]=='*') {
				flag = 0;
				continue;
			} else if(mp[x][y]=='.') {
				if(vis[x][y])continue;
				else {
					vis[x][y]=1;
					dfs(x,y);
				}
			} else {
				view[x][y] = mp[x][y];
			}
			step++;
		}
		if(flag) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=m; j++) {
					cout<<view[i][j];
				}
				cout<<endl;
			}
		} else {
			cout<<"Game over in step "<<step<<endl;
		}
	}
	return 0;
}
