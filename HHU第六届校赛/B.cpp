#include<bits/stdc++.h>
using namespace std;

char s[100005];

int main(){
	int posa[5],posb[5];
	int cnta,cntb;
	while(~scanf("%s",s)){
		cnta=cntb=0;
		bool flag1=1,flag2=1;
		memset(posa,0,sizeof(posa));
		memset(posb,0,sizeof(posb));
		for(int i=0;i<strlen(s);i++){
			if(s[i]=='A'&&s[i+1]=='L'&&s[i+2]=='I'&&s[i+3]=='C'&&s[i+4]=='E'){
				if(!cnta){
					posa[0]=i;
					posa[1]=i+4;
				}
				posa[2]=i;
				posa[3]=i+4;
				cnta++;
			}
			if(s[i]=='B'&&s[i+1]=='O'&&s[i+2]=='B'){
				if(!cntb){
					posb[0]=i;
					posb[1]=i+2;
				}
				posb[2]=i;
				posb[3]=i+2;
				cntb++;
			}				
		}
		if(posa[0]==0&&posa[1]==0){
			flag1 = 0;	
		}
		if(posb[0]==0&&posb[1]==0){
			flag2 = 0;	
		}
		if(!flag1||!flag2){
			printf("-1\n");			
		}
		else{
			printf("%d\n",max(posa[2]-posb[1]-1,posb[2]-posa[1]-1));			
		}
	}
	return 0;
}
