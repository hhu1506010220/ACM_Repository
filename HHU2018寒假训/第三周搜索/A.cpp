#include<bits/stdc++.h>
using namespace std;

int pr[100005][2];
int ans[100005];
int vis[10005];
int pre[100005];
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
	int n,m,cnt;
	int x,y;
	while(~scanf("%d%d",&n,&m)){ 
		cnt = n;
		memset(pr,0,sizeof(pr));
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++)pre[i]=i;
		for(int i=0;i<m;i++){
			scanf("%d%d",&pr[i][0],&pr[i][1]);
		}
		for(int i=m-1;i>=0;i--){
			ans[i] = cnt;
			if(find(pr[i][0])!=find(pr[i][1]))
				cnt--;
			merge(pr[i][0],pr[i][1]);
		}
	    for(int i=0; i<m; i++) {  
            printf("%d\n",ans[i]);  
        }  
	}
	return 0;
}
