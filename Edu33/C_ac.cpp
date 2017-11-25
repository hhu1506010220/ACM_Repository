#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mn = 1e6+5;

ll c[mn], mini;
vector<int> a[mn];
bool seen[mn];

void dfs(int u) {
	mini = min(mini, c[u]);
	seen[u] = 1;
	for(int i = 0; i < a[u].size(); i += 1) {
		if(!seen[a[u][i]])
			dfs(a[u][i]);
	}
}

int main()
{
	int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i += 1) cin >> c[i];
    int u, v;
    while(q--) {
    	cin >> u >> v;
    	a[u].push_back(v);
    	a[v].push_back(u);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i += 1) {
		mini = c[i];
		if(!seen[i]) {
			dfs(i);
			ans += mini;
		}
	}
	cout << ans;
    
    return 0;
}

