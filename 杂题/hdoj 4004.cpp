#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int l,n,m,a[500000+5];

int find(int buchang){
	int cnt=0;
	int i=0,j=0;
	while(i<n){
		for(j=i+1;j<=n;j++){
			if(a[j]-a[i]>buchang){
				cnt++;
				break;
			}
		}
		i=j-1;
//		cout<<1<<endl;
	}
	return cnt+1;
}

int main(){
	while(~scanf("%d%d%d",&l,&n,&m)){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		a[++n]=l;
		sort(a,a+n);
		int l0=0;
		for(int i=1;i<=n;i++){
			l0=max(l0,a[i]-a[i-1]);
		}
		int left=l0,right=l;
		while(left<right){
			int mid = (left+right)/2;
			int ans = find(mid);
			if(ans>m){
				left = mid+1;
			}
			else{
				right = mid;
			}
		}
		printf("%d\n",left);
	}
	
	
}

