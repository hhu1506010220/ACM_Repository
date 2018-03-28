#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,w;
const int maxn =15;
long long d[maxn][1<<15];
int path[5000000][2];//path[10][0]表示第11种(从0计数)兼容方式的前一行二进制形式对应的的值
//path[10][1]表示第11种(从0计数)兼容方式的后一行二进制形式对应的的值
//一共可能有(1<<11)*(1<<11)种兼容方式

void get(int c,int pre,int now) { //得到具有m列的矩阵的所有对应兼容方式存入path中
	if(c>m)return ;
	else if(c==m) {
		path[w][0]=pre;
		path[w++][1]=now;
		return;
	}
	get(c+1,(pre<<1)|1,now<<1);
	get(c+1,(pre<<1),(now<<1)|1);
	get(c+2,(pre<<2)|3,(now<<2)|3);
}

int main() {
	n= m =10;
	w=0;//兼容方式总数
	if(m>n)swap(n,m);//始终保持n为行，m为列数，且m较小
	get(0,0,0);//得到所有兼容方式
	memset(d,0,sizeof(d));
	d[0][(1<<m)-1]=1;//假想的第0行且二进制形式为全1时 出现1次
	for(int i=0; i<n; i++)//共n行
		for(int j=0; j<w; j++) { //每行有w种对应的兼容方式
			d[i+1][path[j][1]] +=d[i][path[j][0]];//path[j][0]与path[j][1]分别指兼容的两个二进制
			//d[i][x]表示第i行且该行的二进制表示为X时，共有多少种摆放骨牌的方式。
		}
	printf("%I64d\n",d[n][(1<<m)-1]);
	return 0;
}
