#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int cnt =0;
	int sum =0;
	for(int i=a;i<=b;i++){
		sum+=i;
		printf("%5d",i);
		cnt++;
		if(i==b&&cnt!=5)puts("");
		if(cnt==5)cnt=0,printf("\n");
	}
	printf("Sum = %d\n",sum);
	return 0;
}
