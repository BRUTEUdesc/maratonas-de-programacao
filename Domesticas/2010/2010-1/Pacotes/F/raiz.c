#include <stdio.h>
#include <math.h>

int main() {
	int i, n;
	float x0, x, a;
	scanf("%d", &n);
	while (n--) {
		scanf("%f", &a);
		x0 = a/2;
		x  = (x0 + a/x0) / 2;
		i = 1;
		while (fabs(x-x0) > 0.001) {
			x0 = x;
			x = (x0 + a/x0) / 2;
			i++;
		}
		printf("%d", i);
		if (n) printf(" ");
	}
	return 0;
}
