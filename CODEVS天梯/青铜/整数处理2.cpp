#include<iostream>
using namespace std;

int main() {
	long int a[100];
	int n;
	long int sum=0;
	cin>>n;
	for(int m=0; m<n; m++) {
		cin>>a[m];
	}
	for(int q=0; q<n; q++) {
		sum+=a[q];
	}
	cout<<sum<<endl;
	return 0;
}
