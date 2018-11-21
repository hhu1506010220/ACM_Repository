#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[105];
	int cnt = 0;
	while(n){
		a[cnt++] = n%m;
		n/=m;
	}
	for(int i=cnt-1;i>=0;i--){
		if(a[i]<10)cout<<a[i];
		else{
			if(a[i]==10)cout<<'A';
			else if(a[i]==11)cout<<'B';
			else if(a[i]==12)cout<<'C';
			else if(a[i]==13)cout<<'D';
			else if(a[i]==14)cout<<'E';
			else if(a[i]==15)cout<<'F';	
		}
	}cout<<endl;
	return 0;
}
