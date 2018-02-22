#include<bits/stdc++.h>
using namespace std;

char s[4][28]= {"QAZWSXEDCRFVTGBYHNUJMIKOLP",
                "QWERTYUIOPASDFGHJKLZXCVBNM",
                "QETUOADGJLZCBMWRYIPSFHKXVN",
                "ZYXWVUTSRQPONMLKJIHGFEDCBA",
               };
char ss[4][28]= {"QAZWSXEDCRFVTGBYHNUJMIKOLP",
                "QWERTYUIOPASDFGHJKLZXCVBNM",
                "QETUOADGJLZCBMWRYIPSFHKXVN",
                "ZYXWVUTSRQPONMLKJIHGFEDCBA",
               };
int main() {
	int t;
	scanf("%d",&t);
	char s_key[8];
	char s_aim[10005];
	int s_pos[4];//串的排列顺序
	int pos[4];//每个串的初始位置 pos[ABC-65]的初始位置 
	char zhuanzi[4][28];
	int cnt1=0,cnt2=0,cnt3=0;
	int temp =0;	
	while(t--) {
		cnt1=cnt2=cnt3=0;
		temp =0;
		memset(s,0,sizeof(s));
		memset(s_key,0,sizeof(s_key));
		memset(s_aim,0,sizeof(s_aim));
		memset(s_pos,0,sizeof(s_pos));
		memset(pos,0,sizeof(pos));
		memset(zhuanzi,0,sizeof(zhuanzi));
		for(int i=0;i<4;i++)
			for(int j=0;j<26;j++)
				s[i][j]=ss[i][j];
		scanf("%s",s_key);
		
		for(int i=0; i<3; i++) {
			s_pos[s_key[i]-65]=i;//s_pos[i]表示s[0]s[1]s[2]的出现位置分别是第(i、j、k) 
		}
		for(int j=3; j<6; j++) {//XYZ给出zhuanzi[0][1][2]各自的初始字母 
			for(int i=0; i<3; i++) {//遍历s[0][1][2]看哪个是第i个转子 
				if(s_pos[i]==j-3) {  
					for(int k=0; k<26; k++) {
						if(s[i][k]==s_key[j]){// 找到初始字母所在的位置 
							pos[i]=k;		  // pos[i]记录s[i]的初始位置下标 
							break;	
						}
					}
				}
			}
		}
		for(int i=0; i<3; i++) {//确定zhuanzi[0][1][2]分别是s[0][1][2]中的哪一个 
			for(int j=0; j<3; j++) {//遍历s[0][1][2] 看谁的出现的位置是0 1 2 
				if(s_pos[j]==i) {//找到了zhuanzi[i]对应的是s[j] 
					for(int k=0; k<26; k++) {//转动转子 使之准备就绪 
						zhuanzi[i][k]=s[j][(pos[j]+k)%26];
					}
				}
			}
		}
		scanf("%s",s_aim); 
		int ans =0;
		char res ;
		for(int j=0; j<strlen(s_aim); j++) {
			//密钥推s1
			ans = s_aim[j]-65;
			res = zhuanzi[0][ans];
			//s1推s2
			ans = res - 65;
			res = zhuanzi[1][ans];
			//s2推s3
			ans = res - 65;
			res = zhuanzi[2][ans];
			//s3推反射器
			//反射器推s3
			for(int i=0; i<26; i++) {
				if(s[3][i]==res) {
					ans = i;
				}
			}
			res = 'A'+ans;
			//s3推s2 
			for(int i=0; i<26; i++) {
				if(zhuanzi[2][i]==res) {
					ans = i;
				}
			}
			res = 'A'+ans;
			//s2推s1
			for(int i=0; i<26; i++) {
				if(zhuanzi[1][i]==res) {
					ans = i;
				}
			}
			res = 'A'+ans;
			//s1推原串
			for(int i=0; i<26; i++) {
				if(zhuanzi[0][i]==res) {
					ans = i;
				}
			}
			res = 'A'+ans;
			printf("%c",res); 
		    temp = zhuanzi[0][0];
			for(int i=1;i<=25;i++){
				zhuanzi[0][i-1] = zhuanzi[0][i];
			}
			zhuanzi[0][25] = temp;
			cnt1++;
			if(cnt1>=26){
				cnt2++;
			    temp = zhuanzi[1][0];
				for(int i=1;i<=25;i++){
					zhuanzi[1][i-1] = zhuanzi[1][i];
				}
				zhuanzi[1][25] = temp;
				if(cnt2>=26){
					cnt3++;
				    temp = zhuanzi[2][0];
					for(int i=1;i<=25;i++){
						zhuanzi[2][i-1] = zhuanzi[2][i];
					}
					zhuanzi[2][25] = temp;	
					cnt2=0;				
				}
				cnt1=0;
			}
		}
		puts("");
	}
	return 0;
}
