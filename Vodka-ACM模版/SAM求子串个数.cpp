/**********************************/
/*	   						      */
/*		SAM后缀自动机             */
/*  求字符串[L,R]中不同子串的个数 */
/*							      */
/**********************************/
#include<bits/stdc++.h>
using namespace std;
const int maxl=2000;

int te,len,Q,ans[maxl+5][maxl+5];
char s[maxl+5];
struct SAM {
	static const int maxi=26;
	struct node {
		node *son[maxi],*fa;
		int MAX;
		int Count() {
			if (!fa) return 0;
			return MAX-fa->MAX;
		}
		//计算多出来的子串个数
	};
	typedef node* P_node;
	node tem[2*maxl+5];
	P_node pos,ro,lst;
	int tot;
	P_node newnode(int M) {
		pos->MAX=M;
		pos->fa=0;
		memset(pos->son,0,sizeof(pos->son));
		return pos++;
	}
	void clear() {
		pos=tem;
		ro=newnode(0);
		lst=ro;
		tot=0;
	}
	int Insert(char ch) {
		int ID=ch-'a';
		P_node p=lst,np=newnode(p->MAX+1);
		while (p&&!p->son[ID]) p->son[ID]=np,p=p->fa;
		if (!p) np->fa=ro,tot+=np->Count();
		else { //更新
			P_node q=p->son[ID];
			if (p->MAX+1==q->MAX) np->fa=q,tot+=np->Count();
			else { //更新
				P_node nq=newnode(p->MAX+1);
				memcpy(nq->son,q->son,sizeof(q->son));
				tot-=q->Count(); //q的father要改变了，先减去原个数
				nq->fa=q->fa;
				q->fa=nq;
				np->fa=nq;
				tot+=q->Count()+np->Count()+nq->Count(); //更新，加上q新的个数
				while (p&&p->son[ID]==q) p->son[ID]=nq,p=p->fa;
			}
		}
		lst=np;
		return tot;
	}
};
SAM sam;
int reads(char *s) {
	int len=0;
	char ch=getchar();
	if (ch==EOF) return EOF;
	while ('z'<ch||ch<'a') ch=getchar();
	s[++len]=ch;
	while ('a'<=s[len]&&s[len]<='z') s[++len]=getchar();
	s[len--]=0;
	return len;
}
int main() {
	scanf("%d",&te);
	while (te--) {
		len = reads(s);
		scanf("%d",&Q);
		for (int i=1; i<=len; i++) {
			sam.clear();
			for (int j=i; j<=len; j++)
				ans[i][j]=sam.Insert(s[j]);
		}
		while (Q--) {
			int x,y;
			scanf("%d",&x);
			scanf("%d",&y);
			printf("%d\n",ans[x][y]);
		}
	}
	return 0;
}
