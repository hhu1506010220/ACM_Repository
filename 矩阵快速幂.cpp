/**********************************/
/*	   						      */
/*		���������ģ��			  */
/*							      */
/**********************************/

#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long lint;
struct matrix {
	lint m[10][10];
	matrix() {
		memset(m,0,sizeof(m));//ע��Ҫ����
	}
};

matrix operator * (const matrix & a,const matrix & b) {
	matrix c;
	for (int i=1; i<=9; i++)
		for (int j=1; j<=9; j++) {
			c.m[i][j]=0;
			for (int k=1; k<=9; k++)
				c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;//һ����Ŀ��Ҫ��Ҫmoduloһ����
		}
	return c;
}

matrix quick(matrix base,int pow) {
	matrix a;
	for (int i=1; i<=9; i++) a.m[i][i]=1;//��λ�󣬾���˷�ʱҪ�õ�
	while (pow) {
		if (pow&1) a=a*base;
		base=base*base;
		pow>>=1;
	}
	//if (pow==0) return base;
	return a;
}

int main() {
	int k;
	while(scanf("%d",&k)!=EOF) {
		matrix A;
		A.m[1][1] = 1;
		A.m[1][2] = 1;
		A.m[2][1] = 1;
		A.m[2][2] = 0;

		matrix B;
		B.m[1][1] = 2;
		B.m[2][1] = 1;

		A = quick(A,2*(k-1)+2);
		B = A * B;

		printf("%lld\n",B.m[1][1] - 1);
	}
	
	return 0;
}
