#include<bits/stdc++.h>
using namespace std;

int a[3000000+5];

int main()
{   
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
   		scanf("%d",&a[i]);
   }
   sort(a+1,a+1+n); 
   if(n%2==1)
   {
    	int num=n/2;
    	double res=a[num+1]*1.0;
    	printf("%.1f\n",res);
   }
   else
   {
   		int num=n/2;
   		double res=(a[num]+a[num+1])*1.0/2.0;
   		printf("%.1f\n",res);
   } 
	return 0;
}
