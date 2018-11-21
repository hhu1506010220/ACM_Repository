#include<bits/stdc++.h>
using namespace std;
const int maxn=3000001;
int n;
struct node {
	int a,b;
} x[200];

int cmp(node x,node y) {
	return x.b<y.b;
}

int main() {
	int ans=1;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) {
		scanf("%d%d",&x[i].a,&x[i].b);
		if(x[i].a>x[i].b) swap(x[i].a,x[i].b);
	}
	sort(x+1,x+n+1,cmp);
	int maxl=x[1].b;
	for(int i=2; i<=n; ++i) {
		if(x[i].a>=maxl) {
			maxl=x[i].b;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
