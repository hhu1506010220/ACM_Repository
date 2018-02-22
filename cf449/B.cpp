#include<bits/stdc++.h>
using namespace std;

long long a[100005];
int b[10];

int main(){
	int k,p,t,cnt,cntt=0;
	for(int i=1;i<=100000;i++){
		memset(b,0,sizeof(b));
		t = i;
		cnt = 0;	
		while(t){
			b[cnt++]=t%10;
			t/=10;	
		}
		long long temp = i;
		for(int j=0;j<cnt;j++){
			temp=temp*10+b[j];
		}
		a[cntt++]=temp;
	}
//	cout<<cntt<<endl;
//	for(int i=0;i<cntt;i++)cout<<a[i]<<" ";
	cin>>k>>p;
	long long res =0;
	for(int i=0;i<k;i++){
		res = (res+a[i])%p;
	}
	cout<<res<<endl;
	return 0;
}
