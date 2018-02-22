#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		m=(int)(sqrt(n*1.0));
		int s=0;
		for(int i=2;i<=m;i++){
			if(n%i==0) {
				if(i*i!=n)
					s=s+i+n/i;
				else
					s+=i;
			}
		}
		printf("%d\n",s+1);
	}
	return 0;
}
