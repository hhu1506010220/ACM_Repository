#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[10];
	while(~scanf("%s",s)){
		int h,m;
		h = (s[0]-'0')*10+(s[1]-'0');
		m = (s[3]-'0')*10+(s[4]-'0');
		int cnt = 0 ;
		if((h>=0&&h<12)||(h==12&&m==0)){
			printf("Only %s.  Too early to Dang.\n",s);
			continue;
		}
		else{
			if(m>0)
				cnt = h-12+1;
			else
				cnt = h-12;	
		}
		for(int i=0;i<cnt;i++){
			printf("Dang");
		}puts("");
	}
	return 0;	
}
