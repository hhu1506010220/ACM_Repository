/**********************************/
/*  		  SA求不重叠		  */
/*  求出现两次且不重叠的子串种类  */
/**********************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1005
#define INF 0xfffff
#define MAXM 27
int wa[MAXN], wb[MAXN], ws[MAXN], wv[MAXN];
char s[MAXN];
int str[MAXN], sa[MAXN];
int height[MAXN], rank[MAXN];

int max(int a, int b) {
	return a>b ? a:b;
}

int min(int a, int b) {
	return a<b ? a:b;
}

int cmp(int *r, int a, int b, int l) {
	return r[a]==r[b] && r[a+l]==r[b+l];
}

void da(int *r, int *sa, int n, int m) {
	int i, j, *x = wa, *y = wb, *t;
	int p;

	for (i=0; i<m; ++i) ws[i] = 0;
	for (i=0; i<n; ++i) ws[x[i]=r[i]]++;
	for (i=1; i<m; ++i) ws[i] += ws[i-1];
	for (i=n-1; i>=0; --i) sa[--ws[x[i]]] = i;
	for (j=1, p=1; j<n; j*=2, m=p) {
		for (p=0, i=n-j; i<n; ++i) y[p++] = i;
		for (i=0; i<n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i=0; i<n; ++i) wv[i] = x[y[i]];
		for (i=0; i<m; ++i) ws[i] = 0;
		for (i=0; i<n; ++i) ws[wv[i]]++;
		for (i=1; i<m; ++i) ws[i] += ws[i-1];
		for (i=n-1; i>=0; --i) sa[--ws[wv[i]]] = y[i];
		for (t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; ++i)
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
	}
}

void calheight(int *r, int *sa, int n) {
	int i, j, k = 0;
	for (i=1; i<=n; ++i) rank[sa[i]] = i;
	for (i=0; i<n; height[rank[i++]]=k)
		for (k? --k:0, j=sa[rank[i]-1]; r[i+k]==r[j+k]; ++k)
			/*do nothing*/;
}

int getRepeat(int len, int n) {
	int i, maxx, minn;
	int ret = 0;
	maxx = -1;
	minn = INF;
	for (i=1; i<=n; ++i) {
		if (height[i] >= len) {
			maxx = max(sa[i], max(sa[i-1], maxx));
			minn = min(sa[i], min(sa[i-1], minn));
		} else {
			if (maxx!=-1 && minn!=INF && (maxx-minn)>=len)
				++ret;
			maxx = -1;
			minn = INF;
		}
	}
	if (maxx!=-1 && minn!=INF && (maxx-minn)>=len)
		++ret;
	return ret;
}

void printRank(int n) {
	int i;
	printf("print rank...\n");
	for (i=1; i<=n; ++i)
		printf("%d ", rank[i]);
	printf("\n");
}

void printHeight(int n) {
	int i;
	printf("print height...\n");
	for (i=1; i<=n; ++i)
		printf("%d ", height[i]);
	printf("\n");
}

void printSa(int n) {
	int i;
	printf("print sa...\n");
	for (i=0; i<=n; ++i)
		printf("%d ", sa[i]);
	printf("\n");
}

int main() {
	int i, len;
	int ans;
	while (scanf("%s",s)!=EOF && (s[0]!='#')) {
		//printf("%s\n", s);
		for (i=0; s[i]; ++i)
			str[i] = s[i] - 'a' + 1;
		str[i] = 0;
		len = i;
		da(str, sa, len+1, MAXM);
		calheight(str, sa, len);
#ifndef ONLINE_JUDGE
		printSa(len);
		printRank(len);
		printHeight(len);
#endif
		for (ans=0, i=1; i<=len/2; ++i) {
			ans += getRepeat(i, len);
		}
		printf("%d\n", ans);
	}

	return 0;
}
