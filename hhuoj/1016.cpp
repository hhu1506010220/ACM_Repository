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
	int s_pos[4];//��������˳��
	int pos[4];//ÿ�����ĳ�ʼλ�� pos[ABC-65]�ĳ�ʼλ�� 
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
			s_pos[s_key[i]-65]=i;//s_pos[i]��ʾs[0]s[1]s[2]�ĳ���λ�÷ֱ��ǵ�(i��j��k) 
		}
		for(int j=3; j<6; j++) {//XYZ����zhuanzi[0][1][2]���Եĳ�ʼ��ĸ 
			for(int i=0; i<3; i++) {//����s[0][1][2]���ĸ��ǵ�i��ת�� 
				if(s_pos[i]==j-3) {  
					for(int k=0; k<26; k++) {
						if(s[i][k]==s_key[j]){// �ҵ���ʼ��ĸ���ڵ�λ�� 
							pos[i]=k;		  // pos[i]��¼s[i]�ĳ�ʼλ���±� 
							break;	
						}
					}
				}
			}
		}
		for(int i=0; i<3; i++) {//ȷ��zhuanzi[0][1][2]�ֱ���s[0][1][2]�е���һ�� 
			for(int j=0; j<3; j++) {//����s[0][1][2] ��˭�ĳ��ֵ�λ����0 1 2 
				if(s_pos[j]==i) {//�ҵ���zhuanzi[i]��Ӧ����s[j] 
					for(int k=0; k<26; k++) {//ת��ת�� ʹ֮׼������ 
						zhuanzi[i][k]=s[j][(pos[j]+k)%26];
					}
				}
			}
		}
		scanf("%s",s_aim); 
		int ans =0;
		char res ;
		for(int j=0; j<strlen(s_aim); j++) {
			//��Կ��s1
			ans = s_aim[j]-65;
			res = zhuanzi[0][ans];
			//s1��s2
			ans = res - 65;
			res = zhuanzi[1][ans];
			//s2��s3
			ans = res - 65;
			res = zhuanzi[2][ans];
			//s3�Ʒ�����
			//��������s3
			for(int i=0; i<26; i++) {
				if(s[3][i]==res) {
					ans = i;
				}
			}
			res = 'A'+ans;
			//s3��s2 
			for(int i=0; i<26; i++) {
				if(zhuanzi[2][i]==res) {
					ans = i;
				}
			}
			res = 'A'+ans;
			//s2��s1
			for(int i=0; i<26; i++) {
				if(zhuanzi[1][i]==res) {
					ans = i;
				}
			}
			res = 'A'+ans;
			//s1��ԭ��
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
