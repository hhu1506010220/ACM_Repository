#include<bits/stdc++.h>
using namespace std;

bool judge(string s) {
	int len = s.length();
	int t1 = 0;
	int t2 = 1;
	for(int i=1; i<len; i++) {
		if(s[i]<='Z'&&s[i]>='A') {
			if(i-t1<2) {
				return 0;
			} else {
				t2++;
				t1 = i;
			}
		}
	}
	if(t2<2||t1==len-1) {
		return 0;
	} else {
		return 1;
	}
}

int main() {
	int t;
	scanf("%d",&t);
	string s;
	while(t--) {
		cin>>s;
		if(judge(s)) {
			if(s[0]<='Z'&&s[0]>='A') {
				printf("%c",s[0]-'A'+'a');
			} else {
				printf("%c",s[0]);
			}
			for(int i=1; i<s.length(); i++) {
				if(s[i]<='z'&&s[i]>='a') {
					printf("%c",s[i]);
				} else {
					printf("_%c",s[i]-'A'+'a');
				}
			}
			puts("");
		} 
		else {
			cout<<s<<endl;
		}
	}
	return 0;
}
