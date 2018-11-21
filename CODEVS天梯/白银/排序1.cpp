#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[105];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int* las = unique(a,a+n);
	cout<<las-a<<endl;
	for(int i=0;i<las-a-1;i++)
		cout<<a[i]<<" ";
	cout<<a[las-a-1]<<endl;
	return 0;
}
