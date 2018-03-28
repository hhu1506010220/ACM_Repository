#include<bits/stdc++.h>
using namespace std;

int v[18]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char m[12]= {'1','0','X' ,'9', '8', '7', '6', '5', '4', '3','2'};

int main() {
	int n;
	cin>>n;
	bool flagg = 1;
	while(n--){
		bool flag = 1;
		long long ans = 0;
		string s;
		cin>>s;
		for(int i=0;i<17;i++){
			if(s[i]<='9'&&s[i]>='0')
				ans += (s[i]-'0')*v[i];
			else{
				flag = 0;
				flagg = 0;
				break;	
			}
		}
		if(!flag){
			cout<<s<<endl;
			continue;
		}
		int z = ans%11;
		if(s[17]!=m[z]){
			flagg = 0;
			cout<<s<<endl;	
		}
	}
	if(flagg)puts("All passed");
	return 0;
}
