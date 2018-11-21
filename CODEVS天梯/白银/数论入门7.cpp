#include<iostream>
using namespace std;

int main() {
	int num;
	cin>>num;
	//ÅĞ¶ÏËØÊı
	bool flag = false;

	if(num<=1) {
		cout<<"\\n";
	} else {
		for(int i=2; i<num; i++) {
			if(num%i==0) {
				flag = true;
			}
		}
		if(flag) {
			cout<<"\\n";
		} else {
			cout<<"\\t";
		}
	}
}
