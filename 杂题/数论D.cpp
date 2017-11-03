/* 
首先可以推出这个式子：a*x+b*y+c*z=|B-A|然后又因为c=a+b，所以其实可以化成a*x+b*y=|B-A|。
所以需要用扩展gcd求出x,y,但是这个x,y有可能不是最优的，为什么呢？
为了让步数最小就要拉近x，y的距离，使|x-y|最小。怎么拉近，下面来看通解方程：
 x = x0 - (b/gcd)*t（t为>=0的整数）
 y = y0 + (a/gcd)*t （t为>=0的整数）
实际上是关于x,y关于t的两条直线（他们必有交叉点）。
可以设x==y，然后解出那个对应的t,得到此时的一组解（t=(x0+y0)/((a+b)/gcd)），
但是实际上有可能无法使x==y（没有整数t)，所以算出来的t接近于交叉点的t(有可能是小数)，
所以可能也不是最优解，所以需要增加一次t，使得t为成为大于交叉点，但是最接近交叉点的点，
这样比较两个t得到的结果（x,y同为正或同为负时，绝对值大的那个值（c的存在，a和b合并为c），
一正一负就是绝对值和），其中小的一个必是最优解。
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
    if(c%gcd!=0)   //无解  
    {  
        return -1;  
    }  
    x*=c/gcd;  
    y*=c/gcd;  
      
    if(x<y)   //确定下面tx,ty的表达式做的处理  
    {  
        swap(x, y);  
        swap(a, b);  
    }  
    temp=x-y;  
    t=temp*gcd/(a+b);  //计算t  
      
      
    tx=x-t*b/gcd;  
    ty=y+t*a/gcd;  
    if (tx*ty>0)  
    {  
         
        ans1=Abs(tx) > Abs(ty) ?  Abs(tx) : Abs(ty);  //同号，方向相同，合并成c,步数取最大的那个。  
    }  
    else  
    {  
        ans1=Abs(tx)+Abs(ty);   //异号表示方向不同，步数等于其绝对值之和  
    }  
      
    tx=tx-b/gcd;   //t增加一次  
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
    return ans1 < ans2 ? ans1 : ans2;  //取最优解  
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
