#include<bits/stdc++.h>
using namespace std;

int a[10],b[10];

int main(){
	int n,m;
	int min1=9999,min2=9999;
	int temp;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&temp); 
		if(temp<min1){
			min1=temp;
		}
		a[temp]++;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&temp); 
		if(temp<min2){
			min2=temp;
		}
		b[temp]++;
	}
	for(int i=1;i<10;i++){
		if(a[i]>=1&&b[i]>=1){
			cout<<i<<endl;
			return 0;	
		}
	}

	cout<<min(min1,min2)<<max(min1,min2)<<endl;
	return 0;
}
