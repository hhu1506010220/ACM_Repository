#include<iostream>
using namespace std;
int n,k,x,ans[300],v[300];
//v表示每个数的前面可以有多少个数 
int main() {
	cin>>n>>k;
	for(int i=0; i<=256; i++)
		ans[i]=-1;
	for(int i=1; i<=n; i++) {
		cin>>x;
		if(ans[x]!=-1)
			cout<<ans[x]<<" ";
		else {
			int pos;
			for(pos=x; pos>=max((x-k+1),0); pos--) {
				if(ans[pos]!=-1) {
					if(v[pos]+(x-pos)<=k)
						pos=x-(v[pos]+(x-pos)-1);
					else
						break;
				}
			}
			pos++;
			int max_pre_pos=pos;
			for(pos=max_pre_pos; pos<=x; pos++) {
				v[pos]=pos-max_pre_pos+1;
				ans[pos]=max_pre_pos;
			}
			cout<<ans[x]<<" ";
		}
	}cout<<endl;
	for(int i=1;i<=n;i++)cout<<v[i]<<" ";cout<<endl;
	return 0;
}
