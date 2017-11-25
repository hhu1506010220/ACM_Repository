#include<bits/stdc++.h>
using namespace std;

char s[4][28]= {"QAZWSXEDCRFVTGBYHNUJMIKOLP",
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
	int pos[4];//每个串的初始位置
	char zhuanzi[4][28];
	int cnt1=0,cnt2=0,cnt3=0;
	int temp =0;	
	while(t--) {
		memset(s_key,0,sizeof(s_key));
		memset(s_aim,0,sizeof(s_aim));
		memset(s_pos,0,sizeof(s_pos));
		memset(pos,0,sizeof(pos));
		scanf("%s",s_key);
		for(int i=0; i<3; i++) {
			s_pos[s_key[i]-65]=(i+1);//A、B、C的出现位置分别是s_pos[0、1、2]
		}
		for(int j=3; j<6; j++) {
			for(int i=0; i<3; i++) {
				if(s_pos[i]==j-2) {
					for(int k=0; k<26; k++) {
						if(s[i][k]==s_key[j])
							pos[i]=k;
					}
				}
			} //出现位置为j的串的初始指针指向哪里
		}
		scanf("%s",s_aim);
//		int len = strlen(s_aim);
//		for(int i=0;i<3;i++)cout<<s_pos[i]<<endl;
//		cout<<len<<endl;
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				if(s_pos[j]==i+1) {
					for(int k=0; k<26; k++) {
						zhuanzi[i][k]=s[j][(pos[s_pos[j]-1]+k)%26];
					}
				}
			}
		}
//		for(int i=0;i<3;i++){
//			for(int j=0;j<26;j++){
//				cout<<zhuanzi[i][j];
//			}
//			cout<<endl;
//			cout<<i<<"pos:"<<pos[i]<<endl;
//		}
//		cout<<s[3]<<endl; 
		int ans =0;
		char res ;
		for(int j=0; j<strlen(s_aim); j++) {
			//密钥推s1
			ans = s_aim[j]-65;
			res = zhuanzi[0][ans];
//			cout<<ans<<" "<<res<<endl;
			//s1推s2
			ans = res - 65;
			res = zhuanzi[1][ans];
//			cout<<ans<<" "<<res<<endl;
			//s2推s3
			ans = res - 65;
			res = zhuanzi[2][ans];
//			cout<<ans<<" "<<res<<endl;
			//s3推反射器
			//反射器推s3
			for(int i=0; i<26; i++) {
				if(s[3][i]==res) {
					ans = i;
				}
			}
			res = 'A'+ans;
//			cout<<ans<<" "<<res<<endl;
			//s3推s2 
			for(int i=0; i<26; i++) {
				if(zhuanzi[2][i]==res) {
					ans = i;
				}
			}
			res = 'A'+ans;
//			cout<<ans<<" "<<res<<endl;
			//s2推s1
			for(int i=0; i<26; i++) {
				if(zhuanzi[1][i]==res) {
					ans = i;
				}
			}
			res = 'A'+ans;
//			cout<<ans<<" "<<res<<endl;
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
//			cout<<"------------------------------------------------"<<endl;
//			for(int i=0;i<26;i++){
//				cout<<zhuanzi[0][i];	
//			}
//			cout<<endl;
//			for(int i=0;i<26;i++){
//				cout<<zhuanzi[1][i];	
//			}
//						cout<<endl;
//			for(int i=0;i<26;i++){
//				cout<<zhuanzi[2][i];	
//			}
//			cout<<"------------------------------------------------"<<endl;
		}
		puts("");
	}
	return 0;
}
