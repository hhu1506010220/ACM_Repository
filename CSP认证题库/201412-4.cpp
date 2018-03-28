#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int INF=1<<30;
struct edge {
	int fr,to,w,nxt;
	bool operator < (const edge &a) const {
		return w<a.w;
	}
};
int pre[N],n,head[N],cnt,m;
edge e[N*(N-1)+5];
void add(int fr,int to,int w) {
	e[cnt].fr=fr;
	e[cnt].to=to;
	e[cnt].w=w;
	e[cnt].nxt=head[fr];
	head[fr]=cnt++;
}
int fin(int x) {
	if(x==pre[x])
		return x;
	return pre[x]=fin(pre[x]);
}
void Kruskal() {
	for(int i=1; i<=n; ++i)
		pre[i]=i;
	sort(e,e+cnt);
	int ans=0;
	for(int i=0; i<cnt; ++i) {
		int u=fin(e[i].fr);
		int v=fin(e[i].to);
		if(u!=v) {
			ans+=e[i].w;
			pre[u]=v;
		}
	}
	printf("%d\n",ans);
}
int main() {
	int a,b,c;
	scanf("%d%d",&n,&m);
	cnt=0;
	memset(head,-1,sizeof(head));
	while(m--) {
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	Kruskal();
	return 0;
}
