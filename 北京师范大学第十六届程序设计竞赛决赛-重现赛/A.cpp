#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag = 1;
		string s;
		while(n--){
			cin>>s;
			if(s!="PERFECT"){
				flag = 0;	
			}
		}
		if(flag){
			puts("MILLION Master");
		}
		else{
			puts("NAIVE Noob");
		}
	}
	return 0;
}
