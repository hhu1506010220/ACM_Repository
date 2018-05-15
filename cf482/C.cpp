#include<bits/stdc++.h>
using namespace std;
int n,x,y;
vector<int>g[300005];
int pre[300005];
int vis[300005];
int isXY[300005];
	
void findxy(int u,int fa){
	pre[u] = fa; 
	if(u==y) return ;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]!=fa){
			findxy(g[u][i],u);
		}
	}
}
	
int dfs(int u){
	int sum = 1;
	vis[u] = 1;
	for(int i=0;i<g[u].size();i++){
		if(!vis[g[u][i]]&&!isXY[g[u][i]]&&g[u][i]!=x&&g[u][i]!=y){
//			cout<<"!!!"<<endl;
			sum+=dfs(g[u][i]);	
		}
	}
	return sum;
}
	
	
int main(){
	cin>>n>>x>>y;
	int u,v;
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	memset(isXY,0,sizeof(isXY));
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);	
	}
//	for(int i=1;i<=n;i++)cout<<pre[i]<<" ";cout<<endl; 
	findxy(x,-1);
	for(int i=y;i!=x;i=pre[i])
		isXY[i]=1;
//	for(int i=1;i<=n;i++)cout<<pre[i]<<" ";cout<<endl;
	int cntx = dfs(x);
	int cnty = dfs(y);
	long long ans;
	ans = (long long)(1ll*n*(n-1))-(long long)(1ll*cntx*cnty);
//	cout<<cntx<<" "<<cnty<<endl;
	cout<<ans<<endl; 
	return 0;
}
