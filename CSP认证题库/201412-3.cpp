#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5007
typedef struct {
	string m;
	double p;
	int s;
	bool e;
} R;
R r[MAX];
set<double> st;
int main() {
	int m=0;
	while(cin>>r[m].m) {
		if(r[m].m == "cancel") {
			cin>>r[m].s;
			r[r[m].s-1].e=true;
			m++;
			continue;
		}
		cin>>r[m].p>>r[m].s;
		++m;
	}
	for(int i=0; i<m; ++i)
		if(r[i].m != "cancel" && !r[i].e)st.insert(r[i].p);

	ll m_sum=0;
	double p=0;
	for(set<double>::iterator it=st.begin(); it!=st.end(); ++it) {
		double p0 = *it;
		ll sumb=0,sums=0,sum;
		for(int i=0; i<m; ++i)
			if(r[i].m == "sell" && !r[i].e && r[i].p<=p0)sums+=r[i].s;
		for(int i=0; i<m; ++i)
			if(r[i].m == "buy" && !r[i].e && r[i].p>=p0)sumb+=r[i].s;
		sum=min(sums,sumb);

		if(sum>=m_sum) {
			m_sum=sum;
			p=p0;
		}
	}
	printf("%.2f ",p);
	cout<<m_sum<<endl;
	return 0;
}
