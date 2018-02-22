#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
struct edge {
    int64 to, cost, next;
    edge() {}
    edge(int64 _to, int64 _cost, int64 _next) : to(_to), cost(_cost), next(_next) {}
} e[200005];
int64 tot;
int64 head[100005];

void init_graph() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

void addedge(int64 from, int64 to, int64 cost) {
    e[tot] = edge(to, cost, head[from]);
    head[from] = tot++;
}

int64 dis[100005];
bool vis[100005];
bool viss[100005];

int n,m,p,k;

void dijkstra(int64 s, int64 t) {
    using PLI = pair<int64, int64>;
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
    pq.push(PLI(0, s));
    dis[s] = 0;
    while(!pq.empty()) {
        PLI now = pq.top();
        pq.pop();
        if(vis[now.second]) continue;
        vis[now.second] = true;
        for(int64 i = head[now.second]; i != -1; i = e[i].next) {
            if(!vis[e[i].to] && e[i].cost + now.first < dis[e[i].to]) {
                dis[e[i].to] = e[i].cost + now.first;
                pq.push(PLI(dis[e[i].to], e[i].to));
            }
        }
    }
    return ;
}

int main() {
	while(~scanf("%lld%lld%lld%lld",&n,&m,&p,&k)){
		memset(viss,0,sizeof(viss));
		init_graph();
		int64 tem, u , v , w ;
		for(int64 i=0;i<k;i++){
			scanf("%lld",&tem);
			addedge(0, tem, 0);
			addedge(tem, 0, 0);
			viss[tem]=1;
		}
		for(int64 i=0; i<m; i++) {
			scanf("%lld%lld%lld", &u, &v, &w);
			addedge(u, v, w);
			addedge(v, u, w);
		}
		long long ans = 0;
		dijkstra(0,n+1);		
		for(int64 i=1; i<=n; i++){
			if(dis[i]<=p&&!viss[i])ans++;			
		}
		printf("%lld\n", ans);
	}
}
