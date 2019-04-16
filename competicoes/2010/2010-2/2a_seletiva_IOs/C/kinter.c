#include <stdio.h>

#define MAX_ELEMENTOS 125000
#define MAX_VALOR     100
#define MAX_K         15

int main() {
	int N, i, j, d, k, maior, media, v[MAX_ELEMENTOS], h[MAX_VALOR+1];
	scanf("%d%d", &N, &k);
	while (N) {
		for (i=0; i<=MAX_VALOR; i++) h[i] = 0;
		maior = 0;
		for (i=0; i<N; i++) {
			scanf("%d", &v[i]);
			if (v[i] > maior) maior = v[i];
			h[v[i]]++;
		}
		/* v ordenado: */
		d = 0;
		for (i=0; i<=MAX_VALOR; i++) {
			for (j=0; j<h[i]; j++) {
				v[d++] = i;
			}
		}
		/* k centrais: */
		media = 0;
		for (i=N/2-k/2; i < N/2-k/2+k; i++) {
			media += v[i];
		}
		media = (int)(1.*media/k + 0.5);
		printf("%d\n", media);
		scanf("%d%d", &N, &k);
	}
	return 0;
}
