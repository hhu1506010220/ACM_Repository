#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int y;	
}; 

int n;
int mp[105][105];
int vis[105][105];//标记是否在队列里 
int step[105][105];
int sx,sy;
int ex,ey;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void BFS(){
	node t;
	t.x = sx,t.y = sy;
	queue<node>q;
	q.push(t);
	int dx,dy;
	vis[sx][sy] = 1;
	step[sx][sy] = 0;
	while(!q.empty()){
		node cr = q.front();
		q.pop();
		vis[cr.x][cr.y] = 0; // 不在队列里的可以再次访问 更新新值 
		for(int i=0;i<4;i++){
			dx = cr.x + dir[i][0];
			dy = cr.y + dir[i][1];
			if(dx<0||dx>=n||dy<0||dy>=n)continue;
			if(step[cr.x][cr.y] + mp[dx][dy] < step[dx][dy]){
				step[dx][dy] = step[cr.x][cr.y] + mp[dx][dy];
				if(!vis[dx][dy]){
					vis[dx][dy] = 1;
					t.x = dx;
					t.y = dy;
					q.push(t);
				}
			}
		}
		
	}
	return ;
}

int main(){
	while(cin>>n){
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		memset(step,0x3f3f3f3f,sizeof(step));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>mp[i][j];
				if(mp[i][j]==-1){
					sx = i;
					sy = j;
					mp[i][j] = 0;	
				}
				else if(mp[i][j]==-2){
					ex = i;
					ey = j;
					mp[i][j] = 0;	
				}
			}
		}
		BFS();
		cout<<step[ex][ey]<<endl;
	}	
	return 0;
}
