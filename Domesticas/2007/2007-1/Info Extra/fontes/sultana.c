#include <stdio.h>

typedef struct str_Rainha {
	int x;
	int y;
} Rainha;

int regraRainhas (Rainha rainhas[], int nRainhas, int x, int y)
{
	int i, j, k, posX, posY;
	int marcas[8][8];
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			marcas[i][j]=1;
		}
	}
	
	for (k=0; k<nRainhas; k++)
	{
		posX = rainhas[k].x;
		posY = rainhas[k].y;
		
		for (i=0; i<8; i++)
		{
			marcas[i][posY] = 0;
			marcas[posX][i] = 0;
		}
		for (i=0; i<8; i++)
		{
			if (posX-i >= 0 && posY+i < 8)
				marcas[posX-i][posY+i] = 0;
		}
		for (i=0; i<8; i++)
		{
			if (posX+i < 8 && posY+i < 8)
				marcas[posX+i][posY+i] = 0;
		}
		marcas[posX][posY] = 2;
	}
	
	/*for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			printf("%i ", marcas[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%i %i\n", x, y);*/
	
	return marcas[x][y] == 1;
}

int main()
{
	int i, j, i1, i2, i3, i4, i5, i6, i7, i8;
	int k, xyz;
	int maior, soma;
	int m[8][8];
	Rainha r[8];
	
	scanf("%i", &k);
	
	for (xyz=0; xyz<k; xyz++)
	{
		for (i=0; i<8; i++)
		{
			for (j=0; j<8; j++)
			{
				scanf("%i", &m[i][j]);
			}
		}
		maior = 0;
		for (i1=0; i1<8; i1++)
		{
			r[0].x = i1;
			r[0].y = 0;
			for (i2=0; i2<8; i2++)
			{
				if (regraRainhas(r, 1, i2, 1))
				{
					r[1].x = i2;
					r[1].y = 1;
					for (i3=0; i3<8; i3++)
					{
						if (regraRainhas(r, 2, i3, 2))
						{
							r[2].x = i3;
							r[2].y = 2;
							for (i4=0; i4<8; i4++)
							{
								if (regraRainhas(r, 3, i4, 3))
								{
									r[3].x = i4;
									r[3].y = 3;
									for (i5=0; i5<8; i5++)
									{
										if (regraRainhas(r, 4, i5, 4))
										{
											r[4].x = i5;
											r[4].y = 4;
											for (i6=0; i6<8; i6++)
											{
												if (regraRainhas(r, 5, i6, 5))
												{
													r[5].x = i6;
													r[5].y = 5;
													for (i7=0; i7<8; i7++)
													{
														if (regraRainhas(r, 6, i7, 6))
														{
															r[6].x = i7;
															r[6].y = 6;
															for (i8=0; i8<8; i8++)
															{
																if (regraRainhas(r, 7, i8, 7))
																{
																	r[7].x = i8;
																	r[7].y = 7;
																	soma = m[i1][0] + m[i2][1] + m[i3][2] + m[i4][3] + m[i5][4] + m[i6][5] + m[i7][6] + m[i8][7];
																	if (soma > maior)
																		maior = soma;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("%5i\n", maior);
	}
	
	
	
	return 0;
}
