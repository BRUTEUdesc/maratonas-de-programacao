#include <stdio.h>
#include <string.h>

int xx[10000];

int main() {
	//freopen("generate.in", "r", stdin);
	int n,i;
	while (scanf("%d", &n), n) {
		memset(xx, 0, sizeof(xx));
		int count=1;
		for (;;) {
			xx[n] = 1;
			n=(n*n/100)%10000;
			if (xx[n]) break;
			count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
