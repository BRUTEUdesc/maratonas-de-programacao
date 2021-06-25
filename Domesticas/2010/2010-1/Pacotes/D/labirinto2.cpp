#include <cstdio>
#include <cassert>
#include <queue>
#include <string>

using namespace std;

struct stat{
	char x, y;
	string way;
	stat(char x, char y) : x(x), y(y){
	}
};

char brett[36][4];
char vis[6][6];

inline int feld_nr(int x, int y){
	return 6*y+x;
}

void print_poss(int x, int y){
	printf("possible moves for (%d,%d):  ", x,y);
	for (int i=0; i<4; i++){
		if (brett[feld_nr(x,y)][i])
			printf ("%d ", i);
	}
	printf("\n");
}

int main(){
	int sx, sy, ex, ey;
	//freopen("basic.in", "r", stdin);
	while (1){
		scanf("%d %d\n", &sx, &sy);
		if (sx == 0 && sy == 0)
			break;
		
		scanf("%d %d\n", &ex, &ey);
		
		sx--; sy--; ex--; ey--;
		
		for (int i=0; i<36; i++)
			for (int j=0; j<4; j++)
				brett[i][j] = 1;
		for (int i=0; i<6; i++)
			for (int j=0; j<6; j++)
				vis[i][j] = 0;
		
		for (int i=0; i<3; i++){
			int x1, x2, y1, y2;
			scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
			for (int j=x1; j<x2; j++){
				//printf("wall between %d,%d and %d,%d\n",j,y1,j,y1-1); 
				brett[feld_nr(j,y1)][0] = 0;
				if (y1 > 0)
					brett[feld_nr(j,y1-1)][2] = 0;
			}
			for (int j=y1; j<y2; j++){
				//printf("wall between %d,%d and %d,%d\n", x1,j, x1-1,j); 
				brett[feld_nr(x1,j)][3] = 0;
				if (x1 > 0)
					brett[feld_nr(x1-1,j)][1] = 0;
			}
		}
		
		queue <stat> q;
		q.push(stat(sx,sy));
	
	
		while (1){
			const stat& s = q.front();
			int x = s.x, y = s.y;
//			print_poss(x,y);
			if (q.empty() || q.size() > 10000)
				return 0;
			if (s.x == ex && s.y == ey)
				break;
	//		printf("feldnr (%d,%d)=%d\n",x,y,feld_nr(x,y));
			if (x < 5 && !vis[x+1][y] && brett[feld_nr(x,y)][1]){
	//			printf("x+1\n");
				stat neu(x+1,y);
				neu.way = s.way + 'E';
				if (x+1 == ex && y == ey){
					printf("%s\n",neu.way.c_str());
					break;
				}
				vis[x+1][y] = 1;
				q.push(neu);
			}
			if (x > 0 && !vis[x-1][y] && brett[feld_nr(x,y)][3]){
	//			printf("x-1\n");
				stat neu(x-1,y);
				neu.way = s.way + 'W';
				if (x-1 == ex && y == ey){
					printf("%s\n",neu.way.c_str());
					break;
				}
				vis[x-1][y] = 1;
				q.push(neu);
			}
			if (y < 5 && !vis[x][y+1] && brett[feld_nr(x,y)][2]){
	//			printf("y+1\n");
				stat neu(x,y+1);
				neu.way = s.way + 'S';
				if (x == ex && y+1 == ey){
					printf("%s\n",neu.way.c_str());
					break;
				}
				vis[x][y+1] = 1;
				q.push(neu);
			}
			if (y > 0 && !vis[x][y-1] && brett[feld_nr(x,y)][0]){
	//			printf("y: %d -> %d\n", y, y-1);
				stat neu(x,y-1);
				neu.way = s.way + 'N';
				if (x == ex && y-1 == ey){
					printf("%s\n",neu.way.c_str());
					break;
				}
				vis[x][y-1] = 1;
				q.push(neu);
			}
			q.pop();
		}
	}
	
	return 0;
}
