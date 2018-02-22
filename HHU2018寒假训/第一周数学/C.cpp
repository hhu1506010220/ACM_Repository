#include<bits/stdc++.h>
using namespace std;
char s[1005];
int t[1005] ;
struct BigInt{
	int a[1005];
	int len ;
	BigInt(){
		memset(a,0,sizeof(a));
		len = 1;	
	}
	void read(){
		memset(s,0,sizeof(s));
		scanf("%s",s);
		len = strlen(s);
		for(int i=1;i<=len;i++){
			a[len-i+1] = (s[i-1]-48);
		}
	}
	void Add_BigInt(BigInt b){
		memset(t,0,sizeof(t));
		for(int i=1;i<=b.len;i++)t[i] = b.a[i];
		len = max(len,b.len);
		for(int i=1;i<=len;i++){
			a[i]+=t[i];	
		}
		for(int i=1;i<=len;i++){
			a[i+1] += a[i]/10;
			a[i] %= 10;	
		}
		if(a[len+1])len++; 
	}
	void Print(){
		for(int i=len;i>=1;i--){
			printf("%d",a[i]);	
		}
	}
};

int main(){
	int t;
	scanf("%d",&t);
	int Case = 1;
	BigInt n_a,n_b;
	for(int i=0;i<t;i++){
		memset(n_a.a,0,sizeof(n_a.a));
		memset(n_b.a,0,sizeof(n_b.a));
		n_a.len = n_b.len = 1;
		printf("Case %d:\n",Case++);
		n_a.read();
		n_b.read();	
		n_a.Print();
		printf(" + ");
		n_b.Print();
		printf(" = ");
		n_a.Add_BigInt(n_b);
		n_a.Print();
		puts("");
		if(i!=t-1)puts("");
	}
	return 0;
}
