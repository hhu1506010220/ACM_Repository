#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],k,n,d;
int s[N],t[N];
int main(){
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1);
	s[0]=1;//�������λ�ò�����Ч�ķ����� ����ǰ���� 
	t[1]=-1;//���������չ����λ�õĽ��ĸ��� Ϊ��������Ҫǰ����-i���������䵽��λ�� ����󿴣� 
	int pos=1;
	for(int i=1;i<=n;++i){
		while(pos<n&&a[pos+1]-a[i]<=d)++pos;//�ҵ���������d��Χ�ڵ����һ������λ�� 
		if(s[i-1]&&i-1+k<=pos)++t[i-1+k],--t[pos+1];
		//����а취����ǰһ��λ�ã�����ǰһ��λ��֮���k����Ҳ��pos��Χ֮�ڣ���λ��++�����ﲻ�����Ǹ�λ��-- 
//		cout<<a[i]<<" "<<t[i]<<endl; 
		s[i]=s[i-1]+t[i];
	}
	// 3 4 4 5 10 13 
//	for(int i=1;i<=n;i++)cout<<s[i]<<" ";cout<<endl; 
	puts(s[n]>0?"YES":"NO");
    return 0;
}
