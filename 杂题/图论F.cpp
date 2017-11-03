#include<iostream>
#include<stdio.h>
#include<cmath>
#include<memory.h>
using namespace std;
 
const int maxn = 50010;
int N;
 
int root;
 
//图: 邻接表
struct Edge
{
         int v;
         int len;
 
         Edge* link;
};
 
Edge buffer[maxn*2];  //2(N-1)条边
int tol;
 
struct Node
{
         int rlen; //len(root,u)  //当前结点u到根结点root的距离
         Edge* link;
};
 
Node node[maxn];  ////用邻接链表存放图
 
bool vis[maxn];
 
void add_edge(int u,int v,int w)
{
         Edge *tmp_edge = &buffer[tol++];
 
         tmp_edge->v = v;
 
         tmp_edge->len = w;
 
         tmp_edge->link = node[u].link;
 
         node[u].link = tmp_edge;
}
 
 
//LCA
int Index[maxn*2];  ////欧拉序列 [1..2n-1];
int dep[maxn*2];    ////欧拉序列对应的深度数组[1..2n-1]
int first[maxn];    //各结点在欧拉序列中第一次出现的时间(下标)
int cnt;            // //欧拉序列的全局下标
 
///LCA DFS
 
void DFS(int u,int DEP,int rlen)    //(2E)
{
         //G
         vis[u] = 1;
         node[u].rlen = rlen;       // 根结点到结点u的距离
 
         //LCA DATA
         Index[cnt] = u;
         dep[cnt]   = DEP;
 
         if(first[u] == 0)
                   first[u] = cnt;
         cnt++;
 
         //DFS
         Edge *tmp = node[u].link;
 
         while(tmp)
         {
                   if(vis[tmp->v] == 0)
                   {
                            DFS(tmp->v,DEP+1,rlen+tmp->len);
 
                            //LCA DATA
                            Index[cnt] = u;
                            dep[cnt]   = DEP;
                            cnt++;
                   }
 
                   tmp = tmp->link;
         }
}
////////////////
 
 
///////RMQ 对dep数组进行RMQ    //O(NlogN)
 
int dp[maxn*2][17];  //存放区间最小值的下标        //dp[i][j] 表示[i...i+(2^j)-1]这个区间的最小值(的下标)
 
void RMQ_PRE(int *dep,int n)  ////计算各区间最小值在dep/Index数组的下标     
{
         for(int i=1; i<=n; i++)
                   dp[i][0] = i;
 
         int m = log(double(n)) / log(2.0);
 
         for(int j=1; j<=m; j++)
                   for(int i=1; i+(1<<j)-1 <= n; i++)
                   {
                            if(dep[ dp[i][j-1] ] <= dep[ dp[i+(1<<(j-1))][j-1] ] )
                                    
                                     dp[i][j] = dp[i][j-1];
                            else
                                     dp[i][j] = dp[i+(1<<(j-1))][j-1];
                   }
}
 
int RMQ(int *dep,int l,int r)  //询问各区间最小值在dep/Index数组的下标
{
         int k = log(double(r-l+1)) / log(2.0);
 
         if(dep[ dp[l][k] ] <= dep[ dp[r-(1<<k)+1][k] ])
                  
                   return dp[l][k];
         else
                   return dp[r-(1<<k)+1][k];
}
 
//end rmq
 
 
 
//LCA
int LCA(int a,int b) //返回dep,b的最近公共祖先的ID
{
         int i = first[a];
         int j = first[b];
 
         if(i > j) swap(i,j);
 
         return Index[RMQ(dep,i,j)];  //注意将得到的dep/Index数组下标转换为结点序号
}
 
 
int main()
{
         int T=0;
         while(scanf("%d",&N)!=EOF)   //单个case:O(NlogN)+O(Q)
         {
                   if(T++) puts("");
                   //LCA init
                   cnt = 1;
                   memset(first,0,sizeof(first));
 
                   //Graph init
                   tol = 0;
                   memset(node,0,sizeof(node));
                   memset(vis,0,sizeof(vis));
 
                   int u,v,w;
                   for(int i=1; i<N; i++)
                   {
                            scanf("%d%d%d",&u,&v,&w);
 
                            //插入边<u,v>
                            add_edge(u,v,w);
 
                             //插入边<v,u>
                            add_edge(v,u,w);
                   }
 
                  
                   root = 0;
 
                   DFS(root,0,0);
 
                   RMQ_PRE(dep,2*N-1);  //O(NlogN)
 
                   int Q;
 
                   scanf("%d",&Q);
 
                   int x,y,z;
                  
                   int Axy;
                   int lenxy;
 
                   int Axz;
                   int lenxz;
 
                   int Ayz;
                   int lenyz;
 
                   int Axyz;
 
                   int lenxyz;
 
                   int LEN;
 
                   while(Q--)  //O(1)*Q
                   {
                            scanf("%d%d%d",&x,&y,&z);
 
                            Axy = LCA(x,y);    //O(1)  //得到最近公共祖先的序号
 
                            lenxy = node[x].rlen + node[y].rlen - 2 * node[Axy].rlen;
                           
                            Axz = LCA(x,z);
 
                            lenxz = node[x].rlen + node[z].rlen - 2 * node[Axz].rlen;
 
                            Ayz = LCA(y,z);
 
                            lenyz = node[y].rlen + node[z].rlen - 2 * node[Ayz].rlen;
 
                            LEN = (lenxy + lenxz + lenyz) / 2;
                           
                            printf("%d",LEN);
                           
                            puts("");
                  
                   }
         }
 
         return 0;
}

