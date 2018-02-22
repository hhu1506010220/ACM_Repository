#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[20];
	scanf("%s",s);
	int tem = 1;
	int sum = 0;
	for(int i=0;i<11;i++){
		if(i==1||i==5)
			continue;
		sum += (s[i]-'0')*(tem++);
	}
	sum %= 11;
	bool flag = 1;
	if(sum==10){
		if(s[12]!='X'){
			flag = 0;
			s[12]='X';			
		}
	}
	else if(s[12]-'0'!=sum){
		flag = 0;
		s[12]=sum+'0';	
	}
		
	if(flag) puts("Right");
	else printf("%s\n",s);
	
	return 0;	
}
