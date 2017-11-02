#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define Max 10
#define mod 2147493647
using namespace std;
struct Matrix
{
    int n,m;
    long long a[Max][Max];
       
    Matrix operator * (Matrix b)
    {
        Matrix c;
        c.n=n;
        c.m=b.m;
        memset(c.a,0,sizeof(c.a));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<b.m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    c.a[i][j] = (c.a[i][j] + (a[i][k] * b.a[k][j]) % mod + mod) % mod;
                }
            }
        }
        return c;
    }
};

Matrix quickpow(Matrix a,int n)
{
    Matrix c;
    c.n=a.n;
    c.m=a.m;
    for(int i=0;i<c.n;i++)
    {
        for(int j=0;j<c.m;j++)
            c.a[i][j]=(i==j);//初始化为单位矩阵；
    }
    while(n){
        if(n&1)	
            c=c*a;
            
        a=a*a;
        n = (n>>1);
	}
    return c;
}

long long fff(Matrix A,Matrix ans)
{
	long long x = 0;
	for(int i=0;i<7;i++)
    {
        x = (x + (A.a[0][i] * ans.a[i][0]) % mod + mod) %mod;
    }
	return x;
}

int main()
{
	int T;
	scanf("%d",&T);
	int N,f1,f2;
	while(T--)
	{
		scanf("%d%d%d",&N,&f1,&f2);
		Matrix A,ans;
		A.n = 7;
	    A.m = 7;
	    A.a[0][0] = 0; A.a[0][1] = 1; A.a[0][2] = 0;A.a[0][3] = 0; A.a[0][4] = 0; A.a[0][5] = 0;A.a[0][6] = 0;
	    A.a[1][0] = 2; A.a[1][1] = 1; A.a[1][2] = 1;A.a[1][3] = 0; A.a[1][4] = 0; A.a[1][5] = 0;A.a[1][6] = 0;
	    A.a[2][0] = 0; A.a[2][1] = 0; A.a[2][2] = 1;A.a[2][3] = 4; A.a[2][4] = 6; A.a[2][5] = 4;A.a[2][6] = 1;
		A.a[3][0] = 0; A.a[3][1] = 0; A.a[3][2] = 0;A.a[3][3] = 1; A.a[3][4] = 3; A.a[3][5] = 3;A.a[3][6] = 1;
		A.a[4][0] = 0; A.a[4][1] = 0; A.a[4][2] = 0;A.a[4][3] = 0; A.a[4][4] = 1; A.a[4][5] = 2;A.a[4][6] = 1;
		A.a[5][0] = 0; A.a[5][1] = 0; A.a[5][2] = 0;A.a[5][3] = 0; A.a[5][4] = 0; A.a[5][5] = 1;A.a[5][6] = 1;
		A.a[6][0] = 0; A.a[6][1] = 0; A.a[6][2] = 0;A.a[6][3] = 0; A.a[6][4] = 0; A.a[6][5] = 0;A.a[6][6] = 1;
//		cout<<"ss"<<endl;
	    A = quickpow(A,N-1);
//	    
//	    for(int i = 0;i<7;i++)
//		{
//			for(int j = 0;j<7;j++)
//			{
//				cout<<A.a[i][j]<<" "; 
//			} 
//			cout<<endl;
//		}
	        
	    ans.n = 7;
	    ans.m = 1;
	    ans.a[0][0] = f1;
	    ans.a[1][0] = f2;
	    ans.a[2][0] = 81;
	    ans.a[3][0] = 27;
	    ans.a[4][0] = 9;
	    ans.a[5][0] = 3;
	    ans.a[6][0] = 1;
	    
	    long long x = fff(A,ans);
	    
	    cout<<x<<endl;
	}
    
    return 0;
}
