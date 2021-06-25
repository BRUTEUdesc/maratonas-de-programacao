#include <stdio.h>

/*
//#define TAM 10000000
#define TAM 1000000

int main() { //versao ruim (alocacao de vetor grande impossivel)
	int T, v, vet[TAM], i;
	scanf("%d", &T);
	while (T--) {
		for (i=0; i<TAM; i++) vet[i]=0;
		do {
			scanf("%d", &v);
			if (v != -1) {
				vet[v]++;
			}
		} while (v != -1);
		for (i=1; i<TAM; i++) {
			vet[i] += vet[i-1];
		}
	printf("%d\n", vet[TAM-1]);
	}
	return 0;
}
//*/

//*
int main() { //versao inteligente (basta determinar a quantidade de elementos
	int T, N, v, n;
	scanf("%d", &T);
	//printf("%d", T); return 0;
	while (T--) {
		n = 0;
		//scanf("%d", &N);
		do {
			scanf("%d", &v);
			if (v != -1) n++;			
		} while (v != -1);
	printf("%d\n", n);
	}
	return 0;
}
//*/
