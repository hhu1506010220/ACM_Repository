#include<bits/stdc++.h>
using namespace std;

int a[5];

int main(){
	for(int i=1000;i<=9999;i++){
		int temp = i;
		int cnt = 0;
		while(temp){
			a[cnt++]=temp%10;
			temp/=10;
		}
		for(int i=3;i>=0;i--)cout<<a[i];
		for(int i=0;i<4;i++)cout<<a[i];cout<<endl;
	}
	return 0;
}
