#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define MAXN 1005
using namespace std;

int cnt;
map< string,int > mp;
int head[MAXN];
bool visited[MAXN];
int dist[MAXN][MAXN];
struct EdgeNode {
	int to;
	int next;
} edges[MAXN*20];

void addedge(int u, int v) {
	edges[cnt].to=v;
	edges[cnt].next=head[u];
	head[u]=cnt++;
}

void bfs(int u) {
	queue<int> Q;
	Q.push(u);
	dist[u][u]=0;
	memset(visited,0,sizeof(visited));
	visited[u]=1;
	while( !Q.empty() ) {
		int now=Q.front();
		Q.pop();
		for(int i=head[now]; i!=-1; i=edges[i].next) {
			int to=edges[i].to;
			if(!visited[to]) {
				dist[u][to]=dist[u][now]+1;
				Q.push(to);
				visited[to]=1;
			}
		}
	}
}

int main() {
	int n,k;
	char a[15],b[15];
	while(scanf("%d",&n)!=EOF && n) {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		mp.clear();
		memset(head,-1,sizeof(head));
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				dist[i][j]=dist[j][i]=inf;
			}
		}
		for(int i=1; i<=n; i++) {
			char name[15];
			scanf("%s",name);
			mp[name]=i;
		}
		cnt=0;
		scanf("%d",&k);
		while(k--) {
			scanf("%s%s",a,b);
			addedge(mp[a],mp[b]);
			addedge(mp[b],mp[a]);
		}
		for(int i=1; i<=n; i++)bfs(i);
		int ans=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(dist[i][j]>ans)
					ans=dist[i][j];
			}
		}
		if(ans==inf)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
