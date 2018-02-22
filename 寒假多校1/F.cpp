#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	int a,b,c;
	scanf("%d",&t);
	int blood  = 100;
	while(t--){
		bool flag = 1;
		blood = 100;
		int t = 0;
		scanf("%d%d%d",&a,&b,&c);
		while(1){
			if(b<=0){
				break;	
			}
			if(blood<=a*7&&c>0){
				blood -= 6*a;
				if(blood <= 0){
					flag = 0;
					break;	
				}
				blood = 80;
				c--;
				t+=6;
			}
			else{
				b-=1;
				if(b<=0)break;
				blood -= a;					
				t++;
			}	
			if(blood<=0){
				flag = 0;
				break;
			}
//			cout<<t<<" "<<blood<<" "<<b<<" "<<c<<endl;
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;	
}
