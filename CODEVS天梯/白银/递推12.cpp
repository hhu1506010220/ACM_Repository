#include<bits/stdc++.h>
using namespace std;

int a[100005]; 
int b[20];

int main(){
	int n;
	cin>>n;
	int x,y;
	memset(a,0,sizeof(a));
	a[1] = 1;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		for(int j=1;j<=100005;j++){
			if(a[j]==i){
				a[j*2] = x;
				a[j*2+1] = y;
				break;
			}
		}
	}
//	for(int i=1;i<15;i++){
//		cout<<a[i]<<" ";	
//	}
	int maxn = 0;
	for(int i=1;i<100005;i++){
		if(a[i]!=0){
			int t = log(i)/log(2);
			if(t>maxn)
				maxn = t;
			b[t]++;
		}
	}
	int mm = 0;
	for(int i=0;i<17;i++){
		mm = max(mm,b[i]);
	}
	cout<<mm<<" "<<maxn+1<<endl;
}
