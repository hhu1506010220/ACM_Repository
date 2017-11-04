#include<bits/stdc++.h>
using namespace std;

int a[55];

int main(){
	set<int>s;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n*2;i++){
		scanf("%d",&a[i]);	
	}
	a[2*n]=0;
	sort(a,a+2*n);
	for(int i=0;i<2*n;i++){
		if(a[i]==a[i+1]){
			i+=1;
		}
		else{
			s.insert(a[i]);	
		}
	}
    long long ans =88888888;
    for(int i=0;i<n*2;i++){
    	for(int j=i+1;j<n*2;j++){
    		int temp = 0;
    		long long sum =0;
    		int cnt=0;
    		for(int k = 0;k<n*2;k++){
				if(k!=i&&k!=j){
					cnt++;
					if(cnt%2==1){
						temp =k;	
					}
					if(cnt%2==0){
						sum += a[k]-a[temp]	;
					}
				}
			}
			if(sum<ans)ans=sum;
		}
    }
    cout<<ans<<endl;
}
