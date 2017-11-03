#include <cstdio>
#include <cstring>
#include<iostream>
#define INF 99999999
using namespace std;

typedef struct {
    int num;
    int time;
}node;
int n,l;
int dis[105][105],w[1005][1005];
int linker[1005],vis[1005];
node no[1005];

void floyd() {
    for(int k = 0;k < n;k++)
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                if(dis[i][k] < INF &&
                   dis[k][j] < INF &&
                   dis[i][j] > dis[i][k] + dis[k][j])
                   dis[i][j] = dis[i][k] + dis[k][j];
}

bool dfs(int u) {
    for(int v = 1;v <= l;v++)
        if(w[u][v] && !vis[v]) {
            vis[v] = 1;
            if(linker[v] == -1 || dfs(linker[v])) {
                linker[v] = u;
                return true;
            }
        }
    return false;
}

int hungary() {
    int res = 0;
    memset(linker,-1,sizeof(linker));
    for(int u = 1;u <= l;u++) {
        memset(vis,0,sizeof(vis));
        if(dfs(u)) res++;
    }
    return res;
}

int main() {
    int m;
    //freopen("test.in","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&l) && (n + m + l)) {
        memset(w,0,sizeof(w));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++) {
                dis[i][j] = INF;
                if(i == j) dis[i][j] = 0;
            }


        while(m--) {
            int a,b,val;
            scanf("%d%d%d",&a,&b,&val);
            dis[a][b] = val;
            dis[b][a] = val;
        }

        floyd();

        for(int i = 1;i <= l;i++)
            scanf("%d%d",&no[i].num,&no[i].time);

        for(int i = 1;i <= l;i++)
            for(int j = 1;j <= l;j++) {
            if(i == j) continue;
            int f = no[i].num,t = no[j].num;
            int ft = no[i].time,tt = no[j].time;
            if(ft + dis[f][t] <= tt) w[i][j] = 1;
        }

        printf("%d\n",l - hungary());
    }
    return 0;
}

