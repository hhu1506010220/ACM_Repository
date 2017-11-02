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
    long long l,r;//�����ߵ����Ҷ˵�ĺ�����  
    long long h;//�����ߵ�������  
    int f;//�������Ǿ��ε��ϱ߻����±�  
}e[N<<1]; 
 
bool cmp(Edge a,Edge b)  
{  
    return a.h < b.h;  
}  

struct Node  
{  
    int l,r;//����������䣬�Ǻ�����������±�  
    int s;//�ýڵ㱻���ǵ�������Ƿ���ȫ���ǣ�  
    long long len;//�����䱻���ǵ��ܳ���  
}q[N*8];  

long long x[2*N];//������ 
 
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
    if (q[i].s) //���㣬�Ѿ������θ���  
    {  
        q[i].len = x[q[i].r+1] - x[q[i].l];  
    }  
    else if (q[i].l == q[i].r) //����һ����������߶�  
    {  
        q[i].len = 0;  
    }  
    else //��һ��û���������䱻���ǵ��߶Σ��ϲ������ӵ���Ϣ  
    {  
        q[i].len = q[ls].len + q[rs].len;  
    }  
}  
void update(int i,int l,int r,int xx)//����������Ϊʲô���±�Ϊ1���ϱ�-1  
{                                   //�±߲���ߣ��ϱ�ɾ����  
    if (q[i].l == l&&q[i].r == r)  
    {  
        q[i].s += xx;  
        pushup(i);//�������䱻����de�ܳ���  
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
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);//����һ������  
            Edge &t1 = e[tot];Edge &t2 = e[1+tot];  
            t1.l = t2.l = x1,t1.r = t2.r = x2;  
            t1.h = y1;t1.f = 1;  
            t2.h = y2;t2.f = -1;  
            x[tot] = x1;x[tot+1] = x2;  
            tot += 2;  
        }  
        sort(e,e+tot,cmp);//�߰��߶ȴ�С�����������¶���ɨ�裩  
        sort(x,x+tot);  
        //��ɢ��������  
        int k = 1;  
        for (int i = 1;i < tot;++i)  
        {  
            if (x[i] != x[i-1]) //ȥ��  
            {  
                x[k++] = x[i];  
            }  
        }  
        build(1,0,k-1);//��ɢ�����������[0��k-1]  
        long long ans = 0.0;  
        for (int i = 0;i < tot;++i)  
        {  
            //��Ϊ�߶��������������Ӧ���±�  
            int l = lower_bound(x,x+k,e[i].l) - x;//�ں����λ��  
            int r = lower_bound(x,x+k,e[i].r) - x - 1;  
            update(1,l,r,e[i].f);//ÿɨ���ĸ���len  
            ans += (e[i+1].h - e[i].h)*q[1].len;//q[1]����  

        }  
        printf("%lld\n",ans);  
    }  
    return 0;  
} 
