#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,x;
	cin>>a>>b>>x;
	string s = "";
	string q = "";
	string h = "";
	string ans = "";
	if(x%2==0){
		for(int i=0;i<x/2;i++){
			s += "1";
			s += "0";	
		}
		for(int i=0;i<b-x/2;i++)
			q +="1";
		for(int i=0;i<a-x/2;i++)
			h +="0";
		if(x/2==b){
			h="";
			for(int i=0;i<a-x/2-1;i++)
				h +="0";
			ans +="0";
			ans +=q;
			ans +=s;
			ans +=h;
		}
		else if(x/2==a){
			ans +=s;
			ans +=q;
		}
		else{
			ans +=s;
			ans +=h;
			ans +=q;
		}
	}
	else{
		for(int i=0;i<(x+1)/2;i++){
			s += "1";
			s += "0";	
		}
		for(int i=0;i<b-(x+1)/2;i++)
			q +="1";
		for(int i=0;i<a-(x+1)/2;i++)
			h +="0";
		ans +=q;
		ans +=s;
		ans +=h;
	}
	cout<<ans<<endl;
	return 0; 
}	
