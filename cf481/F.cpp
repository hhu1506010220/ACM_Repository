#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int idx[maxn];
int res[maxn];
struct node {
	int x,id;
	node(int x=0,int id=0):x(x),id(id) {}
	bool operator <(const node &a)const {
		return x==a.x?id<a.id:x<a.x;
	}
} a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n,k;
	while(cin>>n>>k) {
		for(int i=0; i<n; i++) {
			int x;
			cin>>x;
			a[i+1]=node(x,i+1);
		}
		sort(a+1,a+n+1);
		for(int i=0; i<n; i++) {
			idx[a[i+1].id]=i+1;
		}
		res[a[1].id]=0;
		for(int i=2; i<=n; i++) {
			if(a[i].x>a[i-1].x)
				res[a[i].id]=i-1;
			else res[a[i].id]=res[a[i-1].id];
		}
		while(k--) {
			int u,v;
			cin>>u>>v;
			u=idx[u];
			v=idx[v];
			if(a[u].x>a[v].x)
				res[a[u].id]--;
			if(a[v].x>a[u].x)
				res[a[v].id]--;
		}
		for(int i=1; i<=n; i++) {
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
