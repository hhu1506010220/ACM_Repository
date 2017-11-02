/**********************************/
/*  		  SA求不重叠		  */
/*   连续重复出现次数最多的子串   */
/**********************************/
#include<bits/stdc++.h>
#define N 200020
char s1[200020];
int ws[N],wv[N];
int sa[N],r[N],wx[N],wy[N];
int height[N];
int f[100010][17];
int min(int x,int y) {
	return x<y?x:y;
}
int max(int x,int y) {
	return x<y?y:x;
}
bool cmp(int *r,int a,int b,int l) {
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int n,int m) {
	//注意，这里的n必须比原始数组大小大1
	int *x=wx,*y=wy;
	for(int i=0; i<m; i++) ws[i]=0;
	for(int i=0; i<n; i++) ws[x[i]=r[i]]++;
	for(int i=1; i<m; i++) ws[i]+=ws[i-1];
	for(int i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;
	//这里的x[i] 表示下标i的第一关键字排名
	int i,j,p,*t;
	for(j=1,p=1; p<n; j*=2,m=p) {
		for(p=0,i=n-j; i<n; i++) y[p++]=i;
		for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		//此时的y[i] 表示第二关键字排第i的下标是y[i]
		for(i=0; i<n; i++) wv[i]=x[y[i]];
		for(i=0; i<m; i++) ws[i]=0;
		for(i=0; i<n; i++) ws[wv[i]]++;
		for(i=1; i<m; i++) ws[i]+=ws[i-1];
		for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i];
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
	for(int i=0; i<n; i++) {
		r[sa[i]]=i;
	}
}
void calHeight(int n) {
	int h=0;
	for(int i=0; i<n; i++) {
		if(r[i]==0) h=0;
		else {
			int k=sa[r[i]-1];
			if(--h<0) h=0;
			while(s1[k+h]==s1[i+h]) h++;
		}
		height[r[i]]=h;
	}
}
void RMQ(int n) {
	for(int j=0; j<n; j++) f[j][0]=height[j];
	for(int i=1; i<20; i++) {
		for(int j=0; j<n; j++) {
			if(j+(1<<i)-1 < n) {
				f[j][i]=min(f[j][i-1],f[j+(1<<i-1)][i-1]);
			}
		}
	}
}
int look(int x,int y) {
	x=r[x];
	y=r[y];
	if(x>y) x^=y^=x^=y;
	x++;
	int k=(int)log2((double)(y-x+1));
	return min(f[x][k],f[y-(1<<k)+1][k]);
}

bool cmp(int sl,int l) {
	if(r[sl]>r[l]) return 1;
	return 0;
}

void solve(int n) {
	int maxt=0,sl=0,sr=0;
	for(int i=1; i<=n/2; i++) {
		for(int j=0; j+i<n; j+=i) {
			int l=j;
			int r=j+i;
			int lcp=look(l,r);
			int d=lcp/i+1;
			int t=j-(i-lcp%i);
			for(int k=l-1; k>=0&&k+i>j&&s1[k]==s1[k+i]; k--) {
				if(k==t) {
					d++;
					l=k;
				} else if(cmp(l,k)) {
					l=k;
				}
			}
			if(d>maxt) {
				sl=l;
				sr=l+d*i-1;
				maxt=d;
			} else if(d==maxt&&cmp(sl,l)) {
				sl=l;
				sr=l+d*i-1;
			}
		}
	}
	for(int i=sl; i<=sr; i++) {
		printf("%c",s1[i]);
	}
	printf("\n");
}

int main() {
	int cas=1;
	while(scanf("%s",s1)!=EOF) {
		if(s1[0]=='#') break;
		int len=strlen(s1);
		for(int i=0; i<len; i++)
			r[i]=s1[i]-'a'+1;
		r[len++]=0;
		da(r,len,27);
		calHeight(len);
		RMQ(len);
		printf("Case %d: ",cas++);
		solve(len-1);
	}
	return 0;
}
