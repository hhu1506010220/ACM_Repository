#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[105];
	char low_s[105],low_ss[105];
	char ss[105][105];
	memset(s,0,sizeof(s));
	memset(ss,0,sizeof(ss));
	int option;
	int n;
	cin>>s;
	cin>>option;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ss[i];
		if(option==1){
			if(strstr(ss[i],s)){
				cout<<ss[i]<<endl;	
			}
		}
		else{
			memset(low_ss,0,sizeof(low_ss));
			strcpy(low_s,s);
			strlwr(low_s);
			strcpy(low_ss,ss[i]);
			strlwr(low_ss);	
			if(strstr(low_ss,low_s)){
				cout<<ss[i]<<endl;
			}
		}
	}
	return 0;
}








//
//int main(){
//	char s[105];
//	char ss[105][105];
//	memset(s,0,sizeof(s));
//	memset(ss,0,sizeof(ss));
//	int option;
//	int n;
//	cin>>s;
//	cin>>option;
//	cin>>n;
//	for(int i=0;i<n;i++)
//		cin>>ss[i];
//	if(option==1){
//		for(int i=0;i<n;i++){
//			bool flag = 0;
//			for(int j=0;j<strlen(ss[i]);j++){
//				bool flagg = 1;
//				for(int k=0;j+k<strlen(ss[i])&&k<strlen(s);k++){
//					if(s[k]!=ss[i][j+k]){
//						flagg = 0;
////						j = j+k-1;
//						break;	
//					}
//				}
//				if(flagg){
//					flag = 1;
//					break;
//				}
//			}
//			if(flag){
//				cout<<ss[i]<<endl;
//			}
//		}
//	}
//	else{		
//		for(int i=0;i<n;i++){
//			bool flag = 0;
//			for(int j=0;j<strlen(ss[i]);j++){
//				bool flagg = 1;
//				for(int k=0;j+k<strlen(ss[i])&&k<strlen(s);k++){
//					if(!((s[k]==ss[i][j+k])||(s[k]-'a'==ss[i][j+k]-'A')||(s[k]-'A'==ss[i][j+k]-'a'))){
//						flagg = 0;
////						j = j+k-1;
//						break;	
//					}
//				}
//				if(flagg){
//					flag = 1;
//					break;
//				}
//			}
//			if(flag){
//				cout<<ss[i]<<endl;
//			}
//		}
//	}
//	return 0;	
//}
