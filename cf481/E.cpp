#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,w;
	int cur;
	cin>>n>>w;
	int sum=0;
	int maxn=0;
	int minn=0;
	for(int i=0; i<n; i++) {
		cin>>cur;
		sum+=cur;
		maxn=max(sum,maxn);// ������������
		minn=min(minn,sum);// ������������
	}
	if(maxn>w||minn<-w)
		cout<<"0"<<endl;
	else {
		if(maxn<0) //���maxnС��0 ��ʾһֱ�������ˣ����Գ�ʼ������ |minn|~w��|maxn|~w�Ľ��� 
			cout<<minn+w+1<<endl;
		else if(minn<0) {
			//���maxn>0minn<0��minn��ʾԭʼ������|min|~w��maxn��ʾԭʼ������0~|w-maxn|�������󽻼� 
			if(w-maxn-abs(minn)>=0)
				cout<<w-maxn-abs(minn)+1<<endl;
			else
				cout<<"0"<<endl;
		} else {
			cout<<w-maxn+1<<endl;
		}
	}
	return 0;
}
