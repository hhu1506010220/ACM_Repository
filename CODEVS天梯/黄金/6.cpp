#include<bits/stdc++.h>
using namespace std;

int a[20005]; 
int v[31];

int main(){
	int V,n;
	cin>>V>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<n;i++){
		for(int j=V;j>=v[i];j--){
			a[j] = max(a[j],a[j-v[i]]+v[i]);
		}
	}
	cout<<V-a[V]<<endl;
	return 0;
}
