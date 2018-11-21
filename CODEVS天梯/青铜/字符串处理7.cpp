#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main() {
	char a[100],b[100];
	gets(a);
	int n=strlen(a);
	int i=0;
	int j=0;
	while(i<n) {
		int length=0;
		while(a[i]!=' '&&a[i]!='\0') {
			i++;
			length++;
		}
		j=n-i;
		int m=0;
		for(; m<length; m++) {
			b[j+m]=a[i-length+m];
		}
		if(a[i+1]!='\0')
			b[j+m-length-1]=' ';
		i++;
	}
	a[n]='\0';
	b[n]='\0';
	cout<<b<<endl;
	return 0;
}
