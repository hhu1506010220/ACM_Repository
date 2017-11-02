/**********************************/
/*		给定两个字符串 A 和 B	  */
/* 求长度不小于 k 的公共子串的个数*/
/**********************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int n,lena;
char a[maxn];
typedef pair<char,int> pii;
int A[maxn],B[maxn];
int realrank[maxn],k;
pii st[maxn];
int s[maxn][2];
long long h[maxn];
int K;
int C[maxn],D[maxn];

void init() {
	scanf("%s",a+1);
	lena = strlen(a+1);
	a[lena+1] = '#';
	scanf("%s",a+lena+2);
	n = strlen(a+1);
	//cout << n<<a+1<<endl;
	for(int i = 1; i <= n ; i++) {
		st[i] = make_pair(a[i],i);
	}

	sort(st+1,st+1+n);
	k = realrank[st[1].second] = 1;
	for(int i = 2; i <= n ; i++) {
		if(st[i].first != st[i-1].first)
			k +=1;
		realrank[st[i].second] = k;
	}
}
void suffix_array() {
	for(int i = 1; i <= n ; i *= 2) {
		for(int j = 0 ; j <= n ; j++)
			A[j] = B[j] = 0;
		for(int j = 1;  j <= n ; j++) {
			A[s[j][0] = realrank[j]]++;
			if(j+i <= n)
				s[j][1] = realrank[j+i];
			else    s[j][1] = 0;
			B[s[j][1]]++;
		}
		for(int j = 1; j <= n ; j++)
			A[j] += A[j-1],B[j] += B[j-1];
		for(int j = n ; j >= 1; j--) {
			C[B[s[j][1]]] = j;
			B[s[j][1]]--;
		}
		for(int j = n ; j >=1; j--) {
			D[A[s[C[j]][0]]] = C[j];
			A[s[C[j]][0]]--;
		}
		k = realrank[D[1]] = 1;
		for(int j = 2 ; j <= n ; j++) {
			if(s[D[j]][0] != s[D[j-1]][0] ||s[D[j]][1] != s[D[j-1]][1])
				k++;
			realrank[D[j]] = k;
		}
	}
}
void gethigh() {
	int pre = 0,j;
	for(int i = 1; i <= n ; i++) {
		if(pre) pre--;
		j = D[realrank[i]-1];
		while(i+pre <= n && j + pre <= n && a[i+pre] == a[j+pre])
			pre++;
		h[realrank[i]] = pre;
	}
}
struct node {
	long long cnt,height;
} stka[maxn],stkb[maxn];

long long ans ,tot;
int topa ,topb,taila,tailb;

void sov() {
	ans = topa = topb = taila = tailb = tot = 0;
	for(int i = 2; i <= n ; i++) {
		if(h[i] < K) {
			topa = topb = taila = tailb = 0;
			tot = 0;
		} else {
			int num = 0;
			if(D[i-1] <= lena) {
				num++;
				tot += h[i] - K +1;
			}
			while(taila > topa && stka[taila-1].height >= h[i]) {
				taila--;
				tot -= stka[taila].cnt*(stka[taila].height-h[i]);
				num += stka[taila].cnt;
			}

			stka[taila].height = h[i];
			stka[taila].cnt = num;
			taila++;
			if(D[i] > lena) {
				ans += tot;
			}
		}
	}
	topa = topb = taila = tailb = tot = 0;
	for(int i = 2; i <= n ; i++) {
		if(h[i] < K) {
			topa = topb = taila = tailb = 0;
			tot = 0;
		} else {
			int num = 0;
			if(D[i-1] > lena+1) {
				num++;
				tot += h[i] - K +1;
			}
			while(taila > topa && stka[taila-1].height >= h[i]) {
				taila--;
				tot -= stka[taila].cnt*(stka[taila].height-h[i]);
				num += stka[taila].cnt;
			}
			stka[taila].height = h[i];
			stka[taila].cnt = num;
			taila++;
			if(D[i] <= lena) {
				ans += tot;
			}
		}
	}
	printf("%lld\n",ans);
}

int main() {
	while(~scanf("%d",&K)&&K) {
		init();
		suffix_array();
		gethigh();
		sov();
	}
}
