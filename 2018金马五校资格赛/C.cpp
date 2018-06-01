#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
long long fi[maxn];

int main() {
	int n, p;
	while(scanf("%d %d", &n, &p) != EOF) {
		fi[1] = 1;
		fi[2] = 2;
		for(int i = 3; i <= n ; i ++) {
			fi[i] = (fi[i-1] + fi[i-2]) % p;

		}
		printf("%lld\n",fi[n]);

	}
	return 0;
}

