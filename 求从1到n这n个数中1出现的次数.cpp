/**********************************/
/*   O(len)��n������1���ֵĴ���   */
/**********************************/
#include <bits/stdc++.h>
using namespace std;

int count(int n);

int main(void) {
	int x;

	printf("����һ������");
	scanf("%d",&x);
	printf("\n��0��%dһ������%d��1\n",x,count(x));

	return 0;
}

int count(int n) {
	int count = 0;//ͳ�Ʊ���
	int factor = 1;//�ֽ�����
	int lower = 0;//��ǰ����λ�����е�λ
	int higher = 0;//��ǰ����λ�����и�λ
	int curr =0;//��ǰ����λ

	while(n/factor != 0) {
		lower = n - n/factor*factor;//��õ�λ
		curr = (n/factor)%10;//��ǰλ
		higher = n/(factor*10);//���λ

		switch(curr) {
			case 0:
				count += higher * factor;
				break;
			case 1:
				count += higher * factor + lower + 1;
				break;
			default:
				count += (higher+1)*factor;
		}

		factor *= 10;
	}

	return count;
}
