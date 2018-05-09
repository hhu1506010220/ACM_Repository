#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
char a[maxn];
int t[maxn];
int main(){
	//cout<<strcmp("hello","world")<<endl;
	int tt;
	scanf("%d",&tt);
	int n;
	long long sum;
	while(tt--){
		scanf("%d",&n);
		getchar();
		scanf("%s",a+1);
		for(int i=1;i<=n;i++){
			
			t[i] = -1;
		}
		sum = n;
		sum = (sum+1)*sum/2;
		if(sum%2!=0){
			printf("-1\n");
		}else{
			sum /= 2;
			for(int i=n;i>0;i--){
				if(sum>=i){
					sum -= i;
					//cout<<a[i]<<endl;
					if(a[i]=='1'){
						t[i] = 4;
					}else{
						t[i] = 2;
					}
				}
			}
			if(sum!=0){
				if(a[sum]=='1'){
					t[sum] = 4;
				}else{
					t[sum] = 2;
				}
			}
			for(int i=1;i<=n;i++){
				if(t[i]==-1){
					//cout<<a[i]<<endl;
					if(a[i]=='1'){
						t[i] = 3;
					}else{
						t[i] = 1;
					}
				}
			}
			for(int i=1;i<=n;i++){
				printf("%d",t[i]);
			}
			printf("\n"); 
		}
	} 
	return 0;
} 
