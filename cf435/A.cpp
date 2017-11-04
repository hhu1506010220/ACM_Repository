
 #include<bits/stdc++.h>
using namespace std;

int a[200]={0};

int main(){
	int n , x;
	cin>>n>>x;
	int tem;
	for(int i=1;i<=n;i++){
		cin>>tem;
		a[tem]=1;
	}
	int cnt =0;
	for(int i=0;i<=100;i++){
		if(i==x){
			if(a[i]==1){
				cnt++;
				break;	
			}
			else{
				break;	
			}
		}
		else if(i<x&&a[i]!=1){
			cnt++;
		}
	}
	cout<<cnt<<endl;
}
