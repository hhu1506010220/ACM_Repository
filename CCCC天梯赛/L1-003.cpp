#include <bits/stdc++.h>
using namespace std;
int c[10];
char s[1005];
int main() {
	cin>>s;
	int i,k,l=strlen(s);
	for(k=0; k<l; ++k)
		c[s[k]-'0']++;
	for(i=0; i<10; ++i) {
		if(c[i])
			cout<<i<<":"<<c[i]<<endl;
	}
	return 0;
}
