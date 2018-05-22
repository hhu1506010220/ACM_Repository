#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){cin>>b[i];a[i]=b[i];}
	if(n==1||n==2){
		cout<<"0"<<endl;
		return 0;
	}
	int maxn = 999999999+5;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			b[1]+=i;
			b[2]+=j;
			int d = b[2]-b[1];
			int cnt = 3;
			bool flag = 1;
			int sum = 0;
			if(i!=0)sum++;
			if(j!=0)sum++;
			while(cnt<=n){
				b[cnt] = b[cnt-1]+d;
				if(abs(b[cnt]-a[cnt])>1){
					flag = 0;
					break;	
				}
				else if(b[cnt]!=a[cnt]){
					sum++;
				}
				cnt++;
			}
			for(int k=1;k<=n;k++)b[k]=a[k];
			if(!flag){
				continue;	
			}
			else{
//				cout<<i<<" "<<j<<" "<<sum<<endl;
				maxn = min(sum,maxn);
			}
		}
	}
	if(maxn==999999999+5)cout<<"-1"<<endl;
	else cout<<maxn<<endl;
	return 0;	
}
