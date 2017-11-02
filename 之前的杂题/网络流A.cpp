#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
const int MAX=10100;  
const int INF=1000000000;  
struct EDGE  
{  
    int v,c,next;  
}edge[101000];  
int E,head[MAX];  
int gap[MAX],cur[MAX];  
int pre[MAX],dis[MAX];  
void add_edge(int s,int t,int c,int cc)  
{  
    edge[E].v=t; edge[E].c=c;  
    edge[E].next=head[s];  
    head[s]=E++;  
    edge[E].v=s; edge[E].c=cc;  
    edge[E].next=head[t];  
    head[t]=E++;  
}  
int min(int a,int b){return (a==-1||b<a)?b:a;}  
int SAP(int s,int t,int n)  
{  
    memset(gap,0,sizeof(gap));  
    memset(dis,0,sizeof(dis));  
    int i;  
    for(i=0;i<n;i++)cur[i]=head[i];  
    int u=pre[s]=s,maxflow=0,aug=-1,v;  
    gap[0]=n;      
    while(dis[s]<n)  
    {  
loop:    for(i=cur[u];i!=-1;i=edge[i].next)  
         {  
             v=edge[i].v;  
             if(edge[i].c>0&&dis[u]==dis[v]+1)  
             {  
                 aug=min(aug,edge[i].c);  
                 pre[v]=u;  
                 cur[u]=i;  
                 u=v;  
                 if(u==t)  
                 {  
                     for(u=pre[u];v!=s;v=u,u=pre[u])  
                     {  
                         edge[cur[u]].c-=aug;  
                         edge[cur[u]^1].c+=aug;  
                     }  
                     maxflow+=aug;  
                     aug=-1;  
                 }  
                 goto loop;  
             }  
         }  
         int mindis=n;  
         for(i=head[u];i!=-1;i=edge[i].next)  
         {  
             v=edge[i].v;  
             if(edge[i].c>0&&dis[v]<mindis)  
             {  
                 cur[u]=i;  
                 mindis=dis[v];  
             }  
         }  
         if((--gap[dis[u]])==0)break;  
         gap[dis[u]=mindis+1]++;  
         u=pre[u];  
    }  
    return maxflow;  
}  
int m , n , S, T;  
int sum_row[210] , sum_col[210];  
int low[210][210] , up[210][210] ,in[10010];  
bool judge(int i,int j,char op,int c)  
{  
    if(op=='=')  
    {  
        if(c >= low[i][j] && c <= up[i][j])  
        {  
            low[i][j] = c;  
            up[i][j]  = c;  
        }  
        else return false;  
    }  
    else if(op=='>')  
    {  
        low[i][j] = max(low[i][j],c+1);  
        if(low[i][j] > up[i][j]) return false;  
    }  
    else   
    {  
        up[i][j] = min(up[i][j],c-1);  
        if(low[i][j] > up[i][j]) return false;  
    }  
    return true;  
}  
bool init()  
{  
    E=0;  
    memset(head,-1,sizeof(head));  
    memset(in,0,sizeof(in));  
    int i , j , k , a, b , c;  
    scanf("%d%d",&m,&n);  
    int tot = 2 * n * m;   
    S = 0; T = tot + n + m + 1;  
    for(i = 1; i <= m; i++)  
    {  
        scanf("%d",&sum_row[i]);  
        in[i+tot] = sum_row[i];  
        in[S] -= sum_row[i];  
        //add_edge(S,i+tot,sum_row[i],0);  
    }  
    for(i = 1; i <= n; i++)  
    {  
        scanf("%d",&sum_col[i]);  
        in[T] += sum_col[i];  
        in[m+tot+i] = - sum_col[i];  
        //add_edge(m+tot+i,T,sum_col[i],0);  
    }  
    add_edge(T,S,INF,0);  
    scanf("%d",&k); char op[5];  
    for(i = 1; i <= m; i++) for(j = 1; j <= n; j++) low[i][j] = 0, up[i][j] = 200000;  
    bool flag = true;  
    for(int x = 0; x < k; x++)  
    {  
        scanf("%d%d%s%d",&a,&b,op,&c);  
        if(!a)  
        {  
            if(!b)  
            {  
                for(i = 1; i <= m; i++)  
                {  
                    for(j = 1; j <= n; j++)  
                    {  
                        if(!judge(i,j,op[0],c)) flag = false;  
                    }  
                }  
            }  
            else   
            {  
                for(i = 1; i <= m; i++)  
                {  
                    if(!judge(i,b,op[0],c)) flag = false;  
                }  
            }  
        }  
        else   
        {  
            if(!b)  
            {  
                for(i = 1; i <= n; i++)  
                {  
                    if(!judge(a,i,op[0],c)) flag = false;  
                }  
            }  
            else   
            {  
                if(!judge(a,b,op[0],c)) flag = false;  
            }  
        }  
    }  
    return flag;  
}   
int ans[250][250];  
bool check()  
{  
    for(int i = 1; i <= m; i++)  
    {  
        int s = 0;  
        for(int  j =1; j <=n;j ++)  
        {  
            s += ans[i][j];  
        }  
        if(s!=sum_row[i]) return false;  
    }  
    for(int i = 1; i <= n; i++)  
    {  
        int s =  0;  
        for(int j = 1; j <= m; j++)  
        {  
            s += ans[j][i];  
        }  
        if(s!=sum_col[i]) return false;  
    }  
    return true;  
}  
bool solve()  
{  
    int i , j , k;  
    for(i = 1; i <= m; i++)  
    {  
        for(j = 1; j <= n; j++)  
        {  
            int c = up[i][j] - low[i][j];  
            int id = (i-1)*n+j;  
        //  printf("i=%d j=%d  id = %d %d c = %d\n",i,j,id,id+n*m,c);  
            add_edge(id,id+n*m,c,0);  
            in[id] -= low[i][j];  
            in[id+n*m] += low[i][j];  
        }  
    }  
    int ss = T + 1, tt = ss + 1;  
    for(i = 1; i <= m; i++)  
    {  
        for(j = 1; j <= n; j++)  
        {  
            add_edge(2*n*m+i,(i-1)*n+j,200000,0);  
        }  
    }  
    for(i = 1; i <= n; i++)  
    {  
        for(j = 1; j <= m; j++)  
        {   //printf("%d %d\n",2*n*m+m+i,(j-1)*n+i+n*m);  
            add_edge((j-1)*n+i+m*n,2*m*n+m+i,200000,0);  
        }  
    }  
    for(i = 0; i <= 2*m*n+m+n+1 ; i++)  
    {  
        //printf("in[%d]=%d\n",i,in[i]);  
        if(in[i] > 0) add_edge(ss,i,in[i],0);  
        if(in[i] < 0) add_edge(i,tt,-in[i],0);  
    }  
    SAP(ss,tt,tt+1);  
    for(i=head[ss];i!=-1;i=edge[i].next)  
    {  
        if(edge[i].c) return false;  
    }  
    for(i = 1; i <= m; i++)  
    {  
        for(j = 1; j <= n; j++)  
        {  
            int id = (i-1)*n+j;  
            for(k = head[id]; k!=-1; k=edge[k].next)  
            {  
                if(edge[k].v <= 2*n*m)  
                {  
                    ans[i][j] = low[i][j] + edge[k^1].c;  
                }  
            }  
        }  
    }  
    for(i = 1; i <= m; i++)  
    {  
        printf("%d",ans[i][1]);  
        for(j = 2; j <= n; j++)  
        {  
            printf(" %d",ans[i][j]);  
        }  
        puts("");  
    }  
      
/*  if(check()) { 
        puts("YES"); 
    } else puts("NO");*/  
    return true;  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int i = 0; i < t; i++)  
    {  
        if(i) puts("");  
        if(!init())  
        {  
            puts("IMPOSSIBLE");  
        }  
        else   
        {  
            if(!solve()) puts("IMPOSSIBLE");  
        }  
    }  
    return 0;  
}  
