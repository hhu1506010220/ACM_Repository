#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,w;
const int maxn =15;
long long d[maxn][1<<15];
int path[5000000][2];//path[10][0]��ʾ��11��(��0����)���ݷ�ʽ��ǰһ�ж�������ʽ��Ӧ�ĵ�ֵ
//path[10][1]��ʾ��11��(��0����)���ݷ�ʽ�ĺ�һ�ж�������ʽ��Ӧ�ĵ�ֵ
//һ��������(1<<11)*(1<<11)�ּ��ݷ�ʽ

void get(int c,int pre,int now) { //�õ�����m�еľ�������ж�Ӧ���ݷ�ʽ����path��
	if(c>m)return ;
	else if(c==m) {
		path[w][0]=pre;
		path[w++][1]=now;
		return;
	}
	get(c+1,(pre<<1)|1,now<<1);
	get(c+1,(pre<<1),(now<<1)|1);
	get(c+2,(pre<<2)|3,(now<<2)|3);
}

int main() {
	n= m =10;
	w=0;//���ݷ�ʽ����
	if(m>n)swap(n,m);//ʼ�ձ���nΪ�У�mΪ��������m��С
	get(0,0,0);//�õ����м��ݷ�ʽ
	memset(d,0,sizeof(d));
	d[0][(1<<m)-1]=1;//����ĵ�0���Ҷ�������ʽΪȫ1ʱ ����1��
	for(int i=0; i<n; i++)//��n��
		for(int j=0; j<w; j++) { //ÿ����w�ֶ�Ӧ�ļ��ݷ�ʽ
			d[i+1][path[j][1]] +=d[i][path[j][0]];//path[j][0]��path[j][1]�ֱ�ָ���ݵ�����������
			//d[i][x]��ʾ��i���Ҹ��еĶ����Ʊ�ʾΪXʱ�����ж����ְڷŹ��Ƶķ�ʽ��
		}
	printf("%I64d\n",d[n][(1<<m)-1]);
	return 0;
}
