#include <stdio.h>

int main()
{
	int x, y, i, a1, a2, j, m[300][300], m2[300][300];
	int dCnt, rCnt;
	char d[300][300];
	scanf("%i %i", &x, &y);
	scanf("%i", &a1);
	for (i=0; i<x; i++)
	{
		for (j=0; j<y; j++)
		{
			scanf("%i", &m[i][j]);
		}
	}
	
	dCnt = 0;
	rCnt = 0;
	scanf("%i", &a2);
	for (i=0; i<x; i++)
	{
		for (j=0; j<y; j++)
		{
			scanf("%i", &m2[i][j]);
			if (m[i][j] == 2 && m2[i][j] != m[i][j])
			{
				d[i][j] = 'd';
				dCnt++;
			}
			else if (m2[i][j] == 2 & m[i][j] != m2[i][j])
			{
				d[i][j] = 'r';
				rCnt++;
			}
			else
				d[i][j] = '.';
		}
	}
	
	printf("%i %i\n", x, y);
	printf("%i %i\n", a1, a2);
	for (i=0; i<x; i++)
	{
		for (j=0; j<y; j++)
		{
			printf("%c", d[i][j]);
		}
		printf("\n");
	}
	printf("%.02f\n", (double) rCnt / (double) dCnt);
	
	return 0;
}
