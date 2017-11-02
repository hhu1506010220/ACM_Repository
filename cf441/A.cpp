#include<bits/stdc++.h>
using namespace std;

int a[4];

int main(){
	int n;
	scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
	int aa=a[0],b=a[1],c=a[2];
	sort(a,a+3);
	if(a[0]==aa||a[0]==b){
		printf("%d\n",(n-1)*a[0]);
		return 0;
	}
	if(n==1)printf("0\n");
	else{
		int n1 = min(aa,b);
		printf("%d\n",(n-2)*a[0]+n1);
	}
	return 0;	
}
