/**********************************/
/*   求字符串S中最长重复子串长度  */
/**********************************/
#include<iostream>
#include<string>
using namespace std;

void Next(string a,int n,int *next) {
	int i=0;
	int j=-1;
	next[0] = -1;
	while(i<n-1) {
		if(j==-1 || a[i] == a[j]) {
			++i;
			++j;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
}

void MaxLenRepeatStr(string a) {
	int n = a.size();
	int max = -1;
	for(int i=0; i<n; i++) {
		string b=a.substr(i,n-i+1);
		int *next = new int[n-i+1];
		Next(b,n-i+1,next);
		for(int j=0; j<n-i+1; j++) {
			if(next[j] > max)
				max = next[j];
		}
		delete []next;
	}
	cout<<max<<endl;
}

int main() {
	string a("abcdsetseabcd");
	cout<<"source string: "<<a<<endl;
	cout<<"max repeat substr length: ";
	MaxLenRepeatStr(a);
	return 0;
}
