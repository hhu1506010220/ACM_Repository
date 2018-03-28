#include<bits/stdc++.h>
using namespace std;
int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int isLeapYear(int year) {
	if((year%4==0 && year%100!=0) || (year%400 == 0)) {
		months[2] = 29;
		return 1;
	} else {
		months[2] = 28;
		return 0;
	}
}

int countDays(int year,int month) {
	int days = 0;
	int i;
	for(i = 1850; i < year; i++) {
		if(isLeapYear(i)) {
			days += 366;
		} else {
			days += 365;
		}
	}
	isLeapYear(year);
	for(i = 1; i < month; i++) {
		days += months[i];
	}
	return days;
}
int main() {

	int a,b,c,i;
	int y1,y2;
	scanf("%d%d%d%d%d",&a,&b,&c,&y1,&y2);
	long days = 0;
	for(i = y1; i <= y2; i++) {
		days = countDays(i,a);
		int weekday = days % 7 + 2;
		if(weekday == 8)
			weekday = 1;
		int monthday;
		if(c < weekday) {
			monthday = 8-weekday+(b-1)*7+c;
		} else {
			monthday = (b-1)*7+c-weekday+1;
		}
		isLeapYear(i);
		if(monthday > months[a]) {
			printf("none\n");
		} else {
			printf("%d/%02d/%02d\n",i,a,monthday);
		}
	}
	return 0;
}
