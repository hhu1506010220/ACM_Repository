#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

long long extend_gcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	else{
		int r=extend_gcd(b,a%b,y,x);
		y-=x*(a/b);
		return r;
	}
}

int main(){
	long long x,y,m,n,l,t,a;
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	long long gcd=extend_gcd(m-n,-l,t,a);	
	if((y-x)%gcd!=0){
		puts("Impossible");
	}
	else{
		t=t*(y-x)/gcd;
		a=a*(y-x)/gcd;
		long long temp = l/gcd;
		if(temp<0)temp=-temp;
		t=(t%temp+temp)%temp;
		if(t<0)t=(t+temp)%temp;
		printf("%lld\n",t);
	}
	return 0;
}
