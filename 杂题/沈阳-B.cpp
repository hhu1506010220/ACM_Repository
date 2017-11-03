#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n ;
	while(~scanf("%d",&n)){
		while(n--){
			char s[15];
			cin>>s;
			int sum =0;
			int len = strlen(s);
			for(int i=0;i<len;i++){
				if(s[i]=='H')sum+=1;
				else if(s[i]=='C')sum+=12;
				else sum+=16;	
			}
			cout<<sum<<endl;
		}
		
	}
	
	
	return 0;	
}
