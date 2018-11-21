#include<bits/stdc++.h>
using namespace std;

int a[50005];
int sum[50005];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	sum[0] = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i] = sum[i-1] + a[i];
	}
	double maxn = 0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j-i+1>=k)
			maxn = max(maxn,(sum[j]-sum[i-1])*1.0/(j-i+1)*1.0);
		}
	}
	printf("%.7f",maxn);
	return 0;
}
