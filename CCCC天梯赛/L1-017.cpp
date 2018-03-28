#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[51];
	scanf("%s",s);
	int zf = 1;
	int weishu = 0;
	int oushu = 0;
	int _two = 0;
	if (s[0]=='-'){
		for(int i=1;i<strlen(s);i++){
			if(s[i]=='2')
				_two ++;
		}
		if((s[strlen(s)-1]-'0')%2==0)
			oushu = 1;
		weishu = strlen(s)-1;
		zf = 0;
	}
	else{
		for(int i=0;i<strlen(s);i++){
			if(s[i]=='2')
				_two ++;
		}
		if((s[strlen(s)-1]-'0')%2==0)
			oushu = 1;
		weishu = strlen(s);
	}	
	double b1,b2;
	if(zf)b1 = 1;else b1 = 1.5;
	if(oushu)b2 = 2;else b2 = 1;
	double ans = (double)_two*1.0/(double)weishu*1.0*b1*b2*100.0;
	printf("%.2f%\n",ans);
	return 0;	
}
