#include<bits/stdc++.h>
using namespace std;

bool cmp(char s1[],char s2[]){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int bigone = 0;
	for(int i=0;i<min(len1,len2);i++){
		if(s1[i]!=s2[i]){
			bigone = s1[i]>s2[i]?1:2;	
			break;
		}
	}
	if(bigone){
		return bigone==1?1:0;	
	}
	if(!bigone&&len1==len2){
		return 1;
	}
	else if(!bigone){
		if(len1>len2){
			if(cmp(s1+len2,s2)){
				return 1;
			}
			else return 0;
		}
		else{
			if(cmp(s2+len1,s1)){
				return 0;
			}
			else return 1;			
		}
	}
}

int main(){
	int n;
	while(cin>>n){
		char t[105][105];
		char tem[105];
		for(int i=0;i<n;i++){
			cin>>t[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(cmp(t[j],t[i])){
					memset(tem,0,sizeof(tem));
					strcpy(tem,t[i]);
					strcpy(t[i],t[j]);
					strcpy(t[j],tem);
				}
			}
		}
		for(int i=0;i<n;i++)cout<<t[i];
		cout<<endl;
	}
	return 0;	
}
