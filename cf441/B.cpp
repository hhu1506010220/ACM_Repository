#include<bits/stdc++.h>
using namespace std;

int aa[100005],a[100005];

int main(){
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&aa[i]);
		a[i]=aa[i]%m;
	}
	sort(a,a+n);
	int cnt =1;
	int tem =0;
	bool flag = 0;
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			cnt++;
			if(cnt>=k){
				tem=a[i];
				flag=1;
				puts("Yes");
				break;	
			}
		}
		else cnt=1;
	}
	int cntt=0;
	if(flag){
		for(int i=0;i<n;i++){
			if(aa[i]%m==tem){
				cntt++;
				if(cntt<k)
					printf("%d ",aa[i]);
				else{
					printf("%d\n",aa[i]);
					break;
				}
			}
		}
	}
	else{
		puts("No");	
	}
}
