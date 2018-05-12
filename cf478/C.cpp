#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
ll sum[Max];
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld\n", &sum[i]);
        sum[i] += sum[i - 1];
    }
    ll k, cur = sum[0], pow = 0;
    while (q--) {
        scanf("%lld", &k);
        pow += k;
        if (pow >= sum[n]) {
            printf("%d\n", n);
            pow = 0;
            cur = 0;
            continue;
        }
        int cur = lower_bound(sum + 1, sum + n + 1, pow) - (sum);
        cur = sum[cur] - pow;
        if (cur == 0) {
            printf("%d\n", n - cur);
        }
        else {
            printf("%d\n", n - cur + 1);
        }
    }
    return 0;
}
