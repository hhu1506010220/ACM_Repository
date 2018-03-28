#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 505
using namespace std;

int a[maxn],dis[maxn],vis[maxn],sum[maxn],path[maxn],num[maxn],step[maxn];
int mp[maxn][maxn];
int n,m,s,d;

void dijstra(int x) {
	int i,j;
	for(int i=0; i<n; i++)
		dis[i]=inf;

	vis[x] = 1;
	dis[x] = 0;
	sum[x] = a[x];
	num[x] = 1;
	

	for(int i=0; i<n; i++) {
		if(mp[i][s]!=inf&&i!=s) {
			dis[i] = mp[i][s];
			sum[i] = a[s]+a[i];
			num[i] = 1;
			path [i] = s;
		}
	}
	int temp_max,temp_pos;
	for(int i=0; i<n-1; i++) {
		temp_max = inf;
		temp_pos = 0;
		for(int j=0; j<n; j++) {
			if(!vis[j] && dis[j] < temp_max){
				temp_max = dis[j];
				temp_pos = j;
			}
		}
		vis[temp_pos] = 1;
		for(int j=0;j<n;j++){
			if(!vis[j]&&dis[j]>dis[temp_pos]+mp[temp_pos][j]){
				dis[j] = dis[temp_pos]+mp[temp_pos][j];
				num[j] = num[temp_pos];
				path[j] = temp_pos;
				sum[j] = sum[temp_pos]+a[j];		
			}
			else if(!vis[j]&&dis[j]==dis[temp_pos]+mp[temp_pos][j]){
				num[j] += num[temp_pos];
				if(sum[j]<sum[temp_pos]+a[j]){
					sum[j] = sum[temp_pos]+a[j];
					path[j] = temp_pos;	
				}
			}
		}
	}
	return ;
}

int main() {
	int u,v,w;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mp[i][j] = inf;
	for(int i=0; i<m; i++) {
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v] = w;
		mp[v][u] = w;
	}
	dijstra(s);
	printf("%d %d\n",num[d],sum[d]);
	int now,cnt=0;
	now = d;
	while(now!=s){
		step[cnt++] = now;
		now = path[now];
	}
	printf("%d",s);
	for(int i = cnt-1;i>=0;i--)
		printf(" %d",step[i]);
	puts("");
	return 0;
}
