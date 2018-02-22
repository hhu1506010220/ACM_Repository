#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
long long fast_mod(long long n) {
	long long t[2][2] = {1, 1, 1, 0};
	long long ans[2][2] = {1, 0, 0, 1};
	long long tmp[2][2];
	while(n) {
		if(n & 1) {
			for(long long i = 0; i < 2; ++i)
				for(long long j = 0; j < 2; ++j)
					tmp[i][j] = ans[i][j];
			ans[0][0] = ans[1][1] = ans[0][1] = ans[1][0] = 0;

			for(long long i = 0; i < 2; ++i) {
				for(long long j = 0; j < 2; ++j) {
					for(long long k = 0; k < 2; ++k)
						ans[i][j] = (ans[i][j] + tmp[i][k] * t[k][j]) % MOD;
				}
			}
		}
		for(long long i = 0; i < 2; ++i)
			for(long long j = 0; j < 2; ++j)
				tmp[i][j] = t[i][j];
		t[0][0] = t[1][1] = 0;
		t[0][1] = t[1][0] = 0;
		for(long long i = 0; i < 2; ++i) {
			for(long long j = 0; j < 2; ++j) {
				for(long long k = 0; k < 2; ++k)
					t[i][j] = (t[i][j] + tmp[i][k] * tmp[k][j]) % MOD;
			}
		}
		n >>= 1;
	}
	return ans[0][1];
}

int main() {
	int t;
	ll n ;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		printf("%lld\n",fast_mod(n+1));
	}
	return 0;
}
