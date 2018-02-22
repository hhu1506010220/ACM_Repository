#include<bits/stdc++.h>
using namespace std;

int a[1005];
int vis[1005];
int cnt[10050];
int pre[1005];
int find(int x) {
	int r = x;
	while(r!=pre[r]) r = pre[r];
	int i = x,j;
	while(pre[i]!=r) {
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
void merge(int x,int y){
	int fx = find(x);
	int fy = find(y);	
	if(fx!=fy)
		pre[fy]=fx;
}

int main(){
	int t;
	int casee = 1;
	int n,m,ans;
	int x,y;
	scanf("%d",&t);
	while(t--){
		ans = 0;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)pre[i]=i;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			merge(x,y);	
		}
		for(int i=1;i<=n;i++){
			cnt[find(i)]+=a[i];
			if(!vis[find(i)]){
				ans++;		
				vis[find(i)]=1;	
			}
		}
		sort(cnt+1,cnt+n+1);
		printf("Case %d: %d\n",casee++,ans);
		for(int i=n-ans+1;i<n;i++)printf("%d ",cnt[i]);
		printf("%d\n",cnt[n]);
	}
	return 0;
}
