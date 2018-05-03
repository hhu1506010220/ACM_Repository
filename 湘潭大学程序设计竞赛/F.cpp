#include<bits/stdc++.h>
using namespace std;
const int maxn = 305;

struct Node {
	int x, y;
	int time; //����ʱ��
	Node(int x=0, int y=0, int t=0):x(x),y(y),time(t) {}
	bool operator<(const Node& p)const {
		return time > p.time;
	}
};

struct Cell {
	char ch;
	int tx,ty; //�����ų���, û��ʱΪ-1
} maze[maxn][maxn];


int n,m,q;
int dir[4][2]= {0, 1, 1,0, 0, -1, -1, 0};


int BFS(int sx, int sy) {
	priority_queue<Node> Q;
	Q.push(Node(sx, sy));
	maze[sx][sy].ch='#';
	while(!Q.empty()) {
		Node p = Q.top();
		Q.pop();
		if(maze[p.x][p.y].ch == 'T') return p.time;
		//�����������ĸ������ƶ�
		int tx,ty;
		for(int i=0; i<4; ++i) {
			tx = p.x + dir[i][0];
			ty = p.y + dir[i][1];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m || maze[tx][ty].ch =='#' ) continue; //Խ����
			Q.push(Node(tx, ty, p.time + 1));
			if(maze[tx][ty].ch == 'T') return p.time + 1; //�����һ�������յ�, ��ֱ�ӷ���.
			if(maze[tx][ty].ch != 'T') maze[tx][ty].ch='#';//�߹��ĵ㲻�ظ���
		}
		//���봫����
		tx = maze[p.x][p.y].tx;
		ty = maze[p.x][p.y].ty;
		if(tx < 0 || tx >= n || ty < 0 || ty >= m || maze[tx][ty].ch =='#') continue; //Խ����
		Q.push(Node(tx, ty, p.time+3)); //������Ҫ3��

	}
	return -1;
}

int main() {
	int x,y, sx, sy;
	char line[maxn];
	while(scanf("%d%d%d", &n, &m, &q)!= -1) {
		memset(maze, -1, sizeof(maze));
		for(int i=0; i<n; ++i) {
			scanf("%s", line);
			for(int j=0; j<m; ++j) {
				maze[i][j].ch = line[j];
				if(line[j] == 'S') {
					sx = i, sy = j;
				}
			}
		}
		for(int i=0; i<q; ++i) {
			scanf("%d%d", &x, &y);
			scanf("%d%d", &maze[x][y].tx, &maze[x][y].ty);
		}
		printf("%d\n", BFS( sx, sy ));
	}

	return 0;
}
