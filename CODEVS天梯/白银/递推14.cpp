#include <bits/stdc++.h>
using namespace std;

int problem(int x) {
	if (x == 1)
		return 0;
	if (x % 2 == 1)
		return problem(3 * x + 1) + 1;
	else
		return problem(x / 2) + 1;
}
int main() {
	int t, i, n;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d\n", problem(n));
	}
	return 0;
}

