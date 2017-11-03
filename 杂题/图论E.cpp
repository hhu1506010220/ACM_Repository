#include<cstdio>
#include<cstring>
#define MAX 10005
#define min(a,b) a>b?b:a
using namespace std;
int tot,ans,tot_s,index_s,head[MAX],dfn[MAX],low[MAX],stack[MAX],instack[MAX];
struct Eage
{
	int from,to;
	int next;
}eage[MAX*10];
void add(int a,int b)
{
	Eage e={a,b,head[a]};
	eage[tot]=e;
	head[a]=tot++;
}
void tarjan(int k)
{
	int j,v;
	if(ans)
		return;
	stack[tot_s++]=k;
	instack[k]=1;
	dfn[k]=low[k]=index_s++;
	for(j=head[k];j!=-1;j=eage[j].next)
	{
		v=eage[j].to;
		if(instack[v])
			low[k]=min(dfn[v],low[k]);
		else
		{
			tarjan(v);
			if(ans)
				return ;
			low[k]=min(low[k],low[v]);
		}
	}
	if(dfn[k]==low[k])
	{
		do
		{
			ans++;
			instack[stack[--tot_s]]=0;
		}while(stack[tot_s]!=k);
	}
}
int main()
{
	int m,n,a,b;
	while(scanf("%d%d",&n,&m),m|n)
	{
		tot=0;
		memset(head,-1,sizeof(head));
		if(n<=1)
		{
			printf("Yes\n");
			continue;
		}
		if(m==0)
		{
			printf("No\n");
			continue;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		tot_s=0;
		index_s=1;
		memset(instack,0,sizeof(instack));
		memset(low,-1,sizeof(low));
		memset(dfn,-1,sizeof(dfn));
		ans=0;
		tarjan(1);
		if(ans==n)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
} 
