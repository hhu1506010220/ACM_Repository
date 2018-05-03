#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100005;
const ll mod = 1e9+7;
const ll INF = 1e18;
vector<ll> v[5];
ll T, n, m, k;
ll ans;

void dfs(ll pos, ll now_route, ll res) {
	if(now_route == -1)
		ans = min(ans, res);
	ll y = lower_bound(v[now_route].begin(), v[now_route].end(), pos) - v[now_route].begin();
	if(y != 0)
		dfs(v[now_route][y - 1], now_route-1, res + abs(v[now_route][y-1]-pos));
	if(y != v[now_route].size())
		dfs(v[now_route][y], now_route-1, res + abs(v[now_route][y]-pos));
}

int main() {
	scanf("%lld", &T);
	while(T--) {
		ll t;
		scanf("%lld %lld %lld", &n, &m, &k);
		for(ll i = 0; i < 5; i++) v[i].clear();
		for(ll i = 0; i < n; i++) {
			scanf("%lld", &t);
			v[0].push_back(t);
		}
		for(ll i = 0; i < m; i++) {
			scanf("%lld", &t);
			v[1].push_back(t);
		}
		for(ll i = 0; i < k; i++) {
			scanf("%lld", &t);
			v[2].push_back(t);
		}
		ans = INF;
		for(ll i = 0; i < k; i++) {
			dfs(v[2][i], 1, 0);
		}
		printf("%lld\n", ans + 3);
	}
	return 0;
}
