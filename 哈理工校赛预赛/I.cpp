#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1005;
int vis[maxn];
int dis[maxn];
int head[maxn<<1];
int arr[maxn];
int n,m,t,cnt,x,y,z;
int ans;
struct node {
	int to,next,cost;
} edge[maxn*4];
void add(int from,int to,int cost) {
	edge[cnt].to=to;
	edge[cnt].cost=cost;
	edge[cnt].next=head[from];
	head[from]=cnt++;
}
void spfa(int x) {
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++)
		dis[i]=1e6;
	dis[x]=0;
	vis[x]=1;
	queue<int>q;
	q.push(x);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u]; i!=-1; i=edge[i].next) {
			int v=edge[i].to;
			int c=edge[i].cost;
			if(dis[v]>dis[u]+c) {
				dis[v]=dis[u]+c;
				if(vis[v]==0) {
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	int cntt=0;
	memset(arr,0,sizeof(arr));
	for(int i=1; i<=n; i++) {
		if(dis[i]!=1e6) {
			arr[cntt++]=dis[i];
		}
	}
	if(cntt<=2)
		return ;
	else {
		sort(arr,arr+cntt);
		ans=max(ans,arr[cntt-1]+arr[cntt-2]);
	}
}
int main() {
	scanf("%d",&t);
	while(t--) {
		ans=-1;
		scanf("%d%d",&n,&m);
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		for(int i=1; i<=n; i++) {
			spfa(i);
		}
		printf("%d\n",ans);
	}
}
