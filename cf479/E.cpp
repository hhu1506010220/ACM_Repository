#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int head[maxn];
int vis[maxn];
int in[maxn];
struct edge{
	ll to,next;
}edges[maxn*4];
int n,m,ans=0,cnt=0;
bool flag = 0;

void addedge(int u,int v){
	edges[cnt].to=v;
	edges[cnt].next = head[u];
	head[u]=cnt++;
	edges[cnt].to=u;
	edges[cnt].next = head[v];
	head[v]=cnt++;
	in[u]++;
	in[v]++;
}


void dfs(int s,int t,int las){
	if(in[s]!=2||in[t]!=2){
		flag = 0;
		return ;
	}
	vis[s] = 1;
	for(int i=head[s];i!=-1;i=edges[i].next){
		int to = edges[i].to;
		if(in[to]!=2)continue;
		if(to==t&&to!=las){
			flag = 1;
			return ;	
		}
        if(in[to]==2&&!vis[to]){
            dfs(to,t,s);
        }
	}
}

void solve(int i){
	flag = 0;
	dfs(i,i,-1);
	if(flag)ans++;
}

int main(){
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	int u,v;
	for(int kk=0;kk<m;kk++){
		cin>>u>>v;
		addedge(u,v);
	}
	for(int i=1;i<=n;i++){
		if(in[i]==2&&!vis[i]){
			solve(i);
		}
	}
	cout<<ans<<endl;
}
