#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%lld",&n);
	long long x,l,r,t1,t2;
	while(n--){
		scanf("%lld%lld%lld",&x,&l,&r);
		t1=t2=0;
		t1=x/l; 
		t2=x%l;
		if(t2<=(r-l)*t1)puts("QWQ");
		else puts("TAT");	
	}
	return 0;
}
