#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int num=0;
	char s[105];
	cin>>s;
	for(int i=0; i<n; i++) {
		if(s[i]=='x'&&s[i+1]=='x') {
			while(s[i+2]=='x') {
				num++;
				int j;
				for( j=i+2; j<n-1; j++) {
					s[j]=s[j+1];
				}
				s[j]='\0';
			}
		}

	}
	cout<<num<<endl;
	return 0;
}
