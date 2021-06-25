#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

typedef vector<int> VI;
typedef queue<int> QI;
typedef pair<int, int> PII;
typedef queue<PII> QPII;

const int MAX = 8;
int mauer[MAX][MAX];
//int pred[MAX][MAX];
char pred[MAX][MAX];

const int UNTEN = 1;
const int OBEN = 2;
const int LINKS = 4;
const int RECHTS = 8;

/*int code(int x, int y) {
	return x + y*MAX;
}*/

void print(int x, int y) {
	switch(pred[x][y]) {
	case 's': return;
	case 'S': print(x, y-1);	break;
	case 'N': print(x, y+1);	break;
	case 'E': print(x-1, y);	break;
	case 'W': print(x+1, y);	break;
	}
	printf("%c", pred[x][y]);
}

int main() {
	//freopen("basic.in", "r", stdin);

	int sx, sy, ex, ey;
	while(true) {
		for(int i=0; i < MAX; ++i) {
			for(int j=0; j < MAX; ++j) {
				mauer[i][j] = 0;
				//pred[i][j] = -1;
				pred[i][j] = -1;
			}
		}
		scanf("%d%d", &sx, &sy);
		if(sx==0 && sy==0)
			break;
		scanf("%d%d", &ex, &ey);

		for(int i=0; i < 3; ++i) {
			int x1,y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			int dx = x2 - x1;
			int dy = y2 - y1;
			if(dx == 0) {
				for(int y=y1+1; y <= y2; ++y) {
					mauer[x1][y] |= RECHTS;
					mauer[x1+1][y] |= LINKS;
				}
			} else {
				assert(dy==0);
				for(int x=x1+1; x <= x2; ++x) {
					mauer[x][y1] |= UNTEN;
					mauer[x][y1+1] |= OBEN;
				}
			}
		}
/*		for(int i=0; i < MAX; ++i) {
			for(int j=0; j < MAX; ++j) {
				printf("%d ", mauer[j][i]);
			}
			printf("\n");
		}*/
		//BFS
		QPII queue;
		queue.push(PII(sx, sy));
		pred[sx][sy] = 's';
		while(!queue.empty()) {
			PII p = queue.front();
			int x = p.first;
			int y = p.second;
			if(x == ex && y == ey) {
				break;
			}

			queue.pop();
			if(x == 0 || x == MAX-1 || y ==0 || y==MAX-1)
				continue;
			//oben
			if((mauer[x][y] & OBEN) == 0) {	
				if(pred[x][y-1] == -1) {
					queue.push(PII(x, y-1));
					//pred[x][y-1] = code(x, y);
					pred[x][y-1] = 'N';
				}
			}
			if((mauer[x][y] & LINKS) == 0) {	
				if(pred[x-1][y] == -1) {
					queue.push(PII(x-1, y));
					//pred[x-1][y] = code(x, y);
					pred[x-1][y] = 'W';
				}
			}
			if((mauer[x][y] & UNTEN) == 0) {	
				if(pred[x][y+1] == -1) {
					queue.push(PII(x, y+1));
					//pred[x][y+1] = code(x, y);
					pred[x][y+1] = 'S';
				}
			}
			if((mauer[x][y] & RECHTS) == 0) {	
				if(pred[x+1][y] == -1) {
					queue.push(PII(x+1, y));
					//pred[x+1][y] = code(x, y);
					pred[x+1][y] = 'E';
				}
			}
		}
		assert(!queue.empty());

		print(ex, ey);
		printf("\n");

/*		for(int i=0; i < MAX; ++i) {
			for(int j=0; j < MAX; ++j) {
				//printf("%d ", pred[j][i]);
				printf("%c ", pred[j][i]);
			}
			printf("\n");
		}*/
	}

	return 0;
}

