#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
typedef long long ll;
typedef pair<ll,ll> pa;
set<pa> s; //set自动排序，按第一个关键字
vector<pa> g[maxn];
ll nian[maxn]; //汤圆的粘度
ll vis[maxn];

int main(){
	int t;
	cin>>t;
	int n,m;
	int x,y,z;
	while(t--){
	    memset(nian,0,sizeof(nian));
	    memset(vis,0,sizeof(vis));
		for(int i=0;i<maxn;i++) g[i].clear();
	    s.clear();
		cin>>n>>m;
		for(int i=0;i<m;i++){
			cin>>x>>y>>z;
			g[x].push_back(pa(y,z));
			g[y].push_back(pa(x,z));
			nian[x]+=z;
			nian[y]+=z;
		}
		for(int i=1;i<=n;i++){
			s.insert(pa(nian[i],i));	
		}
		
		ll ans = 0,tt,w;
		pa tem;
		set<pa>::iterator it;
		while(!s.empty()){
			it = s.begin();
			tem = *it;
			ans = max(ans,tem.first);
			s.erase(it);
			tt = tem.second;
			vis[tt] = 1;
			for(ll i=0;i<g[tt].size();i++){
				w=g[tt][i].first;
                if(vis[w]) 
					continue;
                it=s.find(pa(nian[w],w));
                s.erase(it);
                nian[w]-=g[tt][i].second;
                s.insert(pa(nian[w],w));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
