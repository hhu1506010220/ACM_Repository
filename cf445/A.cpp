#include<bits/stdc++.h>
using namespace std;

int a[7];

int main(){
	int sum=0;
	for(int i=0;i<6;i++){
		scanf("%d",&a[i]);
		sum+=a[i];	
	}
	bool flag = 1;
	sort(a,a+6);
	int sum1;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<6;k++){
				if(i!=j&&i!=k&&j!=k){
					sum1 = a[i]+a[j]+a[k];
					if(sum1*2==sum){
						cout<<"YES"<<endl;
						return 0;	
					}
				}
			}
		}
	}
	cout<<"NO"<<endl;
	return 0 ;
}
