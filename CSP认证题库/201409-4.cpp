#include<bits/stdc++.h>
using namespace std;

int mp[1005][1005],vis[1005][1005];
struct node{
	int x, y,step;	
}p,t,now;
int n,m,k,d,l;
int x,y;
queue<node>q;
long long ans = 0;

bool isOK(node t){
	if(t.x>n||t.y>n||t.x<1||t.y<1)
		return 0;
	if(mp[t.x][t.y]==-2)
		return 0;
	if(vis[t.x][t.y]){
		return 0;
	}
	return 1;
}

void bfs(){
	int dir[4][2]={0,1,0,-1,1,0,-1,0};
	while(!q.empty()){
		now = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			t.x = now.x + dir[i][0];
			t.y = now.y + dir[i][1];
			t.step = now.step + 1; 
			if(!isOK(t)){
				continue;
			}
			if(mp[t.x][t.y]>0){
				ans += t.step*mp[t.x][t.y];
			}
			vis[t.x][t.y] = 1;
			q.push(t);
		}
//		cout<<now.x<<" "<<now.y<<" "<<now.step<<endl;
	}
}

int main(){
	cin>>n>>m>>k>>d;
	memset(mp,0,sizeof(mp));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<m;i++){
		cin>>x>>y;
		mp[x][y] = -1;			//-1代表分店 
		p.x = x;
		p.y = y;
		p.step = 0;
		q.push(p);
	}
	for(int i=0;i<k;i++){
		cin>>x>>y>>l;
		if(!mp[x][y])
			mp[x][y] = l;		//>0代表客户   0表示可走 
		else
			mp[x][y] += l;
	}
	for(int i=0;i<d;i++){
		cin>>x>>y;
		mp[x][y] = -2;			//-2代表不可达到 
	}
	bfs();
//	for(int i=0;i<10;i++){
//		for(int j=0;j<10;j++){
//			cout<<mp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<ans<<endl;
	return 0;	
}
