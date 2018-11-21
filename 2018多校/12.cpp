#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
    int n,minn,maxn,tem;
	while(t--){ 
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d",&tem);
            if(i==0) minn=tem;
            if(i==n-1) maxn=tem;
        }
        printf("%d\n",(int)sqrt(abs(minn-maxn)+0.5));
	}
	return 0;
}
