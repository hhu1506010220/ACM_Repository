#include<bits/stdc++.h>
using namespace std;

int pre[1005];
int vis[1005];

int find(int x){
	int r = x;
	while(r!=pre[r]) r = pre[r];	
	int i = x,j;
	while(pre[i]!=r){
		j = pre[i];
		pre[i] = r;
		i = j;	
	}
	return r;
}
void merge(int x,int y){
	int fx = find(x),fy = find(y);	
	if(fx!=fy) pre[fy]=fx;
}

int main(){
	int n , m;
	int _a,_b;
	int cnt ;
	while(~scanf("%d%d",&n,&m)&&n){
		cnt = 0;
		memset(pre,0,sizeof(pre));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			pre[i] = i;
		for(int i=0;i<m;i++){
			scanf("%d%d",&_a,&_b);
			merge(_a,_b);
		}
		for(int i=1;i<=n;i++){
//			vis[find(i)]=1;
			cout<<pre[i]<<endl;
		}
		for(int i=1;i<=n;i++){
			if(vis[i])
				cnt++;	
		}
		printf("%d\n",cnt-1);
	}
	return 0;	
}
