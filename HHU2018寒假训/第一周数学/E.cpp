#include<cstdio>
int mod_pow(int x, int n,int mod){
	int res = 1;
	while(n > 0) {
		if(n & 1)res = res*x% mod;
		x = x*x%mod;
		n >>= 1;
	}
	return res;
}
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF&&n&&m)
		printf("%d\n",mod_pow(m,n,1000));
	return 0;
}
