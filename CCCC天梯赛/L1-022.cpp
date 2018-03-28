#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ji = 0;
	for(int i=0;i<n;i++){
		int te;
		cin>>te;
		if(te%2==1)
			ji++;
	}
	cout<<ji<<" "<<n-ji<<endl;
	return 0;	
}
