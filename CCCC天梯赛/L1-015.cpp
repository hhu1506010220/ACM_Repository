#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	char c;
	cin>>n>>c;
	int Line=0;
	if(n%2==0)
		Line=n/2;
	else Line=n/2+1;
	int t=1;
	for(int i=0; i<Line; i++)
		for(int j=0; j<n; j++) {
			cout<<c;
			if(t%n==0)
				cout<<endl;
			t++;
		}
	return 0;
}
