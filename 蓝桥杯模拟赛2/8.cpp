#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005],pre[100005],las[100005];

int gcd(int x ,int y){
	return y==0?x:gcd(y,x%y); 
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n<3){
		cout<<"0"<<endl;
		return 0;	
	}
	sort(a,a+n); 
	int sum = a[n-1]-a[0];
	int cnt = 0;
	for(int i=1;i<n;i++)
		b[i] = a[i]-a[i-1];
	
	//前缀后缀gcd
	int d = b[0];
	for(int i=1;i<n;i++){
		d = gcd(d,b[i]);
		pre[i] = d;	
	}
	d = b[n];
	for(int i=1;i<n;i++){
		d = gcd(d,b[n-i]);
		las[n-i] = d;	
	}
	//枚举删除每一个区间，即这个区间可以不管，其他区间全部变成相同的长度
	int inf = 0x3f3f3f3f;
	int ans = 0;
	for(int i=1;i<n;i++){
		if(i==1){
			ans = (sum-b[i])/las[2];
		}
		else if(i==n-2){
			ans = (sum-b[i])/pre[n-2];	
		}
		else{
			ans = (sum-b[i])/(gcd(pre[i-1],las[i+1]));			
		}
		inf = min(inf,ans-(n-2));
	}
	cout<<inf<<endl;
	return 0;	
}
