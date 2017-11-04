#include<bits/stdc++.h>
using namespace std;
#define INF 100861111  
#define ll long long  
#define eps 1e-5  
#define maxn 20  
int main()  
{  
    double x1,y1,x2,y2,x3,y3,k1,k2,d1,d2;  
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);  
    d1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);  
    d2=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);  
    if(d1!=d2)  
    {  
        printf("No\n");  
        return 0;  
    }  
    k1=(y1-y2)/(x1-x2);  
    k2=(y2-y3)/(x2-x3);  
    if(k1==k2)  
    {  
        printf("No\n");  
    }  
    else  
        printf("Yes\n");  
    return 0;  
}  
