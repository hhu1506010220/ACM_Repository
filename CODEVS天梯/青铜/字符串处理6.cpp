#include "stdio.h"
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main() {
	char a[500],b[500];
	cin>>a>>b;
	int i=0,j=0,len_a=0,len_b=0;
	len_a=strlen(a);
	len_b=strlen(b);
	while(i<len_a&&j<len_b) {
		if(a[i]==b[j]) {
			i++;
			j++;
		} else {
			i=i-j+1;
			j=0;
		}

	}
	if(j>=len_b) printf( "%d\n",(i-j+1));
	else printf("no found");
	return 0;
}
