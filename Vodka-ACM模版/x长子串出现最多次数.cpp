/**********************************/
/*		给一个字符串S，			  */
/* F(x)表示S的所有长度为x的子串中 */
/*  出现次数的最大值。            */
/*  求F(1)..F(Length(S)) 。       */
/**********************************/
#include<bits/stdc++.h> 
#define MAXN 500010+5 
#define MAXC 26 
using namespace std; 
char ch[MAXN];//输入字符串 
int rk[MAXN],sz[MAXN],ans[MAXN]; 
struct Suffix_Automaton{ 
    int child[MAXN][MAXC]; 
    int f[MAXN];//指向最近的接受态 
    int l[MAXN];//此节点代表的最长串的长度 
    int head,tail,tot;//头节点,最后的接受态,总节点 
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
        //拓扑序的过程 
        //先以l值排序，再以编号排序就好了 
        for(int i=0;i<=len;i++) ws[i]=0;//计数初始化 
        for(int i=1;i<=tot;i++){ 
            ws[l[i]]++;//统计 
        } 
        for(int i=1;i<=len;i++){ 
            ws[i]+=ws[i-1];//前缀和 
        } 
        for(int i=tot;i>0;i--){//拓扑序     
            rk[ws[l[i]]--]=i;     
        } 
        for(int i=0,p=head;i<len;i++){ 
            int ip=ch[i]-'a'; 
            p=child[p][ip]; 
            sz[p]++;//没截取的字符串有自己本身的一次计数 
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
