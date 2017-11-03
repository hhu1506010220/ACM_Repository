#include <iostream>  
#include <cstring>  
#include<math.h>  
using namespace std;  
  
#define DIGIT   4      //四位隔开,即万进制  
#define DEPTH   10000        //万进制  
#define MAX     100  
typedef int bignum_t[MAX+1];  
  
/************************************************************************/  
/* 读取操作数，对操作数进行处理存储在数组里                             */  
/************************************************************************/  
int read(bignum_t a,istream&is=cin)  
{  
    char buf[MAX*DIGIT+1],ch ;  
    int i,j ;  
    memset((void*)a,0,sizeof(bignum_t));  
    if(!(is>>buf))return 0 ;  
    for(a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)  
    ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch ;  
    for(a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');  
    for(i=1;i<=a[0];i++)  
    for(a[i]=0,j=0;j<DIGIT;j++)  
    a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0' ;  
    for(;!a[a[0]]&&a[0]>1;a[0]--);  
    return 1 ;  
}  
  
void write(const bignum_t a,ostream&os=cout)  
{  
    int i,j ;  
    for(os<<a[i=a[0]],i--;i;i--)  
    for(j=DEPTH/10;j;j/=10)  
    os<<a[i]/j%10 ;  
}  
  
int comp(const bignum_t a,const bignum_t b)  
{  
    int i ;  
    if(a[0]!=b[0])  
    return a[0]-b[0];  
    for(i=a[0];i;i--)  
    if(a[i]!=b[i])  
    return a[i]-b[i];  
    return 0 ;  
}  
  
int comp(const bignum_t a,const int b)  
{  
    int c[12]=  
    {  
        1   
    }  
    ;  
    for(c[1]=b;c[c[0]]>=DEPTH;c[c[0]+1]=c[c[0]]/DEPTH,c[c[0]]%=DEPTH,c[0]++);  
    return comp(a,c);  
}  
  
int comp(const bignum_t a,const int c,const int d,const bignum_t b)  
{  
    int i,t=0,O=-DEPTH*2 ;  
    if(b[0]-a[0]<d&&c)  
    return 1 ;  
    for(i=b[0];i>d;i--)  
    {  
        t=t*DEPTH+a[i-d]*c-b[i];  
        if(t>0)return 1 ;  
        if(t<O)return 0 ;  
    }  
    for(i=d;i;i--)  
    {  
        t=t*DEPTH-b[i];  
        if(t>0)return 1 ;  
        if(t<O)return 0 ;  
    }  
    return t>0 ;  
}  
/************************************************************************/  
/* 大数与大数相加                                                       */  
/************************************************************************/  
void add(bignum_t a,const bignum_t b)  
{  
    int i ;  
    for(i=1;i<=b[0];i++)  
    if((a[i]+=b[i])>=DEPTH)  
    a[i]-=DEPTH,a[i+1]++;  
    if(b[0]>=a[0])  
    a[0]=b[0];  
    else   
    for(;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);  
    a[0]+=(a[a[0]+1]>0);  
}  
/************************************************************************/  
/* 大数与小数相加                                                       */  
/************************************************************************/  
void add(bignum_t a,const int b)  
{  
    int i=1 ;  
    for(a[1]+=b;a[i]>=DEPTH&&i<a[0];a[i+1]+=a[i]/DEPTH,a[i]%=DEPTH,i++);  
    for(;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);  
}  
/************************************************************************/  
/* 大数相减(被减数>=减数)                                               */  
/************************************************************************/  
void sub(bignum_t a,const bignum_t b)  
{  
    int i ;  
    for(i=1;i<=b[0];i++)  
    if((a[i]-=b[i])<0)  
    a[i+1]--,a[i]+=DEPTH ;  
    for(;a[i]<0;a[i]+=DEPTH,i++,a[i]--);  
    for(;!a[a[0]]&&a[0]>1;a[0]--);  
}  
/************************************************************************/  
/* 大数减去小数(被减数>=减数)                                           */  
/************************************************************************/  
void sub(bignum_t a,const int b)  
{  
    int i=1 ;  
    for(a[1]-=b;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);  
    for(;!a[a[0]]&&a[0]>1;a[0]--);  
}  
  
void sub(bignum_t a,const bignum_t b,const int c,const int d)  
{  
    int i,O=b[0]+d ;  
    for(i=1+d;i<=O;i++)  
    if((a[i]-=b[i-d]*c)<0)  
    a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH ;  
    for(;a[i]<0;a[i+1]+=(a[i]-DEPTH+1)/DEPTH,a[i]-=(a[i]-DEPTH+1)/DEPTH*DEPTH,i++);  
    for(;!a[a[0]]&&a[0]>1;a[0]--);  
}  
/************************************************************************/  
/* 大数相乘，读入被乘数a，乘数b，结果保存在c[]                          */  
/************************************************************************/  
void mul(bignum_t c,const bignum_t a,const bignum_t b)  
{  
    int i,j ;  
    memset((void*)c,0,sizeof(bignum_t));  
    for(c[0]=a[0]+b[0]-1,i=1;i<=a[0];i++)  
    for(j=1;j<=b[0];j++)  
    if((c[i+j-1]+=a[i]*b[j])>=DEPTH)  
    c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH ;  
    for(c[0]+=(c[c[0]+1]>0);!c[c[0]]&&c[0]>1;c[0]--);  
}  
/************************************************************************/  
/* 大数乘以小数，读入被乘数a，乘数b，结果保存在被乘数                   */  
/************************************************************************/  
void mul(bignum_t a,const int b)  
{  
    int i ;  
    for(a[1]*=b,i=2;i<=a[0];i++)  
    {  
        a[i]*=b ;  
        if(a[i-1]>=DEPTH)  
        a[i]+=a[i-1]/DEPTH,a[i-1]%=DEPTH ;  
    }  
    for(;a[a[0]]>=DEPTH;a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);  
    for(;!a[a[0]]&&a[0]>1;a[0]--);  
}  
  
void mul(bignum_t b,const bignum_t a,const int c,const int d)  
{  
    int i ;  
    memset((void*)b,0,sizeof(bignum_t));  
    for(b[0]=a[0]+d,i=d+1;i<=b[0];i++)  
    if((b[i]+=a[i-d]*c)>=DEPTH)  
    b[i+1]+=b[i]/DEPTH,b[i]%=DEPTH ;  
    for(;b[b[0]+1];b[0]++,b[b[0]+1]=b[b[0]]/DEPTH,b[b[0]]%=DEPTH);  
    for(;!b[b[0]]&&b[0]>1;b[0]--);  
}  
/**************************************************************************/  
/* 大数相除,读入被除数a，除数b，结果保存在c[]数组                         */  
/* 需要comp()函数                                                         */  
/**************************************************************************/  
void div(bignum_t c,bignum_t a,const bignum_t b)  
{  
    int h,l,m,i ;  
    memset((void*)c,0,sizeof(bignum_t));  
    c[0]=(b[0]<a[0]+1)?(a[0]-b[0]+2):1 ;  
    for(i=c[0];i;sub(a,b,c[i]=m,i-1),i--)  
    for(h=DEPTH-1,l=0,m=(h+l+1)>>1;h>l;m=(h+l+1)>>1)  
    if(comp(b,m,i-1,a))h=m-1 ;  
    else l=m ;  
    for(;!c[c[0]]&&c[0]>1;c[0]--);  
    c[0]=c[0]>1?c[0]:1 ;  
}  
  
void div(bignum_t a,const int b,int&c)  
{  
    int i ;  
    for(c=0,i=a[0];i;c=c*DEPTH+a[i],a[i]=c/b,c%=b,i--);  
    for(;!a[a[0]]&&a[0]>1;a[0]--);  
}  
/************************************************************************/  
/* 大数平方根，读入大数a，结果保存在b[]数组里                           */  
/* 需要comp()函数                                                       */  
/************************************************************************/  
void sqrt(bignum_t b,bignum_t a)  
{  
    int h,l,m,i ;  
    memset((void*)b,0,sizeof(bignum_t));  
    for(i=b[0]=(a[0]+1)>>1;i;sub(a,b,m,i-1),b[i]+=m,i--)  
    for(h=DEPTH-1,l=0,b[i]=m=(h+l+1)>>1;h>l;b[i]=m=(h+l+1)>>1)  
    if(comp(b,m,i-1,a))h=m-1 ;  
    else l=m ;  
    for(;!b[b[0]]&&b[0]>1;b[0]--);  
    for(i=1;i<=b[0];b[i++]>>=1);  
}  
/************************************************************************/  
/* 返回大数的长度                                                       */  
/************************************************************************/  
int length(const bignum_t a)  
{  
    int t,ret ;  
    for(ret=(a[0]-1)*DIGIT,t=a[a[0]];t;t/=10,ret++);  
    return ret>0?ret:1 ;  
}  
/************************************************************************/  
/* 返回指定位置的数字，从低位开始数到第b位，返回b位上的数               */  
/************************************************************************/  
int digit(const bignum_t a,const int b)  
{  
    int i,ret ;  
    for(ret=a[(b-1)/DIGIT+1],i=(b-1)%DIGIT;i;ret/=10,i--);  
    return ret%10 ;  
}  
/************************************************************************/  
/* 返回大数末尾0的个数                                                  */  
/************************************************************************/  
int zeronum(const bignum_t a)  
{  
    int ret,t ;  
    for(ret=0;!a[ret+1];ret++);  
    for(t=a[ret+1],ret*=DIGIT;!(t%10);t/=10,ret++);  
    return ret ;  
}  
  
void comp(int*a,const int l,const int h,const int d)  
{  
    int i,j,t ;  
    for(i=l;i<=h;i++)  
    for(t=i,j=2;t>1;j++)  
    while(!(t%j))  
    a[j]+=d,t/=j ;  
}  
  
void convert(int*a,const int h,bignum_t b)  
{  
    int i,j,t=1 ;  
    memset(b,0,sizeof(bignum_t));  
    for(b[0]=b[1]=1,i=2;i<=h;i++)  
    if(a[i])  
    for(j=a[i];j;t*=i,j--)  
    if(t*i>DEPTH)  
    mul(b,t),t=1 ;  
    mul(b,t);  
}  
/************************************************************************/  
/* 组合数                                                               */  
/************************************************************************/  
void combination(bignum_t a,int m,int n)  
{  
    int*t=new int[m+1];  
    memset((void*)t,0,sizeof(int)*(m+1));  
    comp(t,n+1,m,1);  
    comp(t,2,m-n,-1);  
    convert(t,m,a);  
    delete[]t ;  
}  
/************************************************************************/  
/* 排列数                                                               */  
/************************************************************************/  
void permutation(bignum_t a,int m,int n)  
{  
    int i,t=1 ;  
    memset(a,0,sizeof(bignum_t));  
    a[0]=a[1]=1 ;  
    for(i=m-n+1;i<=m;t*=i++)  
    if(t*i>DEPTH)  
    mul(a,t),t=1 ;  
    mul(a,t);  
}  
  
#define SGN(x) ((x)>0?1:((x)<0?-1:0))  
#define ABS(x) ((x)>0?(x):-(x))  
  
int read(bignum_t a,int&sgn,istream&is=cin)  
{  
    char str[MAX*DIGIT+2],ch,*buf ;  
    int i,j ;  
    memset((void*)a,0,sizeof(bignum_t));  
    if(!(is>>str))return 0 ;  
    buf=str,sgn=1 ;  
    if(*buf=='-')sgn=-1,buf++;  
    for(a[0]=strlen(buf),i=a[0]/2-1;i>=0;i--)  
    ch=buf[i],buf[i]=buf[a[0]-1-i],buf[a[0]-1-i]=ch ;  
    for(a[0]=(a[0]+DIGIT-1)/DIGIT,j=strlen(buf);j<a[0]*DIGIT;buf[j++]='0');  
    for(i=1;i<=a[0];i++)  
    for(a[i]=0,j=0;j<DIGIT;j++)  
    a[i]=a[i]*10+buf[i*DIGIT-1-j]-'0' ;  
    for(;!a[a[0]]&&a[0]>1;a[0]--);  
    if(a[0]==1&&!a[1])sgn=0 ;  
    return 1 ;  
}  
struct bignum   
{  
    bignum_t num ;  
    int sgn ;  
    public :  
    inline bignum()  
    {  
        memset(num,0,sizeof(bignum_t));  
        num[0]=1 ;  
        sgn=0 ;  
    }  
    inline int operator!()  
    {  
        return num[0]==1&&!num[1];  
    }  
    inline bignum&operator=(const bignum&a)  
    {  
        memcpy(num,a.num,sizeof(bignum_t));  
        sgn=a.sgn ;  
        return*this ;  
    }  
    inline bignum&operator=(const int a)  
    {  
        memset(num,0,sizeof(bignum_t));  
        num[0]=1 ;  
        sgn=SGN (a);  
        add(num,sgn*a);  
        return*this ;  
    }  
    ;  
    inline bignum&operator+=(const bignum&a)  
    {  
        if(sgn==a.sgn)add(num,a.num);  
        else if           
        (sgn&&a.sgn)  
        {  
            int ret=comp(num,a.num);  
            if(ret>0)sub(num,a.num);  
            else if(ret<0)  
            {  
                bignum_t t ;  
                memcpy(t,num,sizeof(bignum_t));  
                memcpy(num,a.num,sizeof(bignum_t));  
                sub (num,t);  
                sgn=a.sgn ;  
            }  
            else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0 ;  
        }  
        else if(!sgn)  
            memcpy(num,a.num,sizeof(bignum_t)),sgn=a.sgn ;  
        return*this ;  
    }  
    inline bignum&operator+=(const int a)  
    {  
        if(sgn*a>0)add(num,ABS(a));  
        else if(sgn&&a)  
        {  
            int  ret=comp(num,ABS(a));  
            if(ret>0)sub(num,ABS(a));  
            else if(ret<0)  
            {  
                bignum_t t ;  
                memcpy(t,num,sizeof(bignum_t));  
                memset(num,0,sizeof(bignum_t));  
                num[0]=1 ;  
                add(num,ABS (a));  
                sgn=-sgn ;  
                sub(num,t);  
            }  
            else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0 ;  
        }  
        else if   
            (!sgn)sgn=SGN(a),add(num,ABS(a));  
        return*this ;  
    }  
    inline bignum operator+(const bignum&a)  
    {  
        bignum ret ;  
        memcpy(ret.num,num,sizeof (bignum_t));  
        ret.sgn=sgn ;  
        ret+=a ;  
        return ret ;  
    }  
    inline bignum operator+(const int a)  
    {  
        bignum ret ;  
        memcpy(ret.num,num,sizeof (bignum_t));  
        ret.sgn=sgn ;  
        ret+=a ;  
        return ret ;  
    }  
    inline bignum&operator-=(const bignum&a)  
    {  
        if(sgn*a.sgn<0)add(num,a.num);  
        else if           
        (sgn&&a.sgn)  
        {  
            int ret=comp(num,a.num);  
            if(ret>0)sub(num,a.num);  
            else if(ret<0)  
            {  
                bignum_t t ;  
                memcpy(t,num,sizeof(bignum_t));  
                memcpy(num,a.num,sizeof(bignum_t));  
                sub(num,t);  
                sgn=-sgn ;  
            }  
            else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0 ;  
        }  
        else if(!sgn)add (num,a.num),sgn=-a.sgn ;  
        return*this ;  
    }  
    inline bignum&operator-=(const int a)  
    {  
        if(sgn*a<0)add(num,ABS(a));  
        else if(sgn&&a)  
        {  
            int  ret=comp(num,ABS(a));  
            if(ret>0)sub(num,ABS(a));  
            else if(ret<0)  
            {  
                bignum_t t ;  
                memcpy(t,num,sizeof(bignum_t));  
                memset(num,0,sizeof(bignum_t));  
                num[0]=1 ;  
                add(num,ABS(a));  
                sub(num,t);  
                sgn=-sgn ;  
            }  
            else memset(num,0,sizeof(bignum_t)),num[0]=1,sgn=0 ;  
        }  
        else if   
            (!sgn)sgn=-SGN(a),add(num,ABS(a));  
        return*this ;  
    }  
    inline bignum operator-(const bignum&a)  
    {  
        bignum ret ;  
        memcpy(ret.num,num,sizeof(bignum_t));  
        ret.sgn=sgn ;  
        ret-=a ;  
        return ret ;  
    }  
    inline bignum operator-(const int a)  
    {  
        bignum ret ;  
        memcpy(ret.num,num,sizeof(bignum_t));  
        ret.sgn=sgn ;  
        ret-=a ;  
        return ret ;  
    }  
    inline bignum&operator*=(const bignum&a)  
    {  
        bignum_t t ;  
        mul(t,num,a.num);  
        memcpy(num,t,sizeof(bignum_t));  
        sgn*=a.sgn ;  
        return*this ;  
    }  
    inline bignum&operator*=(const int a)  
    {  
        mul(num,ABS(a));  
        sgn*=SGN(a);  
        return*this ;  
    }  
    inline bignum operator*(const bignum&a)  
    {  
        bignum ret ;  
        mul(ret.num,num,a.num);  
        ret.sgn=sgn*a.sgn ;  
        return ret ;  
    }  
    inline bignum operator*(const int a)  
    {  
        bignum ret ;  
        memcpy(ret.num,num,sizeof (bignum_t));  
        mul(ret.num,ABS(a));  
        ret.sgn=sgn*SGN(a);  
        return ret ;  
    }  
    inline bignum&operator/=(const bignum&a)  
    {  
        bignum_t t ;  
        div(t,num,a.num);  
        memcpy (num,t,sizeof(bignum_t));  
        sgn=(num[0]==1&&!num[1])?0:sgn*a.sgn ;  
        return*this ;  
    }  
    inline bignum&operator/=(const int a)  
    {  
        int t ;  
        div(num,ABS(a),t);  
        sgn=(num[0]==1&&!num [1])?0:sgn*SGN(a);  
        return*this ;  
    }  
    inline bignum operator/(const bignum&a)  
    {  
        bignum ret ;  
        bignum_t t ;  
        memcpy(t,num,sizeof(bignum_t));  
        div(ret.num,t,a.num);  
        ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*a.sgn ;  
        return ret ;  
    }  
    inline bignum operator/(const int a)  
    {  
        bignum ret ;  
        int t ;  
        memcpy(ret.num,num,sizeof(bignum_t));  
        div(ret.num,ABS(a),t);  
        ret.sgn=(ret.num[0]==1&&!ret.num[1])?0:sgn*SGN(a);  
        return ret ;  
    }  
    inline bignum&operator%=(const bignum&a)  
    {  
        bignum_t t ;  
        div(t,num,a.num);  
        if(num[0]==1&&!num[1])sgn=0 ;  
        return*this ;  
    }  
    inline int operator%=(const int a)  
    {  
        int t ;  
        div(num,ABS(a),t);  
        memset(num,0,sizeof (bignum_t));  
        num[0]=1 ;  
        add(num,t);  
        return t ;  
    }  
    inline bignum operator%(const bignum&a)  
    {  
        bignum ret ;  
        bignum_t t ;  
        memcpy(ret.num,num,sizeof(bignum_t));  
        div(t,ret.num,a.num);  
        ret.sgn=(ret.num[0]==1&&!ret.num [1])?0:sgn ;  
        return ret ;  
    }  
    inline int operator%(const int a)  
    {  
        bignum ret ;  
        int t ;  
        memcpy(ret.num,num,sizeof(bignum_t));  
        div(ret.num,ABS(a),t);  
        memset(ret.num,0,sizeof(bignum_t));  
        ret.num[0]=1 ;  
        add(ret.num,t);  
        return t ;  
    }  
    inline bignum&operator++()  
    {  
        *this+=1 ;  
        return*this ;  
    }  
    inline bignum&operator--()  
    {  
        *this-=1 ;  
        return*this ;  
    }  
    ;  
    inline int operator>(const bignum&a)  
    {  
        return sgn>0?(a.sgn>0?comp(num,a.num)>0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<0:0):a.sgn<0);  
    }  
    inline int operator>(const int a)  
    {  
        return sgn>0?(a>0?comp(num,a)>0:1):(sgn<0?(a<0?comp(num,-a)<0:0):a<0);  
    }  
    inline int operator>=(const bignum&a)  
    {  
        return sgn>0?(a.sgn>0?comp(num,a.num)>=0:1):(sgn<0?(a.sgn<0?comp(num,a.num)<=0:0):a.sgn<=0);  
    }  
    inline int operator>=(const int a)  
    {  
        return sgn>0?(a>0?comp(num,a)>=0:1):(sgn<0?(a<0?comp(num,-a)<=0:0):a<=0);  
    }  
    inline int operator<(const bignum&a)  
    {  
        return sgn<0?(a.sgn<0?comp(num,a.num)>0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<0:0):a.sgn>0);  
    }  
    inline int operator<(const int a)  
    {  
        return sgn<0?(a<0?comp(num,-a)>0:1):(sgn>0?(a>0?comp(num,a)<0:0):a>0);  
    }  
    inline int operator<=(const bignum&a)  
    {  
        return sgn<0?(a.sgn<0?comp(num,a.num)>=0:1):(sgn>0?(a.sgn>0?comp(num,a.num)<=0:0):a.sgn>=0);  
    }  
    inline int operator<=(const int a)  
    {  
        return sgn<0?(a<0?comp(num,-a)>=0:1):  
        (sgn>0?(a>0?comp(num,a)<=0:0):a>=0);  
    }  
    inline int operator==(const bignum&a)  
    {  
        return(sgn==a.sgn)?!comp(num,a.num):0 ;  
    }  
    inline int operator==(const int a)  
    {  
        return(sgn*a>=0)?!comp(num,ABS(a)):0 ;  
    }  
    inline int operator!=(const bignum&a)  
    {  
        return(sgn==a.sgn)?comp(num,a.num):1 ;  
    }  
    inline int operator!=(const int a)  
    {  
        return(sgn*a>=0)?comp(num,ABS(a)):1 ;  
    }  
    inline int operator[](const int a)  
    {  
        return digit(num,a);  
    }  
    friend inline istream&operator>>(istream&is,bignum&a)  
    {  
        read(a.num,a.sgn,is);  
        return  is ;  
    }  
    friend inline ostream&operator<<(ostream&os,const bignum&a)  
    {  
        if(a.sgn<0)  
            os<<'-' ;  
        write(a.num,os);  
        return os ;  
    }  
    friend inline bignum sqrt(const bignum&a)  
    {  
        bignum ret ;  
        bignum_t t ;  
        memcpy(t,a.num,sizeof(bignum_t));  
        sqrt(ret.num,t);  
        ret.sgn=ret.num[0]!=1||ret.num[1];  
        return ret ;  
    }  
    friend inline bignum sqrt(const bignum&a,bignum&b)  
    {  
        bignum ret ;  
        memcpy(b.num,a.num,sizeof(bignum_t));  
        sqrt(ret.num,b.num);  
        ret.sgn=ret.num[0]!=1||ret.num[1];  
        b.sgn=b.num[0]!=1||ret.num[1];  
        return ret ;  
    }  
    inline int length()  
    {  
        return :: length(num);  
    }  
    inline int zeronum()  
    {  
        return :: zeronum(num);  
    }  
    inline bignum C(const int m,const int n)  
    {  
        combination(num,m,n);  
        sgn=1 ;  
        return*this ;  
    }  
    inline bignum P(const int m,const int n)  
    {  
        permutation(num,m,n);  
        sgn=1 ;  
        return*this ;  
    }  
};  
int vis[1000],cnt,n=300;
//int prime[1000];
//bignum chengji[500]={  
//        2,  
//        6,  
//        30,  
//        210,  
//        2310,  
//        30030,  
//        510510,  
//        9699690,  
//        223092870,  
//        6469693230,  
//        200560490130,  
//        7420738134810,  
//        304250263527210,  
//        13082761331670030,  
//        614889782588491410,  
//        32589158477190044730,  
//        1922760350154212639070,   
//        117288381359406970983270,  
//        7858321551080267055879090,  
//        557940830126698960967415390,  
//        40729680599249024150621323470,  
//        3217644767340672907899084554130,  
//        267064515689275851355624017992790,  
//        23768741896345550770650537601358310,  
//        2305567963945518424753102147331756070,  
//        232862364358497360900063316880507363070,  
//        23984823528925228172706521638692258396210,  
//        2566376117594999414479597815340071648394470,  
//        279734996817854936178276161872067809674997230,  
//        31610054640417607788145206291543662493274686990,  
//        4014476939333036189094441199026045136645885247730,  
//        525896479052627740771371797072411912900610967452630,  
//        72047817630210000485677936198920432067383702541010310,  
//        10014646650599190067509233131649940057366334653200433090,  
//        1492182350939279320058875736615841068547583863326864530410,  
//        225319534991831177328890236228992001350685163362356544091910,  
//        35375166993717494840635767087951744212057570647889977422429870,  
//        5766152219975951659023630035336134306565384015606066319856068810,  
//        962947420735983927056946215901134429196419130606213075415963491270,  
//        166589903787325219380851695350896256250980509594874862046961683989710,  
//        29819592777931214269172453467810429868925511217482600306406141434158090,  
//        5397346292805549782720214077673687806275517530364350655459511599582614290,  
//        1030893141925860008499560888835674370998623848299590975192766715520279329390,  
//        198962376391690981640415251545285153602734402721821058212203976095413910572270,  
//        39195588149163123383161804554421175259738677336198748467804183290796540382737190,  
//        7799922041683461553249199106329813876687996789903550945093032474868511536164700810,  
//        1645783550795210387735581011435590727981167322669649249414629852197255934130751870910,  
//        367009731827331916465034565550136732339800312955331782619462457039988073311157667212930,  
//        83311209124804345037562846379881038241134671040860314654617977748077292641632790457335110,  
//        19078266889580195013601891820992757757219839668357012055907516904309700014933909014729740190,  
//        4445236185272185438169240794291312557432222642727183809026451438704160103479600800432029464270,  
//        1062411448280052319722448549835623701226301211611796930357321893850294264731624591303255041960530,  
//        256041159035492609053110100510385311995538591998443060216114576417920917800321526504084465112487730,      
//        64266330917908644872330635228106713310880186591609208114244758680898150367880703152525200743234420230  
//};
//void get_prime(){
//	int i,j,m;
//	cnt=0;
//	m=(int)sqrt(n+0.5);
//	memset(vis,0,sizeof(vis));
//	for(int i=2;i<=m;i++){
//		if(!vis[i]){
//			for(int j=i*i;j<=n;j+=i){
//				vis[j]=1;
//			}
//		}
//	}
//	for(int i=2;i<=n;i++){
//		if(!vis[i]){
//			prime[cnt++]=i;
//		}
//	}
//	
//}

int main() 
{    
	int t;
//	get_prime();
//	for(int i=0;i<cnt;i++)cout<<prime[i]<<" ";
//	chengji[0]=2;
//	for(int i=0;i<cnt-1;i++){
//		chengji[i+1]=chengji[i]*prime[i+1];
////		cout<<chengji[i]<<endl; 
//	}
	while(~scanf("%d",&t)){
	    while(t--){
	    	int n;cin>>n;
	    	cout<<(bignum)n;
//	    	bignum n;
//	    	cin>>n;
//	        for(int i=0;i<cnt;i++)  
//	        {  
//	           if(n>=chengji[i]&&n<chengji[i+1]){
//	   		        cout<<chengji[i]<<endl; 
//	   		        break;
//			   }
//	        }       
		}	
	}    
    return 0 ; 
}    

