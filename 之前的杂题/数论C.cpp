#include<iostream>
using namespace std;

long long C(int n,int m){
	int a=1;  
    if(m==0)  
       return 1;  
    for(int i=1;i<=m;i++){  
        a=a*(n-i+1);  
        a=a/i;     
    }  
    return a;  
}

int main(){
	int i,j,n;
	long long sum,a[30];  
    a[1]=0; a[2]=1;   
    for(i=3;i<=12;i++)  
        a[i]=(i-1)*(a[i-1]+a[i-2]);//´íÅÅ¹«Ê½  
	while(~scanf("%d",&n)&&n){
		 sum=1;  
         for(i=1;i<=n/2;i++)  
             sum=sum+C(n,i)*a[i];  
         printf("%lld\n",sum);    
	}
	return 0;
} 
