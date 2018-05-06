#include<bits/stdc++.h>
using namespace std;

int main() {
	int m, n, l, v1, v2, k;
	double ans;
	while(cin >> m) {
		while(m--) {
			double cnt;
			scanf("%d%d%d%d%d",&n,&l,&v1,&v2,&k);
			if(n % k)
				cnt = n / k + 1;
			else
				cnt = n / k;
			double ans = (1.0*l/v2) * ((2.0 * cnt - 1) * v2 + v1) / (v2 + (2.0 * cnt - 1) * v1);
			printf("%.10f\n",ans);
		}
	}
	return 0;
}
