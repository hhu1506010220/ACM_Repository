#include<bits/stdc++.h>
using namespace std;

long long zhunkao[1005],jishi[1005],kaoshi[1005];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>zhunkao[i]>>jishi[i]>>kaoshi[i];
	int m;
	cin>>m;
	int temp;
	while(m--){
		cin>>temp;
		for(int i=0;i<n;i++){
			if(jishi[i]==temp){
				cout<<zhunkao[i]<<" "<<kaoshi[i]<<endl;
				break;			
			}
		}
		
	}
	return 0;
}
