#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=200010;
int n,a[3][maxn],d[maxn],s[maxn];
LL ans=0;
int qqq;

#define lowbit(x) ((x)&(-x))

void calu(int p)
{
    while(p<=n)
    {
        s[p]++;
        p+=lowbit(p);
    }
}

int cal(int p)
{
    int res=0;
    while(p>0)
    {
        res+=s[p];
        p-=lowbit(p);
    }
    return res;
}

bool cmp(int x,int y)
{
    return a[qqq][x]<a[qqq][y];
}

LL CDQ_FF(int x,int y)
{
    LL res=0;
    qqq=x;
    for(int i=1;i<=n;i++)d[i]=i;
    sort(d+1,d+n+1,cmp);
    for(int i=1;i<=n;i++)s[i]=0;
    for(int i=1;i<=n;i++)
    {
        res+=(long long)(((long long)(1))*(cal(n)-cal(a[y][d[i]])));
        calu(a[y][d[i]]);
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
    ans+=CDQ_FF(0,1);
    ans+=CDQ_FF(2,0);
    ans+=CDQ_FF(1,2);
    printf("%lld\n",ans/2);
    return 0;
}

