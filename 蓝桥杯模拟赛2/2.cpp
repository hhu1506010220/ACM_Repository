#include<bits/stdc++.h>
using namespace std;

int mp[4][4]= {1,4,2,5,
               2,1,2,1,
               3,1,3,2,
               2,5,3,4
              };
int vis[4][4]= {0};
int dir[4][2]= {0,1,1,0,0,-1,-1,0};
int ans = 0;


int check(int x,int y) {
	if(vis[x][y]) return 0;
	if(x==0||x==3||y==0||y==3) return 1;
	for(int i=0; i<4; i++) {
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(vis[xx][yy]==1) return 1;
	}
	return 0;
}

void dfs(int step,int sum) {
	if(sum>ans) {
		ans = sum;
	}
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(check(i,j))
				for(int k=0; k<4; k++) {
					for(int l=0; l<4; l++) {
						if(k==i&&l==j)continue;
						if(mp[i][j]==mp[k][l]&&check(i,j)&&check(k,l)) {
							vis[i][j] = vis[k][l] = 1;
							dfs(step+1,step*mp[k][l]+sum);
							vis[i][j]= vis[k][l] = 0;
						}
					}
				}
		}
	}
}


int main() {
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
