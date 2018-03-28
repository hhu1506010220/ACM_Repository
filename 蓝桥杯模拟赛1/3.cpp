#include<bits/stdc++.h>
using namespace std;

long long s;
int aa[10]={1,2,3,4,5,6,7,8,9,10};

int f(int a,char b,int c){
	if(b=='+')
		return a+c;
	if(b=='-')
		return a-c;	
	if(b=='*')
		return a*c;
}

void dfs(int a,char b,int c,int step){
	if(step==10){
		if(f(a,b,c)==0){
			s++;
		}
		return ;	
	}
	dfs(f(a,b,c),'+',aa[step],step+1);
	dfs(f(a,b,c),'-',aa[step],step+1);
	dfs(a,b,c*aa[step],step+1);
}


int main(){
	s = 0;
	dfs(0,'+',1,1);
	cout<<s<<endl;
	return 0;	
}
