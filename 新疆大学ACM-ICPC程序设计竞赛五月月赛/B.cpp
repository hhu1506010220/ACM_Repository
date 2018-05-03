#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int num[10];
int main() {
	for(int i=1; i<=9; i++)
		num[i]=i;
	int tmp;
	cin>>tmp;
	int ans=0;
	do {
		int a=0,b=0,c=0;
		for(int i=1; i<=9; i++) {
			a*=10;
			a+=num[i];
			b=0;
			for(int j=i+1; j<=9; j++) {
				b*=10;
				b+=num[j];
				c=0;
				for(int k=j+1; k<=9; k++) {
					c*=10;
					c+=num[k];
				}
				if(a*b-c==tmp)ans++;
			}
		}
	} while(next_permutation(num+1,num+10));
	cout<<ans<<endl;
}
