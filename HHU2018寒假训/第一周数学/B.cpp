#include<cstdio>

int main(){
	int k=1;
	int t;
	scanf("%d",&t);
	while(t--){
		long long n,m;
		scanf("%lld%lld",&n,&m);
		long long sum=m*n/2;
		printf("Case %d: ",k++);
		printf("%lld\n",sum);
	}
	return 0;
}
