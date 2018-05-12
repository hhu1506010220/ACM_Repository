#include<bits/stdc++.h>
using namespace std;
struct stu {
	char name[12];
	double score;
	double s[5];
} a[200005];
double maxn[5];

bool cmp(stu a,stu b) {
	if(fabs(a.score-b.score)<1e-5)
		return (strcmp(a.name,b.name)<0);
	return a.score>b.score;
}

int main() {
	int n;
	while(~scanf("%d",&n)) {
		maxn[0]=maxn[1]=maxn[2]=maxn[3]=maxn[4]=0.0;
		for(int i=0; i<n; i++) {
			memset(a[i].name,0,sizeof(a[i].name));
			scanf("%s",a[i].name);
			a[i].score = 0;
			for(int j=0; j<5; j++) {
				scanf("%lf",&a[i].s[j]);
				maxn[j] = max(maxn[j],a[i].s[j]);
			}
		}
//		for(int i=0; i<5; i++) {
//			for(int j=0; j<n; j++) {
//				maxn[i] = max(maxn[i],a[j].s[i]);
//			}
//		}
//		for(int i=0;i<5;i++)
//			cout<<maxn[i]<<endl;
		for(int i=0; i<n; i++) {
			a[i].score=a[i].s[0]*600.0/maxn[0]*0.25+
            (a[i].s[1]*300.0/maxn[1]+a[i].s[2]*300.0/maxn[2])*0.25+
            (a[i].s[3]*300.0/maxn[3]+a[i].s[4]*300.0/maxn[4])*0.5;
		}
		sort(a,a+n,cmp);
		for(int i=0; i<n; i++) {
			printf("%s %.5f\n",a[i].name,a[i].score);
		}
	}
	return 0;
}
