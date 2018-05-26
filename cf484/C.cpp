#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
vector<int>g[maxn]; 
int vis[maxn];
int cnt = 0;

int dfs(int u){
	vis[u] = 1;
	int sum = 0;
	for(int i=0;i<g[u].size();i++){
		if(vis[g[u][i]])continue;
		sum += dfs(g[u][i]);
	}
	sum++;
	if(sum%2==0&&u!=1){
		cnt++;	
	}
//	cout<<u<<": "<<sum<<endl;
	return sum;
}

int main(){
	int n;
	cin>>n;
	int u,v;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n%2==1){
		puts("-1");
		return 0;	
	}
	dfs(1);
	cout<<cnt<<endl;

	return 0;
}

/*
10
1 3
3 5
2 4
4 6
5 7
6 7
7 8
8 9
9 10
*/
