#include<cstdio>

int eular(int x){
	int ans=x;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			ans-=ans/i;
			while(x%i==0){
				x/=i;
			}
		}
	}
	if(x>1)
		ans-=ans/x;
	return ans;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		printf("%d\n",n-eular(n)-1);
	}
	return 0; 
}
