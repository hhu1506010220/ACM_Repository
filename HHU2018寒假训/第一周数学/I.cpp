#include<cstdio>

int main() {
	int t;
	long long B,n,x;
	scanf("%d",&t);
	for(int i=0; i<t; i++) {
		scanf("%lld%lld",&n,&B);
		for(int i=1; i<=9972; i++) {
			x=B*i-n;
			if(x%9973==0) {
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
