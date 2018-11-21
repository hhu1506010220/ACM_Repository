#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int fullprice,a;
	double percent;
	cin>>fullprice>>percent;
	a=(int)((fullprice *( percent /10)+5)/10);
    cout<<a*10;
	return 0;
}
