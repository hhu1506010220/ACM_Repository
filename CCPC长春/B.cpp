#include<bits/stdc++.h>
using namespace std;

int a[15],b[15];
int gcd(int x,int y){  
    if(y==0) return x;  
    else return(gcd(y,x%y));  
}  
int main()
{
	int t,cnn = 0,p,q;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		q = a[n],p=b[n];
		for(int i=n-1;i>0;i--){
			p = a[i]*q+p;
			q = b[i]*q;
//			cout<<p<<" "<<q<<endl;
			int t = p;
			p = q;
			q = t;
		}
		int t = gcd(p,q);
		printf("Case #%d: %d %d\n",++cnn,p/t,q/t);
	}
	return 0;
}
