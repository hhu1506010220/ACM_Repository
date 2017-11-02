#include<bits/stdc++.h>
using namespace std;

int a[100];

int exchange(char s[]){
    int len=strlen(s);  
    int sum=0;  
    for(int j=0;j<len;j++)  
    {  
        if(s[j]>='A'&&s[j]<='F')  
            sum+=(s[j]-'A'+10)*pow(16,len-1-j);//不要忘了加10   
        if(s[j]>='0'&&s[j]<='9')  
            sum+=(s[j]-'0')*pow(16,len-1-j);  
    }  
    return sum;
}

int main(){
	//freopen("in.txt","r",stdin); 
	char s[100000];
	double ans=0;
	int cnt=0,cnn=0;
	memset(a,-1,sizeof(a));
	while(~scanf("%s",s)&&strcmp(s,"END")!=0){
		cnn++;	
		int h1 = exchange(s)/16;
		int h2 = h1%64;
		if(a[h2]!=h1){
			puts("Miss");
			a[h2]=h1;	
		}
		else{
			puts("Hit");
			cnt++;	
		}
		memset(s,0,sizeof(s));
	}
//	cout<<cnn<<" "<<cnt<<endl;
	ans = (double)(cnt*1.0)/(cnn*1.0);
	printf("Hit ratio = %.2f",ans*100);
	puts("%");
	return 0;
}
