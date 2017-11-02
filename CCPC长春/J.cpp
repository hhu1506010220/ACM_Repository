//include <bits/stdc++.h>
#include<cstring>
#include<iostream>
#include<cstdio> 
#include<vector>
//#include<windows.h>
using namespace std;
const int maxn = 1010;
char s[maxn];
int len;
int mid;
vector<string > ans;

void Sub(char s[],char s1[]){
//	cout<<len<<endl;
//	cout<<s<<" "<<s1<<endl; 
	for(int i=len-1;i>=0;i--){
//		cout<<s[i]<<" "<<s1[i]<<endl;
		char c = s[i]-s1[i]+'0';
		if(c<'0'){
			s[i-1]=(char)(s[i-1]-1);
			s[i] = (char)(c+10);
		}
		else{
			s[i]=c;
		}
//		cout<<s[i]<<" "<<c<<endl;
	}
//	cout<<s<<" "<<s1<<endl;
//	Sleep(1000);
	for(int i=0;i<len;i++){//处理前缀0 
		if(s[i]!='0'){
			int len1 = len-i;
			for(int j=0;i+j<len;j++){
				s[j] = s[i+j];
			}
			s[len1]='\0';
			len = len1;
			break;
		}
	}
}

void Subb(char s[],char s1[]){
	for(int i=len-1;i>=0;i--){
//		cout<<s[i]<<" "<<s1[i]<<endl;
		char c = s[i]-s1[i]+'0';
		if(c<'0'){
			s[i-1]=(char)(s[i-1]-1);
			s[i] = (char)(c+10);
		}
		else{
			s[i]=c;
		}
//		cout<<s[i]<<" "<<c<<endl;
	}
//	Sleep(1000);
	for(int i=mid-1;i<len;i++){//处理前缀0 
		if(s[i]!='0'){
			int len1 = len-i;
			for(int j=0;i+j<len;j++){
				s[j] = s[i+j];
			}
			s[len1]='\0';
			len = len1;
			break;
		}
	}
}
void Sub_1(char s[]){
	int len2 = strlen(s);
	char c = s[len2-1] = (char)(s[len2-1]-1);
	for(int i=len2-1;i>=0;i--){
//		cout<<s[i]<<" "<<s1[i]<<endl;
		if(i!=len2-1)
			 c = s[i];
		if(c<'0'){
			s[i-1]=(char)(s[i-1]-1);
			s[i] = (char)(c+10);
		}
		else{
			s[i]=c;
		}
//		cout<<s[i]<<" "<<c<<endl;
	}
}

void Sub_2(char s[]){
	int len2 = strlen(s);
	int midd = len/2+1;
	char c = s[midd-1] = (char)(s[midd-1]-1);
//	cout<<c<<endl;
	for(int i=midd-1;i>=0;i--){
//		cout<<s[i]<<" "<<s1[i]<<endl;
		if(i!=midd-1)
			 c = s[i];
		if(c<'0'){
			s[i-1]=(char)(s[i-1]-1);
			s[i] = (char)(c+10);
		}
		else{
			s[i]=c;
		}
	}
//	cout<<s<<" "<<c<<endl;
	int kk =2;
	for(int i=midd;i<len;i++){
		s[i]=s[i-kk];
		kk+=2;
	}
//	cout<<s<<" "<<c<<endl;
}

void change(char s[],char s1[]){
	for(int i = 0; i < mid; i ++)
	{
		s1[i] = s[i];
	}
	
	int k = 1;
	int j;
	for(j = mid; j< len&&j-k>=0; j ++)
	{
		s1[j]=s[j - k];
		k += 2;
	} 
//	s1[j]='\0';
}

int main(){
//	freopen("in.txt","r",stdin);
	int T;
	scanf("%d",&T); 
	int Casee = 1;
//	cout<<(char)('5'+1)<<endl;
	while(T--)
	{
		ans.clear();
		scanf("%s",s);
		len = strlen(s);
		while(1)
		{
			len = strlen(s);
			mid = len / 2;
			//构造一个回文串
			char s1[maxn] = {0};
			
			int _1=0,_0=0;
			for(int i=0;i<len;i++){
				if(s[i]=='1')_1++;
				if(s[i]=='0')_0++;
			}
			if(_1+_0==len&&_1==1){
				for(int i=0;i<len-1;i++){
					s1[i]='9';
				}
//				s1[len-1]='\0';
				if(!(_1==1&&_0==0)) 
				ans.push_back(s1);
				ans.push_back("1");
				memset(s1,0,sizeof(s1));
				break;
			}
			
//			cout<<
			
			if(len % 2 ==0)//偶数 
			{
				change(s,s1);
				
//				cout<<s1<<endl;	

				int cmpp = strcmp(s,s1);

				if(!cmpp){
					ans.push_back(s1);
					break;
				}
				
				if(cmpp==1){
					ans.push_back(s1);
					Sub(s,s1);
				}
//				cout<<s<<endl;

				else{
					memset(s1,0,sizeof(s1));
					for(int i=0;i<mid;i++)
						s1[i]=s[i];
					Sub_1(s1);
//					cout<<"s1="<<s1<<endl;	
					int k=1;
					int ii;
					for(ii = mid; ii < len; ii ++)
					{
						s1[ii] = s1[ii-k];
						k+=2;
					}
//					s1[ii]='\0';
//					cout<<s<<" "<<s1<<endl;
					ans.push_back(s1);
					Sub(s,s1);
//					cout<<"s="<<s<<endl;
				}
			} 
			else{//奇数长度 
				mid++;
//				cout<<mid<<endl;
				
				for(int i = 0; i < mid; i ++)
				{
					s1[i] = s[i];
				}
				
				int k = 2;
				int j;
				for(j = mid; j< len&&j-k>=0; j ++)
				{
					s1[j]=s[j - k];
					k += 2;
				} 
//				s1[j]='\0';
				
//				cout<<s1<<endl;	

				int cmpp = strcmp(s,s1);

				if(!cmpp){
					ans.push_back(s1);
					break;
				}
				
				if(cmpp==1){
					ans.push_back(s1);
					Sub(s,s1);
				}
//				cout<<s<<endl;

				else{
					memset(s1,0,sizeof(s1));
					strcpy(s1,s);
					Sub_2(s1);
//					cout<<s1<<endl;	
					
					ans.push_back(s1);
					Subb(s,s1);					
				
//					cout<<s<<endl;
				}				
	
			}
		
		}
		
		printf("Case #%d:\n",Casee++);
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<endl;
		}
//		123981249862356283470921895345103712364365943592310649832740123642356237451235421394501239601239560324975602837428375410273423975328750183751832402147291734098634573412387462398470929749263945293569235
	} 
	return 0;
}
