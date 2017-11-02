#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
  
void exgcd(int a, int b, int &d, int &x, int &y)  //d��Ϊ����gcd(a,b) 
{  
    if (!b){d=a; x=1; y=0;}  
    else  
    {  
        exgcd(b, a%b, d, y, x);  
        y-=x*(a/b);  
    }  
}  
  
int main()  
{  
    int a,m,T;  
    cin>>T;  
    while (T--)  
    {  
        cin>>a>>m;  
        int d,x,y;  
        exgcd(a, m, d, x, y);  
        if (d==1)//�������Ϊ1  
        {  
            while (x<=0) x+=m;//�������Ϊ����  
            cout<<x<<endl;  
        }  
        else cout<<"Not Exist"<<endl;  
    }  
    return 0;  
}  
