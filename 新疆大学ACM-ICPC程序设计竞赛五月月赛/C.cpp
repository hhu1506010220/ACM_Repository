#include <bits/stdc++.h>
using namespace std;

const static int N = 500005;
int a1[N],a2[N],b1[N],b2[N];
int LIS1(int n) {
	int len = 0;
	for(int i = 1; i <= n; ++i) {
		int* p = upper_bound(b1 + 1, b1 + len + 1, a1[i]);
		*p = a1[i];
		len = max(len, a1[i] = p - b1);
	}
	return len;
}
int LIS2(int n) {
	int len = 0;
	for(int i = 1; i <= n; ++i) {
		int* p = upper_bound(b2 + 1, b2 + len + 1, a2[i]);
		*p = a2[i];
		len = max(len, a2[i] = p - b2);
	}
	return len;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a1[i]);
	}
	for(int i = 1; i <= n; ++i) {
		a2[i] = a1[n - i + 1];
	}
	LIS1(n),LIS2(n);
	int ans = -1;
	for(int i = 1; i <= n; ++i) {
		ans = max(ans, a1[i] + a2[n - i + 1] - 1);
	}
	printf("%d\n", ans);
	return 0;
}
