#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[4];
int main(){
	int n;
	while(cin>>n){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		b[1]=b[2]=1;
		bool flag = 1; 
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(b[a[i]]==0)
				flag = 0;
			for(int j=1;j<=3;j++){
				if(j==a[i])continue;
				else{
					b[j] = 1-b[j];	
				}
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}
