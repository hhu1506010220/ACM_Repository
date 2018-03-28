#include<bits/stdc++.h>
using namespace std;

vector< int >v;

int find(int a) {
	return distance(v.begin(), find(v.begin(), v.end(), a));
}

int main() {
	int n,m;
	cin>>n>>m;
	int t;
	for(int i=0; i<n; i++) {
		cin>>t;
		v.push_back(t);
		make_heap(v.begin(), v.end(), greater<int>());
	}
	getchar();
	while(m--) {
		char q[100];
		cin.getline(q,100);
		if(q[strlen(q) - 1] == 't') {
			int zf = 1;
			int cnt = 0;
			if(q[0]=='-')zf=-1;
			if(zf==1) {
				for(int i=0; i<strlen(q); i++) {
					if(q[i]==' ')break;
					cnt = cnt*10 + (q[i]-'0');
				}
			} else {
				for(int i=1; i<strlen(q); i++) {
					if(q[i]==' ')break;
					cnt = cnt*10 + (q[i]-'0');
				}
			}
			cnt *= zf;
			if (v[0] == cnt) printf("T\n");
			else printf("F\n");
		} else if(q[strlen(q) - 1] == 's') {
			int a, b;
			string temp;
			stringstream ss(q);
			ss >> a >> temp >> b;
			int pos_a = find(a);
			int pos_b = find(b);
			pos_a++;
			pos_b++;
			if(pos_a / 2 == pos_b / 2)
				printf("T\n");
			else
				printf("F\n");
		} else {
			stringstream ss(q);
			int a, b;
			string temp;
			ss >> a >> temp >> temp;
			if(temp[0] == 't') {
				ss >> temp >> temp >> b;
				int pos_a = find(a);
				int pos_b = find(b);
				if(pos_b == pos_a * 2 + 1 || pos_b == pos_a * 2 + 2)
					printf("T\n");
				else
					printf("F\n");
			} else if(temp[0] == 'a') {
				ss >> temp >> temp >> b;
				int pos_a = find(a);
				int pos_b = find(b);
				if(pos_a == pos_b * 2 + 1 || pos_a == pos_b * 2 + 2)
					printf("T\n");
				else
					printf("F\n");
			}
		}
	}
	return 0;
}
