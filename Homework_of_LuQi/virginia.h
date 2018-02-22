#include<bits/stdc++.h>
using namespace std;

string VJNY(string s_password,string s_key){
	int point_key=0;//指向s_key的移动指针 
	int cnt=0;//计数器，用来指示当前s_password的位置 
	int len_s = s_password.length();//原串长度 
	int len_key = s_key.length();//密钥长度 
	for(cnt=0;cnt<len_s;cnt++){
		if(s_password[cnt]<='Z'&&s_password[cnt]>='A'&&s_key[point_key]<='Z'&&s_key[point_key]>='A'){
			s_password[cnt] = (s_password[cnt] - s_key[point_key] + 26)%26 + 'A';
			point_key++;		
		}
		else if(s_password[cnt]<='Z'&&s_password[cnt]>='A'&&s_key[point_key]<='z'&&s_key[point_key]>='a'){
			s_password[cnt] = (s_password[cnt] - s_key[point_key] + (97-65) + 26)%26 + 'A';	
			point_key++;	
		}
		else if(s_password[cnt]<='z'&&s_password[cnt]>='a'&&s_key[point_key]<='z'&&s_key[point_key]>='a'){
			s_password[cnt] = (s_password[cnt] - s_key[point_key] + 26)%26 + 'a';
			point_key++;			
		}
		else if(s_password[cnt]<='z'&&s_password[cnt]>='a'&&s_key[point_key]<='Z'&&s_key[point_key]>='A'){
			s_password[cnt] = (s_password[cnt] - s_key[point_key] - (97-65) + 26)%26 + 'a';		
			point_key++;				
		}
		if(point_key>=len_key)
			point_key=0;
	}
	return s_password;
}


