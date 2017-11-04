#include<bits/stdc++.h>
using namespace std;

bool f(const int m,const int n) {
	int d1,d2,d3=1;
	if(m<=n) {
		d1=m;
		d2=n;
	} else {
		d1=n;
		d2=m;
	}
	while(d3!=0) {
		d3=d2%d1;
		d2=d1;
		d1=d3;
	}

	if(d2==1)return 1;
	else return 0;

}

int main() {
	int n;
	while(cin>>n) {
		int fenzi;
		for(int i=1; i<=n; i++) {
			fenzi = n-i;
			if(fenzi%i==0)continue;
			if(f(fenzi,i)&&fenzi<i) {
				cout<<fenzi<<" "<<i<<endl;
				break;
			}
		}

	}
	return 0;
}
