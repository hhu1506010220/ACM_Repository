#include<stdio.h>
#include<math.h>
void CaculateWeekDay(int y,int m, int d) {
	if(m==1||m==2) {
		m+=12;
		y--;
	}
	int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	switch(iWeek) {
		case 0:
			printf("Monday\n");
			break;
		case 1:
			printf("Tuesday\n");
			break;
		case 2:
			printf("Wednesday\n");
			break;
		case 3:
			printf("Thursday\n");
			break;
		case 4:
			printf("Friday\n");
			break;
		case 5:
			printf("Saturday\n");
			break;
		case 6:
			printf("Sunday\n");
			break;
	}
}
int main() {
	int year=0,month=0,day=0;
	while(~scanf("%d%d%d",&year,&month,&day)){
		CaculateWeekDay(year,month,day);
	}
	return 0;
}
