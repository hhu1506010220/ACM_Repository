#include <bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	int m,n;
	for(int i=1; i<=500000; i++)
		a[i]=1;
	for(int i=2; i<=250001; i++){
		for(int j=i+i; j<=500000; j+=i){ 
			a[j]+=i;
		}
	}
	scanf("%d",&m);
	while(m--) {
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
