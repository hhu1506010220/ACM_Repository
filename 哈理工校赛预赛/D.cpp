#include<bits/stdc++.h>
using namespace std;
vector<int>vec[10005];
int a[10005],b[10005],vis[10005],dp[10005];

void dfs(int x){
    for(int i=0;i<vec[x].size();i++){
        if(vis[vec[x][i]]==0){
            vis[vec[x][i]]=1;
            dfs(vec[x][i]); 
        }
    }
}

int main(){
	int t,n,m,c,x,y;
	scanf("%d",&t);
	while(t--){
//		cout<<"sdasd"<<endl;
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		scanf("%d%d%d",&n,&m,&c);
		for(int i=0;i<=n;i++)vec[i].clear(); 
		for(int i=2;i<=n;i++){
			scanf("%d%d",&a[i],&b[i]);	
		}
//		cout<<"asa"<<endl;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);	
		}
		dfs(1);
        for(int i=2;i<=n;i++){
            if(vis[i]==1){
                for(int j=c;j>=a[i];j--){
                    dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
                }
            }
        }
        printf("%d\n",dp[c]);
	}
	return 0;
}
