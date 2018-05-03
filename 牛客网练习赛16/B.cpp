#include<bits/stdc++.h>
using namespace std;

int a[100005];
map<int,int>m;


int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	for(int i=1;i<=(n+1)/2;i++){
		a[i] -= i;
		m[a[i]]++;
	}
	for(int i=n;i>(n+1)/2;i--){
		a[i] -= (n-i+1);	
		m[a[i]]++;
	}
	int num=0;
	for(auto i=m.begin();i!=m.end();i++) num=max(num,i->second);
	cout<<n-num<<endl;

	return 0;
}
