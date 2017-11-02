#define mem(a,x) memset(a,x,sizeof(a))  
#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<queue>  
#include<set>  
#include<stack>  
#include<cmath>  
#include<map>  
#include<stdlib.h>  
#include<cctype>  
#include<string>  
using namespace std;  
typedef long long ll;  
const int N = 1010;  
struct Edge  
{  
    long long l,r;//这条线的左右端点的横坐标  
    long long h;//这条线的纵坐标  
    int f;//这条线是矩形的上边还是下边  
}e[N<<1]; 
 
bool cmp(Edge a,Edge b)  
{  
    return a.h < b.h;  
}  

struct Node  
{  
    int l,r;//横坐标的区间，是横坐标数组的下标  
    int s;//该节点被覆盖的情况（是否完全覆盖）  
    long long len;//该区间被覆盖的总长度  
}q[N*8];  

long long x[2*N];//横坐标 
 
#define ls i<<1  
#define rs i<<1|1  
#define m(i) ((q[i].l + q[i].r)>>1)  
void build(int i,int l,int r)  
{  
    q[i].l = l,q[i].r = r;  
    q[i].s = 0;q[i].len = 0;  
    if (l == r) return;  
    int mid = m(i);  
    build(ls,l,mid);  
    build(rs,mid+1,r);  
}  
void pushup(int i)  
{  
    if (q[i].s) //非零，已经被整段覆盖  
    {  
        q[i].len = x[q[i].r+1] - x[q[i].l];  
    }  
    else if (q[i].l == q[i].r) //这是一个点而不是线段  
    {  
        q[i].len = 0;  
    }  
    else //是一条没有整个区间被覆盖的线段，合并左右子的信息  
    {  
        q[i].len = q[ls].len + q[rs].len;  
    }  
}  
void update(int i,int l,int r,int xx)//这里深刻体会为什么令下边为1，上边-1  
{                                   //下边插入边，上边删除边  
    if (q[i].l == l&&q[i].r == r)  
    {  
        q[i].s += xx;  
        pushup(i);//更新区间被覆盖de总长度  
        return;  
    }  
    int mid = m(i);  
    if (r <= mid) update(ls,l,r,xx);  
    else if (l > mid) update(rs,l,r,xx);  
    else  
    {  
        update(ls,l,mid,xx);  
        update(rs,mid+1,r,xx);  
    }  
    pushup(i);  
}  
int main()  
{  
    int n;int kas = 0;  
    while (scanf("%d",&n)!= EOF)  
    {  
    	if(n == 0)
    	{
    		printf("*\n");
    		break;
		}
		
        int tot = 0;  
        for (int i = 0;i < n;++i)  
        {  
            long long x1,x2,y1,y2;  
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);//输入一个矩形  
            Edge &t1 = e[tot];Edge &t2 = e[1+tot];  
            t1.l = t2.l = x1,t1.r = t2.r = x2;  
            t1.h = y1;t1.f = 1;  
            t2.h = y2;t2.f = -1;  
            x[tot] = x1;x[tot+1] = x2;  
            tot += 2;  
        }  
        sort(e,e+tot,cmp);//边按高度从小到大排序（自下而上扫描）  
        sort(x,x+tot);  
        //离散化横坐标  
        int k = 1;  
        for (int i = 1;i < tot;++i)  
        {  
            if (x[i] != x[i-1]) //去重  
            {  
                x[k++] = x[i];  
            }  
        }  
        build(1,0,k-1);//离散化后的区间是[0，k-1]  
        long long ans = 0.0;  
        for (int i = 0;i < tot;++i)  
        {  
            //因为线段树两个横坐标对应的下标  
            int l = lower_bound(x,x+k,e[i].l) - x;//在横里的位置  
            int r = lower_bound(x,x+k,e[i].r) - x - 1;  
            update(1,l,r,e[i].f);//每扫到的覆盖len  
            ans += (e[i+1].h - e[i].h)*q[1].len;//q[1]整度  

        }  
        printf("%lld\n",ans);  
    }  
    return 0;  
} 
