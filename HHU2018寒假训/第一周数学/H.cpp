#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define mod 7
struct Matrix {
	long long ma[2][2];
};

Matrix mul(Matrix A,Matrix B) {
	Matrix C;
	C.ma[0][0]=C.ma[0][1]=C.ma[1][0]=C.ma[1][1]=0;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			for(int k=0; k<2; k++) {
				C.ma[i][j]=(C.ma[i][j]+A.ma[i][k]*B.ma[k][j])%mod;
			}
		}
	}
	return C;
}

Matrix pow_mod(Matrix A,long long n) {
	Matrix B;
	B.ma[0][0]=B.ma[1][1]=1;
	B.ma[0][1]=B.ma[1][0]=0;
	while(n) {
		if(n&1) B=mul(B,A);
		A=mul(A,A);
		n>>=1;
	}
	return B;
}

int main() {
	int a,b,n;
	while(~scanf("%d%d%d",&a,&b,&n)) {
		Matrix A;
		A.ma[0][0]=a;
		A.ma[0][1]=b;
		A.ma[1][0]=1;
		A.ma[1][1]=0;
		Matrix ans=pow_mod(A,n-2);
		printf("%lld\n",(ans.ma[0][0]+ans.ma[0][1]+7)%7);
	}
	return 0;
}
