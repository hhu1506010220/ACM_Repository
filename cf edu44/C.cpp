#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
	int n,k,l;
	cin>>n>>k>>l;
	int tol = n*k;
	for(int i=0;i<tol;i++){
		cin>>a[i];	
	}
	long long sum = 0;
	sort(a,a+tol);
	int minn = a[0];
	if(a[0]+l>=a[tol-k]){
		for(int i=tol-k;i>=0;i-=k){
			sum+=1ll*a[i];
		}	
	}
	else{
		int pos;
		for(pos=1;;pos++){
			if(a[pos]>a[0]+l)
				break;	
		}
		pos--;
		for(int i=tol-k;i>=0;i-=k){
			if(a[0]+l>=a[i]){
				break;
			}
			else{
				int tem = a[pos];
				a[pos] = a[i];
				a[i] = tem;
				pos--;	
			}
		}
		for(int i=tol-k;i>=0;i-=k){
			sum+=1ll*a[i];
		}
	}
	int maxn = 0;
	for(int i=tol-k;i>=0;i-=k){
		maxn = max(maxn,a[i]);
	}
	if(maxn-minn>l){
		puts("0");
		return 0;	
	}
//	for(int i=0;i<tol;i++)cout<<a[i]<<" ";cout<<endl;
	cout<<sum<<endl;
	return 0;
}
