#include<bits/stdc++.h>
using namespace std;

int a[120005];

int main(){
	int sum = 1;
	int tol = 0;
	int pp  = 0;
	for(int i=0;i<120000&&sum<=100000000;i++){
		tol+=sum;
		a[i]=tol;
		sum++;	
		pp = i;
	}
	pp++;
	int n;
	cin>>n;
	if(n==1){
		cout<<"1/1"<<endl;
		return 0;	
	}
	int pos = lower_bound(a,a+pp,n)-a;
	pos --;
	int start = 0,_end = 0;
	if(pos%2==1){
		start = pos + 2 ;
		_end = 1;
		int lef = n - (a[pos] + 1);
		for(int i=0;i<lef;i++){
			start --;
			_end ++;
		}
	}
	else{
		start = 1;
		_end = pos + 2;
		int lef = n - (a[pos] + 1);
		for(int i=0;i<lef;i++){
			start ++;
			_end --;
		}		
	}
	cout<<start<<"/"<<_end<<endl;
	return 0;
}
