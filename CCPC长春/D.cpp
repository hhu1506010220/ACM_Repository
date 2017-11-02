#include<bits/stdc++.h>
using namespace std;

int a[25]={0,0,0,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0};
int gcd(int x,int y){  
    if(y==0) return x;  
    else return(gcd(y,x%y));  
}  
int main()
{
	int n;
	int t;
	scanf("%d",&t);
	int kase=  0;
	int ans = 0;
	while(t--){
		scanf("%d",&n);
		ans = 0;
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		printf("Case #%d: %d\n",++kase,ans);
	}
	return 0;
}
