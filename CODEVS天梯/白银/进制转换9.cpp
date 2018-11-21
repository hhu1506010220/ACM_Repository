#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	char a[105];
	cin>>a;
	ll m;
	cin>>m;
	ll sum = 0;
	ll cnt = 1;
	for(int i=strlen(a)-1;i>=0;i--){
		if(a[i]>='0'&&a[i]<='9')
			sum += (a[i]-'0')*cnt; 
		else if(a[i]>='A'&&a[i]<='F'){
			sum += (a[i]-'A'+10)*cnt;
		}
		cnt *= m;
	}
	cout<<sum<<endl;
	return 0; 
}
