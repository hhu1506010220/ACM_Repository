#include<bits/stdc++.h>
using namespace std;

char a[7] = {'a','e','i','o','u','y'};

int main(){
	string s;
	while(cin>>s){
		for(int i=0;i<s.length();i++){
			for(int j=5;j>=0;j--){
				if(s[i]>=a[j]){
					s[i] = a[j];
					break;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
