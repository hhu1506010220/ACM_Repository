#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,x;
	cin>>s>>x;
	int num = 0;
	int pos = s.find(x);
	while(pos!=-1){
		num ++;	
		pos = s.find(x,pos+1);
	}
	if(num*x.length()>=s.length()){
		puts("Yes");	
	}
	else{
		puts("No");	
	}
	return 0;	
}
