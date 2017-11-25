#include<bits/stdc++.h>
using namespace std;
int a[4];

int main(){
	int n,tem;
	scanf("%d",&n);
	int cnt =0,temp;
	memset(a,0,sizeof(a));
	int res;
	bool flag = 1;
	a[1]=a[2]=1;
	for(int i=0;i<n;i++){
//		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
		scanf("%d",&tem);
		if(!a[tem]){
			flag = 0;
			puts("NO");
			return 0;
		}
		for(int j=1;j<=3;j++){
			if(a[j]&&j!=tem){
				res = j;
				a[j]=0;	
			}
		}
		for(int j=1;j<=3;j++){
			if(!a[j]&&j!=res)
				a[j]=1;	
		}
	}
	if(flag)puts("YES");
	return 0;
}
