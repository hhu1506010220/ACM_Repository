#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=510;
int uN,vN;
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    int v;
    for(v=0;v<vN;v++)
      if(g[u][v]&&!used[v])
      {
          used[v]=true;
          if(linker[v]==-1||dfs(linker[v]))
          {
              linker[v]=u;
              return true;
          }
      }
    return false;
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}

int main()
{
     int m;
     int u,v;
     int iCase=0;
     while(scanf("%d%d%d",&uN,&vN,&m))
     {
         iCase++;
         if(uN==0&&vN==0&&m==0)break;
         for(int i=0;i<uN;i++)
           for(int j=0;j<vN;j++)
              g[i][j]=1;
         while(m--)
         {
             scanf("%d%d",&u,&v);
             u--;
             v--;
             g[u][v]=0;
         }
         printf("Case %d: %d\n",iCase,uN+vN-hungary());
     }
     return 0;
}
