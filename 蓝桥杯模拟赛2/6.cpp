#include <iostream>
using namespace std;
const int maxn = 50;
int a[maxn] = {258055 ,69760 ,163908 ,249856 ,53440,
               151684, 77958, 176134 ,8262, 229446,
               245953, 20676, 45189 ,69826 ,131075,
               28672, 155717 ,118851 ,221318 ,254150,
               135235 ,86083, 41089 ,28743 ,32772,
               225475, 118855 ,249862 ,184320, 217154,
              };
              
int main() {
	int maxx  = -1;
	for(int i =  0 ; i < 30  ; i ++) {
		for(int j = i + 1 ; j < 30 ; j ++) {
			for(int k = j + 1 ; k < 30 ; k ++)
				maxx = max(maxx,a[i]^a[j]^a[k]);
		}
	}
	cout << maxx << endl;
}
