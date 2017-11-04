#include<bits/stdc++.h>
using namespace std;

struct aa {
	long long  c;
	long long poss;
	long long pos;
} a[300005];

bool cmp(aa x , aa y) {
	if(x.c!=y.c)	return x.c>y.c;
	else if(x.c==y.c&&x.pos!=y.pos)return x.pos>y.pos;
}

bool cmp1(aa x , aa y) {
	if(x.pos!=y.pos)	return x.pos<y.pos;
}

int main() {
	long long n,k;
	while(cin>>n>>k) {
		for(int i=1; i<=n; i++) {
			cin>>a[i].c;
			a[i].pos=i;
		}
		sort(a+1,a+n+1,cmp);
		long long sum =0;
		set <long long> res;
		set <long long> ::iterator x;
		for(int i =k+1; i<=k+n+1; i++)
			res.insert(i);
		for(int i =1; i<=n; i++) {
			x = res.lower_bound(a[i].pos);
			long long temp = *x;
			a[i].poss = temp;
			res.erase(temp);
			sum+=a[i].c*((temp-a[i].pos));
		}
		sort(a+1,a+n+1,cmp1);
		cout<<sum<<endl;
		for(int i=1; i<n; i++) {
			cout<<a[i].poss<<" ";
		}
		cout<<a[n].poss<<endl;
	}
	return 0;
}
