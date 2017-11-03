#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		while(n--){
				int a,b;
		cin>>a>>b;
		cout<<max(a+2*b,a*2+b)<<endl;	
			
		}

	}
	return 0;
}
