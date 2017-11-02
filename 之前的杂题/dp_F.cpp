#include<iostream>
#include<cstdio>
using namespace std;

  
int d[1000005],c[25],n,i,j;  
int main()  
{  
    scanf("%d",&n);  
    c[0]=d[0]=1;  
    for(i=1;i<=20;i++)  
        c[i]=c[i-1]<<1;  
    for(i=0;i<=20&&c[i]<=n;i++)  
        for(j=c[i];j<=n;j++)  
            d[j]=(d[j]+d[j-c[i]])%1000000000;  
    printf("%d\n",d[n]);          
}  
