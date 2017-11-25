#include<bits/stdc++.h>
using namespace std;
const long long maxn=100000+10;
long long minn;
long long vis[maxn],c[maxn];
long long n,m;
long long head[100010],k,flag,cnt;
struct node {
	long long x,y;
	long long next;
} edge[100010];

void dfs(long long i) {
//	if(vis[i]) return;   
	for(long long j=head[i]; j!=-1; j=edge[j].next) {
		long long v=edge[j].y;
		if(!vis[v]) {
			vis[v]=1;
			minn = min(minn,c[v]);
			dfs(v);
		}
	}
}

int main() {
	k=0;
	memset(head,-1,sizeof(head));
	scanf("%lld%lld",&n,&m);
	for(long long i=1; i<=n; i++) {
		scanf("%d",&c[i]);
	}
	for(long long i=0; i<m; i++) {
		long long a,b;
		scanf("%lld%lld",&a,&b);
		edge[k].x=a;
		edge[k].y=b;
		edge[k].next=head[a];      //½¨xµ½yµÄ±ß¡£
		head[a]=k++;
	}

	long long cnt=0;
	long long sum = 0;
	for(long long i=1; i<=n; i++) {
		minn = c[i];
		if(!vis[i]) {
			vis[i]=1;
			dfs(i);
			sum+=minn;
		}
	}
	printf("%lld\n",sum);
	return 0;
}
