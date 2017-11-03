#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000005],b[1000005];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int l,n;
		cin>>l>>n;
		int maxn=0,minn=99999999;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			a[i]=max(temp,l-temp);
			b[i]=min(temp,l-temp);					
		}
		sort(a,a+n);
		sort(b,b+n);
		cout<<b[n-1]<<" "<<a[n-1]<<endl; 
	} 
	return 0;
} 
