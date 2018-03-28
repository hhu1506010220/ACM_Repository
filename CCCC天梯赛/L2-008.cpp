#include<bits/stdc++.h>
using namespace std;

char s[1005];

int main(){
//	scanf("%s",s);
	cin.getline(s,1005);
	int len = strlen(s);
	int ans = 0;
	
	for(int i=0;i<len;i++){
		for(int j=0;j<=i&&i+j<len;j++){//ÆæÊı 
			if(s[i-j]!=s[i+j]){
				break;	
			}
			if(2*j+1>ans){
				ans = 2*j+1;	
			}
		}
		for(int j=0;j<=i&&i+j+1<len;j++){//Å¼Êı 
			if (s[i-j] != s[i+j+1]){
                break;
            }
            if (2*j+2 > ans){
                ans = 2*j+2;
            }
		}
	}
	printf("%d\n",ans); 
	return 0;
}
