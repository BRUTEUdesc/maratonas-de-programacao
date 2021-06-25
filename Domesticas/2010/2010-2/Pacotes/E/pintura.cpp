// Author: Adrian Kuegel
// Date: 4. 6. 2007

#include <stdio.h>
#include <assert.h>

#define MAXN 40000

int main() {
	int n, m, c;
	freopen("black.in","r",stdin);
	while(scanf("%d %d %d",&n,&m,&c) == 3 && (n || m || c)) {
		assert(n >= 8 && n <= MAXN && m >= 8 && m <= MAXN && c >= 0 && c <= 1);
		// lets first ignore the colour constraint
		n -= 7; // number of possible rows for bottom right corner
		m -= 7; // number of possible columns for bottom right corner
		// one half of those n * m fields are white
		// round up if bottom right corner of painting is white
		printf("%d\n",(n*m+c)/2);
	}
	assert(n == 0 && m == 0 && c == 0);
	return 0;
}
