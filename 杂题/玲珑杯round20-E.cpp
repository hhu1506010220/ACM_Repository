#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400010;
const int M = MAXN * 30;
int n,q,m,tot;
int a[MAXN], t[MAXN];
int T[MAXN], lson[M], rson[M], c[M];

void Init_hash()
{
    for(int i = 1; i <= n; i++)
        t[i] = a[i];
    sort(t+1,t+1+n);
    m = unique(t+1,t+1+n)-t-1;
}
int build(int l,int r)
{
    int root = tot++;
    c[root] = 0;
    if(l != r) {
        int mid = (l+r)>>1;
        lson[root] = build(l,mid);
        rson[root] = build(mid+1,r);
    }
    return root;
}

int update(int root,int pos,int val)
{
    int newroot = tot++, tmp = newroot;
    c[newroot] = c[root] + val;
    int l = 1, r = m;
    while(l < r) {
        int mid = (l+r)>>1;
        if(pos <= mid) {
            lson[newroot] = tot++;
            rson[newroot] = rson[root];
            newroot = lson[newroot];
            root = lson[root];
            r = mid;
        } else {
            rson[newroot] = tot++;
            lson[newroot] = lson[root];
            newroot = rson[newroot];
            root = rson[root];
            l = mid+1;
        }
        c[newroot] = c[root] + val;
    }
    return tmp;
}

int getsum(int left_root,int right_root,int x)
{
    if (x==0) return 0;
    int l = 1, r = m;
    int res = 0;
    while( l < r) {
        int mid=(l+r)>>1;
        if (mid<=x) {
            res+=c[lson[left_root]]-c[lson[right_root]];
            l=mid+1;
            left_root = rson[left_root];
            right_root = rson[right_root];
        } else {
            r=mid;
            left_root = lson[left_root];
            right_root = lson[right_root];
        }
    }
    return res;
}

int getkth(int left_root,int right_root,int k)
{
    int l = 1, r = m;
    while( l < r) {
        int mid = (l+r)>>1;
        if (c[left_root]-c[right_root] < k || k == 0) return -1;
        if (c[lson[left_root]]-c[lson[right_root]] >= k ) {
            r = mid;
            left_root = lson[left_root];
            right_root = lson[right_root];
        } else {
            l = mid + 1;
            k -= c[lson[left_root]] - c[lson[right_root]];
            left_root = rson[left_root];
            right_root = rson[right_root];
        }
    }
    return l;
}

namespace fastIO {
	#define BUF_SIZE 10000000
	//fread -> read
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if(p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if(pend == p1) {
				IOerror = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch) {
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	inline void read(int &x) {
		char ch;
		while(blank(ch = nc()));
		if(IOerror)
			return;
		for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
	}
	#undef BUF_SIZE
};

int main()
{
    using namespace fastIO;
    read(n);read(q);
    tot = 0;
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    Init_hash();
    T[n+1] = build(1,m);
    for (int i = n; i ; i--) {
        int pos = lower_bound(t+1,t+1+m,a[i])-t;
        T[i] = update(T[i+1],pos,1);
    }
    while (q--) {
        int l,r,x,k1,k2;
        read(l);read(r);read(x);read(k1);read(k2);
        x=upper_bound(t+1,t+1+m,x)-t-1;
        int s=getsum(T[l],T[r+1],x);
        int a=getkth(T[l],T[r+1],k1);
        if (a > x) a=-1;
        if (a!=-1) a=t[a];
        int b=getkth(T[l],T[r+1],s + k2);
        if (b!=-1) b=t[b];
        printf("%d %d\n",a,b);
    }
    return 0;
}
