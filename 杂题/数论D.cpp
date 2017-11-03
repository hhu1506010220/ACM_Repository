/* 
���ȿ����Ƴ����ʽ�ӣ�a*x+b*y+c*z=|B-A|Ȼ������Ϊc=a+b��������ʵ���Ի���a*x+b*y=|B-A|��
������Ҫ����չgcd���x,y,�������x,y�п��ܲ������ŵģ�Ϊʲô�أ�
Ϊ���ò�����С��Ҫ����x��y�ľ��룬ʹ|x-y|��С����ô��������������ͨ�ⷽ�̣�
 x = x0 - (b/gcd)*t��tΪ>=0��������
 y = y0 + (a/gcd)*t ��tΪ>=0��������
ʵ�����ǹ���x,y����t������ֱ�ߣ����Ǳ��н���㣩��
������x==y��Ȼ�����Ǹ���Ӧ��t,�õ���ʱ��һ��⣨t=(x0+y0)/((a+b)/gcd)����
����ʵ�����п����޷�ʹx==y��û������t)�������������t�ӽ��ڽ�����t(�п�����С��)��
���Կ���Ҳ�������Ž⣬������Ҫ����һ��t��ʹ��tΪ��Ϊ���ڽ���㣬������ӽ������ĵ㣬
�����Ƚ�����t�õ��Ľ����x,yͬΪ����ͬΪ��ʱ������ֵ����Ǹ�ֵ��c�Ĵ��ڣ�a��b�ϲ�Ϊc����
һ��һ�����Ǿ���ֵ�ͣ�������С��һ���������Ž⡣
*/ 
#include <stdio.h>  
#include <iostream>  
#include <math.h>  
#include <stdlib.h>  
#include <string.h>  
using namespace std;  
typedef long long  LL;  
LL exgcd(LL a,LL b,LL &x,LL &y)  
{  
    if (b==0)  
    {  
        x=1;  
        y=0;  
        return a;  
    }  
    LL ans=exgcd(b, a%b, x, y);  
    LL temp=x;  
    x=y;  
    y=temp-a/b*y;  
    return ans;  
}  
LL Abs(LL x)  
{  
    if (x<0)  
    {  
        x=-x;  
    }  
    return x;  
}  
LL cal(LL a,LL b,LL c)  
{  
    LL x,y,temp,t,tx,ty,ans1,ans2;  
    LL gcd=exgcd(a, b, x, y);  
    if(c%gcd!=0)   //�޽�  
    {  
        return -1;  
    }  
    x*=c/gcd;  
    y*=c/gcd;  
      
    if(x<y)   //ȷ������tx,ty�ı��ʽ���Ĵ���  
    {  
        swap(x, y);  
        swap(a, b);  
    }  
    temp=x-y;  
    t=temp*gcd/(a+b);  //����t  
      
      
    tx=x-t*b/gcd;  
    ty=y+t*a/gcd;  
    if (tx*ty>0)  
    {  
         
        ans1=Abs(tx) > Abs(ty) ?  Abs(tx) : Abs(ty);  //ͬ�ţ�������ͬ���ϲ���c,����ȡ�����Ǹ���  
    }  
    else  
    {  
        ans1=Abs(tx)+Abs(ty);   //��ű�ʾ����ͬ���������������ֵ֮��  
    }  
      
    tx=tx-b/gcd;   //t����һ��  
    ty=ty+a/gcd;  
    if (tx*ty>0)  
    {  
        tx=Abs(tx);  
        ty=Abs(ty);  
        ans2=tx > ty ? tx : ty;  
    }  
    else  
    {  
        ans2=Abs(tx)+Abs(ty);  
    }  
    return ans1 < ans2 ? ans1 : ans2;  //ȡ���Ž�  
}  
  
int main()  
{  
    LL A,B,a,b;  
    int t;  
    scanf("%d",&t);  
    while (t--)  
    {  
        scanf("%lld%lld%lld%lld",&A,&B,&a,&b);  
        printf("%lld\n",cal(a, b,Abs(A-B)));  
          
    }  
    return 0;  
      
}  
