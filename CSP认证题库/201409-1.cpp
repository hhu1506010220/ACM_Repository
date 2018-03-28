#include<bits/stdc++.h>
using namespace std;

int a[10005];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int cnt =0;
	for(int i=0;i<n-1;i++){
		if(a[i+1]-a[i]==1){
			cnt++;	
		}
	}
	cout<<cnt<<endl;
	return 0;
}
