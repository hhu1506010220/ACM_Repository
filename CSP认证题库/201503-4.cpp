#include<bits/stdc++.h>
using namespace std;

vector<int>g[20005];
queue<int>q;
int vis[20005],dis[20005];
int e;
int ans;

void bfs(int x){
	ans = 0;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	q.push(x);
	vis[x] = 1;
	dis[x] = 0;
	int tem;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=0;i<g[now].size();i++){
			tem = g[now][i];
			if(!vis[tem]){
				q.push(tem);
				vis[tem] = 1;
				dis[tem] = dis[now] + 1;
				if(ans<dis[tem]){
					ans = dis[tem];
					e = tem;
				}
			}
		}
	}
}


int main(){
	int n,m;
	cin>>n>>m;
	int t;
	for(int i=2;i<=n+m;i++){
		cin>>t;
		g[t].push_back(i);
		g[i].push_back(t);
	}
	bfs(1);
	bfs(e);
	cout<<ans<<endl;
	return 0;	
}
