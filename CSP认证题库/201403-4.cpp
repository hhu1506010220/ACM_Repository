#include<bits/stdc++.h>
using namespace std;

pair<int ,int >p[205];
int mp[205][205];
int n,m,k,r;
int vis[205][205];
int dist[205][205];
int src = 0;

void spfa(){
	queue < pair <int,int> > que;
	pair<int,int> tem = make_pair(0,0),temp;
	memset(dist,0x3f3f3f3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[src][src]=0;
	vis[0][0]=1;
	while(!que.empty())que.pop();
	que.push(tem);
	while(!que.empty()){
		tem = que.front();
		que.pop();
		vis[tem.first][tem.second] = 0;
		for(int i=0;i<n+m;i++){
			if(mp[tem.first][i]){
				temp = make_pair(i,tem.second);
				if(i>=n)temp.second++;
				if(temp.second<=k&&dist[temp.first][temp.second]>dist[tem.first][tem.second]+1){
					dist[temp.first][temp.second]=dist[tem.first][tem.second]+1;  
					if(!vis[temp.first][temp.second]){  
						vis[temp.first][temp.second]=1;  
						que.push(temp);  
					}  	
								
				}
			}			
		}		
	}
}

bool isOK(pair<int,int> p1,pair<int,int> p2){
	long long l = (long long)(p1.first-p2.first)*(p1.first-p2.first)+(long long)(p1.second-p2.second)*(p1.second-p2.second);
	long long rr = (long long)r*r;
	if(l>rr)
		return false;	
	else
		return true;
}

int main(){
	memset(mp,0,sizeof(mp));
	scanf("%d%d%d%d",&n,&m,&k,&r);
	for(int i=0;i<n+m;i++){
		scanf("%d%d",&p[i].first,&p[i].second);
		for(int j=0;j<=i;j++){
			if(isOK(p[i],p[j]))
				mp[i][j] = 1, mp[j][i] = 1 ;
			else
				mp[i][j] = 0, mp[j][i] = 0 ;
		}
	}
	
	
	spfa();

	
	int ans=0x3f3f3f3f;  
    for(int i=0;i<=k;i++) ans=min(ans,dist[1][i]);  
	printf("%d\n",ans-1);	
	return 0;	
}
