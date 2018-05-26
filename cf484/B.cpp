#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a,b) memset(a,b,sizeof(a))
#define P pair< int , int >
const int maxn = 200000+10;
const int INF = 0x3f3f3f3f3f;
struct node {
	int w;
	int id;
	bool friend operator < (const node &u,const node &v) {
		return u.w<v.w;
	}
} p[maxn];
bool cmp(const node &u,const node &v) {
	return u.w<v.w;
}
int main() {
	priority_queue<node> q;
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&p[i].w);
		p[i].id=i;
	}
	sort(p+1,p+1+n,cmp);
	char s[maxn*2];
	int t=1;
	scanf("%s",s+1);
	for(int i=1; i<=2*n; i++) {
		if(s[i]=='0') {
			printf("%d ",p[t].id);
			q.push(p[t++]);
		} else {
			printf("%d ",q.top().id);
			q.pop();
		}
	}
}
