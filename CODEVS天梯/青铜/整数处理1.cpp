#include<iostream>
using namespace std;

int main() {
	void SX_Quick_Sort(long int array[],int i,int j);
	int Quick_Sort(long int array[],int i,int j);
	int n,i;
	long int *p;
	cin>>n;
	p=new long int [n+1];
	for(i=1; i<n+1; i++)
		cin>>p[i];
	SX_Quick_Sort(p,1,n);
	cout<<p[1]<<" "<<p[n]<<endl;
	return 0;
}

int Quick_Sort(long int array[],int i,int j) {
	while(i<j) {
		while(i<j&&array[i]<=array[j])j--;     //先从右边开始
		if(i<j) {
			array[0]=array[i];
			array[i]=array[j];
			array[j]=array[0];
			i++;
		}
		while(i<j&&array[i]<=array[j])i++;    //再从左边
		if(i<j) {
			array[0]=array[i];
			array[i]=array[j];
			array[j]=array[0];
			j--;
		}
	}
	return i;                               //返回轴
}
void SX_Quick_Sort(long int array[],int i,int j) {
	int p;
	if(i<j) {
		p=Quick_Sort(array,i,j);
		SX_Quick_Sort(array,i,p-1);
		SX_Quick_Sort(array,p+1,j);
	}
}
