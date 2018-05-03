#include<bits/stdc++.h>
using namespace std;

int a[30010],b[30010];

struct node {
	int price,du;
} q[30010];

bool cmp(node a,node b) {
	if(a.price==b.price)
		return a.du>=b.du;
	return a.price<b.price;
};

int main() {
	int t,n,m;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++) {
			scanf("%d%d",&q[i].price,&q[i].du);
		}
		sort(q,q+n,cmp);
		int maxn = q[0].du;
		for(int i=0; i<n; i++) {
			a[i]=q[i].price;
			maxn = max(maxn,q[i].du);
			b[i]=maxn;
		}
		int x;
		for(int i=0; i<m; i++) {
			scanf("%d",&x);
			int flag=upper_bound(a,a+n,x)-a;
			printf("%d\n",b[flag-1]);
		}
	}
	return 0;
}
