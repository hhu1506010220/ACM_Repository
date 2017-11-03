#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 21000
#define maxm 1000000
#define INF 0x3f3f3f3f
using namespace std;
int n, m;
int head[maxn],cur[maxn], cnt;
int dist[maxn], vis[maxn];
struct node{
    int u, v, cap, flow, next;
};
node edge[maxm];

void init(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v, int w){
    node E1 = {u, v, w, 0, head[u]};
    edge[cnt] = E1;
    head[u] = cnt++;
    node E2 = {v, u, 0, 0, head[v]};
    edge[cnt] = E2;
    head[v] = cnt++;
}

void getmap(){
    int a, b, w;
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &a, &b);
        add(0, i, a);
        add(i, n + 1, b);
    }
    for(int j = 1; j <=m; ++j){
        scanf("%d%d%d", &a, &b, &w);
        add(a, b, w);
        add(b, a, w);
    }
}

bool BFS(int st, int ed){
    queue<int>q;
    memset(vis, 0 ,sizeof(vis));
    memset(dist, -1, sizeof(dist));
    vis[st] = 1;
    dist[st] = 0;
    q.push(st);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next){
            node E = edge[i];
            if(!vis[E.v] && E.cap > E.flow){
                vis[E.v] = 1;
                dist[E.v] = dist[u] + 1;
                if(E.v == ed) return true;
                q.push(E.v);
            }
        }
    }
    return false;
}

int DFS(int x, int ed, int a){
    if(a == 0 || x == ed)
        return a;
    int flow = 0, f;
    for(int &i = cur[x]; i != -1; i = edge[i].next){
        node &E = edge[i];
        if(dist[E.v] == dist[x] + 1 && (f = DFS(E.v, ed, min(a, E.cap - E.flow))) > 0){
            E.flow += f;
            edge[i ^ 1].flow -= f;
            flow += f;
            a -= f;
            if(a == 0) break;
        }
    }
    return flow;
}

int maxflow(int st, int ed){
    int sumflow = 0;
    while(BFS(st,ed)){
        memcpy(cur, head, sizeof(head));
        sumflow += DFS(st, ed, INF);
    }
    return sumflow;
}

int main (){
    while(scanf("%d%d", &n,&m) != EOF){
        init();
        getmap();
        printf("%d\n", maxflow(0, n + 1));
    }
    return 0;
}

