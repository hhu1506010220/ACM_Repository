#include <bits/stdc++.h>
int pre[100005];
int find(int x) {
	int r = x;
	while(r!=pre[r]) r = pre[r];
	int i = x,j;
	while(pre[i]!=r) {
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
int main() {
	int x,y;
	int cnt;
	while(scanf("%d",&x)==1) {
		for(int i=0; i<=100005; i++)
			pre[i] = i;
		cnt =0;
		while( x != -1) {
			scanf("%d",&y);
			x=find(x);
			y=find(y);
			if(x==y)
				cnt++;
			else
				pre[x]=y;
			scanf("%d",&x);
		}
		printf("%d\n",cnt);
	}
	return 0;
}
