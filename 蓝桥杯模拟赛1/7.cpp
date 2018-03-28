#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    double c,a0,an1;
    scanf("%d",&n);
    scanf("%lf %lf",&a0,&an1);
    double ans=0;
 	double t = 0;
    ans=an1+n*a0;
    for(int i=1;i<=n;i++){
        scanf("%lf",&c);
        t+=c*(n-i+1)*2;
    }
    ans-=t;
    ans/=(n+1);
    printf("%.2lf\n",ans);
    return 0;
}
