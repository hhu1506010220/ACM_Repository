#include<bits/stdc++.h>
using namespace std;

long long vis[100]={1, 8, 49, 288, 1681, 9800, 57121, 332928, 1940449, 11309768, 65918161, 384199200, 2239277041, 13051463048, 76069501249, 443365544448, 2584123765441, 15061377048200, 87784138523761, 511643454094368, 2982076586042449, 17380816062160328, 101302819786919521};

int main(){
	int t;
	scanf("%d",&t);
		int cnt=1;
		while(t--){
			long long n;
			scanf("%lld",&n);
			int nn = lower_bound(vis,vis+23,n)-vis;
			long long ans = vis[nn];
			if(ans==0)ans=-1;
			printf("Case #%d: %lld\n",cnt++,ans);
		}
	return 0;	
}
