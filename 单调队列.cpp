/**********************************/
/*             单调队列           */
/**********************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 2000001
using namespace std;
int n,k;
int q[maxn],a[maxn],p[maxn],mi[maxn];
void Getmin()
{
    int tail=0,head=1;
    memset(q,0,sizeof(q));
    memset(p,0,sizeof(p));
    memset(mi,0,sizeof(mi));
    for(int i=1;i<k;i++)
    {
        while(head<=tail&&q[tail]>=a[i])
            --tail;
        q[++tail]=a[i];
        p[tail]=i;
    }
    for(int i=k;i<=n;i++)
    {
        while(head<=tail&&q[tail]>=a[i])
            --tail;
        q[++tail]=a[i];
        p[tail]=i;
        while(p[head]<i-k+1)     ++head;
        mi[i-k+1]=q[head];
    }
        for(int i=1;i<n-k+1;i++)
        printf("%d ",mi[i]);printf("%d\n",mi[n-k+1]);
}
 
void Getmax()
{
    int tail=0,head=1;
    memset(q,0,sizeof(q));
    memset(p,0,sizeof(p));
    memset(mi,0,sizeof(mi));
    for(int i=1;i<k;i++)
    {
        while(head<=tail&&q[tail]<=a[i])
            --tail;
        q[++tail]=a[i];
        p[tail]=i;
    }
    for(int i=k;i<=n;i++)
    {
        while(head<=tail&&q[tail]<=a[i])
            --tail;
        q[++tail]=a[i];
        p[tail]=i;
        while(p[head]<i-k+1)     ++head;
        mi[i-k+1]=q[head];
    }
    for(int i=1;i<n-k+1;i++)
        printf("%d ",mi[i]);printf("%d\n",mi[n-k+1]);
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    Getmin();
    Getmax();
    return 0;
}
