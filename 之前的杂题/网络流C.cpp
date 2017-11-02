#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <queue>  
using namespace std;  
  
const int N = 1000;  
const int INF = 0x3f3f3f3f;  
struct edge  
{  
    int to, cap, next;  
}g[N*1000];  
int iter[N], level[N], head[N];  
int cnt;  
void addedge(int v, int u, int cap)  
{  
    g[cnt].to = u, g[cnt].cap = cap, g[cnt].next = head[v], head[v] = cnt++;  
    g[cnt].to = v, g[cnt].cap = 0, g[cnt].next = head[u], head[u] = cnt++;  
}  
bool bfs(int s, int t)  
{  
    memset(level, -1, sizeof level);  
    queue<int> que;  
    level[s] = 0;  
    que.push(s);  
    while(! que.empty())  
    {  
        int v = que.front(); que.pop();  
        for(int i = head[v]; i != -1; i =g[i].next)  
        {  
            int u = g[i].to;  
            if(g[i].cap > 0 && level[u] < 0)  
            {  
                level[u] = level[v] + 1;  
                que.push(u);  
            }  
        }  
    }  
    return level[t] == -1;  
}  
int dfs(int v, int t, int f)  
{  
    if(v == t) return f;  
    for(int &i = iter[v]; i != -1; i = g[i].next)  
    {  
        int u = g[i].to;  
        if(g[i].cap > 0 && level[v] < level[u])  
        {  
            int d = dfs(u, t, min(f, g[i].cap));  
            if(d > 0)  
            {  
                g[i].cap -= d, g[i^1].cap += d;  
                return d;  
            }  
        }  
    }  
    return 0;  
}  
int dinic(int s, int t)  
{  
    int flow = 0, f;  
    while(true)  
    {  
        if(bfs(s, t)) return flow;  
        memcpy(iter, head, sizeof head);  
        while(f = dfs(s, t, INF), f > 0)  
            flow += f;  
    }  
} 
 int main()
 {
     int n,fn,dn;
     while(~scanf("%d%d%d",&n,&fn,&dn))
     {
         cnt = 0;  
         memset(head, -1, sizeof(head)); 
		 int source=0;
		 int end= fn + 2 * n + dn + 1;
//         cout<<"2"<<endl;
         // f:1~fn cow1:fn+1~fn+n cow2:fn+n+1~fn+2n dn:fn+2n+1~fn+2n+dn 
		 for(int j=1;j<=n;j++){
			addedge(fn+j,fn+n+j,1);
		 }
//	     cout<<"1"<<endl;
		 for(int j=1;j<=fn;j++){
			addedge(0,j,1);
		 }
//		 cout<<"3"<<endl;
	 	 for(int j=1;j<=dn;j++){
			addedge(fn+2*n+j,fn+2*n+dn+1,1);
		 }
//		 cout<<"4"<<endl;
         for(int i=1;i<=n;i++)
         {
         	 int fn1,dn2;
          	 scanf("%d%d",&fn1,&dn2);
          	 for(int j=0;j<fn1;j++){
          	 	int s;
          	 	scanf("%d",&s);
          	 	addedge(s,fn+i,1);
			 }
			 for(int j=0;j<dn2;j++){
			 	int s;
			 	scanf("%d",&s);
			 	addedge(fn+n+i,fn+2*n+s,1);
			 }
         }
         printf("%d\n",dinic(source,end));
     }
     return 0;
 }
