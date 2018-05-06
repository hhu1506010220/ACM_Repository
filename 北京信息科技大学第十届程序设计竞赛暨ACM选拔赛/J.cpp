#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,k,x,y;
	scanf("%d",&t);
	while(t--) {
		double s,v1,v2,v3;
		scanf("%lf%lf%lf",&s,&v1,&v2);
		if(s==0) {
			printf("0.0000000000\n");
			continue;
		}
		if(v1<=0||v1<=v2) {
			printf("Infinity\n");
			continue;
		}
		double ans=s/(v1-v2*v2/v1);
		printf("%.10f\n",ans);
	}
	return 0;
}
