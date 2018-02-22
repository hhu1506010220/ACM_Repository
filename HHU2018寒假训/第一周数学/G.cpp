#include<cstdio>  
  
int main(){  
    int n,a,b;  
    while(scanf("%d",&n)!=EOF){  
        a=n/2;  
        b=n-a;  
        printf("%d\n",a*(a-1)/2+b*(b-1)/2);  
    }  
    return 0;  
}  
