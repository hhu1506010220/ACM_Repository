#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int INF = 0x3f3f3f3f;
int w[maxn], v[maxn];
int dp[5500];
int main() {
	int T, n, B;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&B);
		int V = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d",&w[i],&v[i]);
			V += v[i];
		}
		memset(dp,INF,sizeof(dp));
		dp[0] = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = V; j >= v[i]; j--) {
				dp[j] = min(dp[j],dp[j-v[i]]+w[i]);
			}
		}
		int ans = 0;
		for(int i = V; i >= 0; i--) {
			if(dp[i] <= B) {
				ans = i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
