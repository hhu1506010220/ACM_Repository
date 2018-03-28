#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[10005];
typedef pair<long long,long long> Pair;
vector< Pair >g[10005];
long long ans ;
long long vis[10005];

void dfs(long long s,long long t,long long money){
	long long min_cost;
	long long cost;
	if(s==t){
		cout<<ans<<endl;
		return;
	}
	vis[s] = 1;
	for(long long i=0;i<g[s].size();i++){
		if(!vis[g[s][i].first]){
			vis[g[s][i].first] = 1;
			min_cost = min(money,a[s]);
			cost = g[s][i].second*min_cost;
			ans += cost;
			dfs(g[s][i].first,t,min_cost);
			ans -= cost;
		}
	}
}

int main(){
	cin>>n>>m;
	long long u,v,w;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=0;i<n-1;i++){
		cin>>u>>v>>w;
		g[u].push_back(Pair(v,w));
		g[v].push_back(Pair(u,w));
	}
	long long si,ti;
	for(long long i=0;i<m;i++){
		cin>>si>>ti;
		ans = 0;
		memset(vis,0,sizeof(vis));
		dfs(si,ti,a[si]);
	}
	return 0;	
}
