#include <bits/stdc++.h>
using namespace std;
int num[105][105];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int main() {
	int t;
	scanf("%d",&t);
	int x1,x2,y1,y2;
	while(t--) {
		int n;
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		for(int i=0; i<n; i++) {
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(int i=x1; i<x2; i++) {
				for(int j=y1; j<y2; j++) {
					num[i][j]++;
				}
			}
		}
		int maxx = 0;
		for(int i=0; i<=100; i++) {
			for(int j=0; j<=100; j++) {

				if(maxx<num[i][j]) {
					maxx = num[i][j];
				}
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}
