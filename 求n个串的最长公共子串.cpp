/**********************************/
/*	   						      */
/*		SAM后缀自动机            */
/*  求n个字符串的最长公共子串长度  */
/*							      */
/**********************************/
#include<bits/stdc++.h>
using namespace std;  
const int N=250005;  
  
struct State  
{  
    State *pre,*go[26];  
    int step,nl,ml;  
    void clear()  
    {  
        pre=0;  
        step=0;  
        memset(go,0,sizeof(go));  
    }  
}*root,*last;  
  
State statePool[N*2],*b[2*N],*cur;  
  
void init()  
{  
    cur=statePool;  
    root=last=cur++;  
    root->clear();  
}  
  
void Insert(int w)  
{  
    State *p=last;  
    State *np=cur++;  
    np->clear();  
    np->step=np->ml=p->step+1;  
    while(p&&!p->go[w])  
        p->go[w]=np,p=p->pre;  
    if(p==0)  
        np->pre=root;  
    else  
    {  
        State *q=p->go[w];  
        if(p->step+1==q->step)  
            np->pre=q;  
        else  
        {  
            State *nq=cur++;  
            nq->clear();  
            memcpy(nq->go,q->go,sizeof(q->go));  
            nq->step=nq->ml=p->step+1;  
            nq->pre=q->pre;  
            q->pre=nq;  
            np->pre=nq;  
            while(p&&p->go[w]==q)  
                p->go[w]=nq, p=p->pre;  
        }  
    }  
    last=np;  
}  
  
char str[N];  
int cnt[N];  
  
int main()  
{  
    int n,m;  
    scanf("%s",str);  
    n=strlen(str);  
    init();  
    for(int i=0; i<n; i++)  
        Insert(str[i]-'a');  
    for(State *p=statePool; p!=cur; p++)  
        cnt[p->step]++;  
    for(int i=1; i<=n; i++)  
        cnt[i]+=cnt[i-1];  
    for(State *p=statePool; p!=cur; p++)  
        b[--cnt[p->step]]=p;  
    while(~scanf("%s",str))  
    {  
        int len=0;  
        m=strlen(str);  
        State *p=root;  
        for(int i=0; i<m; i++)  
        {  
            int x=str[i]-'a';  
            if(p->go[x])  
            {  
                len++;  
                p=p->go[x];  
            }  
            else  
            {  
                while(p&&!p->go[x]) p=p->pre;  
                if(!p) p=root,len=0;  
                else   len=p->step+1,p=p->go[x];  
            }  
            if(len>p->nl) p->nl=len;  
        }  
        int num=cur-statePool;  
        for(int i=num-1;i>=0;i--)  
        {  
            p=b[i];  
            if(p->ml>p->nl) p->ml=p->nl;  
            if(p->pre&&p->pre->nl<p->nl) p->pre->nl=p->nl;  
            p->nl=0;  
        }  
    }  
    int ans=0;  
    for(State *p=statePool;p!=cur;p++)  
        if(p->ml>ans) ans=p->ml;  
    printf("%d\n",ans);  
    return 0;  
}  
