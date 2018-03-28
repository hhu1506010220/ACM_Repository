#include<bits/stdc++.h>
using namespace std;

int a[130];

int main(){
	char s1[10005],s2[100005],s3[100005];
	cin.getline(s1,10005);
	cin.getline(s2,10005);
	int len1=strlen(s1),len2=strlen(s2);	
	for(int i=0;i<len2;i++){
		a[s2[i]]=1;	
	}
	int cnt =0;
	for(int i=0;i<len1;i++){
		if(a[s1[i]])
			continue;
		else
			s3[cnt++] = s1[i];
	}
	cout<<s3<<endl;
	return 0;	
}
