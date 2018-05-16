#include <bits/stdc++.h>
#define ll long long
using namespace std;
	int n,q,l,r;
	int f[5005][5005],g[5005][5005];
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		g[1][i]=f[1][i]=read();
	for (int i=2;i<=n;i++)//长度
		for (int j=1;j<=n-i+1;j++){//起始位置
			f[i][j]=f[i-1][j]^f[i-1][j+1];
			g[i][j]=max(max(f[i][j],g[i-1][j]),g[i-1][j+1]);
		}
	q=read();
	while (q--){
		l=read(),r=read();
		printf("%d\n",g[r-l+1][l]);
	}
	return 0;
}
