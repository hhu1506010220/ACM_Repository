#include<bits/stdc++.h>
using namespace std;

long long f[100];

int main(){
	f[0]=1;
	f[1]=2;
	for(int i=2;i<=80;i++){
		f[i]=f[i-1]+f[i-2];	
	}
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",f[n-1]);	
	}
	return 0;
}
