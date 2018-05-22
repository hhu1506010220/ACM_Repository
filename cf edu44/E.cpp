#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],k,n,d;
int s[N],t[N];
int main(){
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1);
	s[0]=1;//代表到达该位置并且有效的方法数 （向前看） 
	t[1]=-1;//代表可以扩展到该位置的结点的个数 为负代表需要前面有-i个结点可扩充到该位置 （向后看） 
	int pos=1;
	for(int i=1;i<=n;++i){
		while(pos<n&&a[pos+1]-a[i]<=d)++pos;//找到所有在他d范围内的最后一个数的位置 
		if(s[i-1]&&i-1+k<=pos)++t[i-1+k],--t[pos+1];
		//如果有办法到达前一个位置，并且前一个位置之后的k个数也在pos范围之内，该位置++，到达不到的那个位置-- 
//		cout<<a[i]<<" "<<t[i]<<endl; 
		s[i]=s[i-1]+t[i];
	}
	// 3 4 4 5 10 13 
//	for(int i=1;i<=n;i++)cout<<s[i]<<" ";cout<<endl; 
	puts(s[n]>0?"YES":"NO");
    return 0;
}
