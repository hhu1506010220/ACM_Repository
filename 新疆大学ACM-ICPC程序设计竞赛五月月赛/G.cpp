#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int n,m;
	double x=(1.0+sqrt(5.0));
	while(scanf("%d%d",&n,&m)!=EOF) {
		if(n>m)
			swap(n,m);
		int temp=floor((m-n)*x/2.0);
		if(temp==n) printf("Lao Wang\n");
		else printf("Xiao Ren\n");
	}
	return 0;
}
