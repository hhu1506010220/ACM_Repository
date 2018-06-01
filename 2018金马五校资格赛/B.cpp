#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
char s[maxn];
long long cnt[30];

int main() {
	int n;
	while(scanf("%d", &n) !=EOF) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%s",s);
		int n = strlen(s);
		for(int i = 0; i < n; i ++) {
			cnt[s[i] - 'a'] ++;
		}

		long long ans = 0;
		for(int i = 0; i < 30 ; i ++) {
			ans = max(ans, cnt[i]);
		}

		printf("%lld\n",ans);
	}
	return 0;
}

