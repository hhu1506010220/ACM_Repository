#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
int main(){
	int t;
	scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int t1,t2;
		t1 = t2 = 1;
		for(int i=1;i<n;i++){
			if(a[i]>a[i-1]){
				t1++;
			}else{
				break;
			}
		}
		for(int i=n-1;i>0;i--){
			if(a[i-1]>a[i]){
				t2++;
			}else{
				break;
			}
		}
		if((t1+t2)==(n+1)&&t1!=n&&t2!=n){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	} 
	return 0;
} 
