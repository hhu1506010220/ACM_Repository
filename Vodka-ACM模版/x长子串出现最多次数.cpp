/**********************************/
/*		��һ���ַ���S��			  */
/* F(x)��ʾS�����г���Ϊx���Ӵ��� */
/*  ���ִ��������ֵ��            */
/*  ��F(1)..F(Length(S)) ��       */
/**********************************/
#include<bits/stdc++.h> 
#define MAXN 500010+5 
#define MAXC 26 
using namespace std; 
char ch[MAXN];//�����ַ��� 
int rk[MAXN],sz[MAXN],ans[MAXN]; 
struct Suffix_Automaton{ 
    int child[MAXN][MAXC]; 
    int f[MAXN];//ָ������Ľ���̬ 
    int l[MAXN];//�˽ڵ���������ĳ��� 
    int head,tail,tot;//ͷ�ڵ�,���Ľ���̬,�ܽڵ� 
    void clear(){ 
        memset(child,0,sizeof(child)); 
        memset(f,0,sizeof(f)); 
        memset(l,0,sizeof(l)); 
        head=tail=tot=1; 
    } 
    void add(int c){ 
        int p=tail,np=++tot;l[np]=l[p]+1;tail=np; 
        for(;p&&!child[p][c];p=f[p]) child[p][c]=np; 
        if(!p) f[np]=head; 
        else if(l[child[p][c]]==l[p]+1) f[np]=child[p][c]; 
        else{ 
            int q=child[p][c],r=++tot; 
            memcpy(child[r],child[q],MAXC*sizeof(int)); 
            f[r]=f[q];l[r]=l[p]+1;f[q]=f[np]=r; 
            for(;p&&child[p][c]==q;p=f[p]) child[p][c]=r; 
        } 
    } 
    void insert(char*ch){ 
        int l=strlen(ch); 
        for(int i=0;i<l;i++) add(ch[i]-'a'); 
    } 
    void solve(char*ch){ 
        int len=strlen(ch); 
        int ws[MAXN]; 
        //������Ĺ��� 
        //����lֵ�������Ա������ͺ��� 
        for(int i=0;i<=len;i++) ws[i]=0;//������ʼ�� 
        for(int i=1;i<=tot;i++){ 
            ws[l[i]]++;//ͳ�� 
        } 
        for(int i=1;i<=len;i++){ 
            ws[i]+=ws[i-1];//ǰ׺�� 
        } 
        for(int i=tot;i>0;i--){//������     
            rk[ws[l[i]]--]=i;     
        } 
        for(int i=0,p=head;i<len;i++){ 
            int ip=ch[i]-'a'; 
            p=child[p][ip]; 
            sz[p]++;//û��ȡ���ַ������Լ������һ�μ��� 
        } 
        for(int i=tot;i>0;i--){ 
            ans[l[rk[i]]]=max(ans[l[rk[i]]],sz[rk[i]]); 
            sz[f[rk[i]]]+=sz[rk[i]]; 
        } 
        for(int i=1;i<=len;i++) 
        { 
            printf("%d\\n",ans[i]); 
        } 
    } 
}SAM; 
int main() 
{ 
    SAM.clear(); 
    scanf("%s",&ch); 
    SAM.insert(ch); 
    SAM.solve(ch); 
    return 0; 
}
