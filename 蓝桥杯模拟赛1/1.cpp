#include<bits/stdc++.h>
using namespace std;

int main(){
	int a1,a2,b1,b2;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				for(int l=0;l<10;l++){
					a1 = i*10+j;
					a2 = i+j;
					b1 = k*10+l;
					b2 = k+l;
					if(b1==3*a2&&a1==2*b2){
						cout<<a1<<" "<<b1<<endl;
					}
				}
			}
		}
	}
	return 0;
}
