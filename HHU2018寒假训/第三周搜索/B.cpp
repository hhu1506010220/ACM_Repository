#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

long long e[201][201];
int k,i,j,m1,m2,m3;
int inf=10000;

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		memset(e,inf,sizeof(e));
		int a,b,x;
		for(int i=0; i<m; i++) {
			scanf("%d%d%d",&a,&b,&x);
			if(e[a][b]>x) {
				e[a][b]=x;
				e[b][a]=x;
			}
		}
		for(int i=0; i<n; i++)e[i][i]=0;
		for(k=0; k<n; k++)
			for(i=0; i<n; i++)
				for(j=0; j<n; j++) {
					if(e[i][j]>e[i][k]+e[k][j]) {
						e[i][j]=e[i][k]+e[k][j];
						e[j][i]=e[i][j];
					}
				}
		int a1,b1;
		scanf("%d%d",&a1,&b1);
		if(e[a1][b1]<inf)printf("%lld\n",e[a1][b1]);
		else printf("-1\n");
	}
	return 0;
}
