/**********************************/
/*	      给出一个字符串	      */
/*    求其字典序排名第k的子串     */
/**********************************/
#include <bits/stdc++.h>
using namespace std;
const int N=500005;
char s[N];
struct sam {
	int p,q,np,nq,cnt,last,a[N][26],l[N],f[N];
	sam() {
		cnt=0;
		last=++cnt;
	}
	void extend(int c) {
		p=last;
		np=last=++cnt;
		l[np]=l[p]+1;
		while(!a[p][c]&&p)a[p][c]=np,p=f[p];
		if(!p)f[np]=1;
		else {
			q=a[p][c];
			if(l[p]+1==l[q])f[np]=q;
			else {
				nq=++cnt;
				l[nq]=l[p]+1;
				memcpy(a[nq],a[q],sizeof(a[q]));
				f[nq]=f[q];
				f[np]=f[q]=nq;
				while(a[p][c]==q)a[p][c]=nq,p=f[p];
			}
		}
	}
	int b[N],x[N],mx[N];
	void build() {
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=1; i<=len; i++)extend(s[i]-'a');
		for(int i=1; i<=cnt; i++)b[l[i]]++;
		for(int i=1; i<=len; i++)b[i]+=b[i-1];
		for(int i=1; i<=cnt; i++)x[b[l[i]]--]=i;
		for(int i=cnt; i; i--) {
			mx[x[i]]=1;
			for(int j=0; j<26; j++)mx[x[i]]+=mx[a[x[i]][j]];
		}
	}
	void query(int k) {
		p=1;
		while(k) {
			for(int i=0; i<26; i++)if(a[p][i]) {
					if(mx[a[p][i]]>=k) {
						putchar('a'+i);
						p=a[p][i];
						--k;
						break;
					} else k-=mx[a[p][i]];
				}
		}
		puts("");
	}
} sam;
int main() {
	sam.build();
	int Q,x;
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d",&x);
		sam.query(x);
	}
	return 0;
}
