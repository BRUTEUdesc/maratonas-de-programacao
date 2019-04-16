#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	int linhas, colunas, ano1, ano2;
	float qtdD, qtdR;
	int **matrizA;
	int **matrizB;
	char **matrizS;
	cin >> linhas >> colunas;
	matrizA = new int*[linhas];
	matrizB = new int*[linhas];
	matrizS = new char*[linhas];
	for (int i=0;i<linhas;i++)
	{
		matrizA[i] = new int[colunas];
		matrizB[i] = new int[colunas];
		matrizS[i] = new char[colunas];
	}
	cin >> ano1;
	for (int i=0;i<linhas;i++)
		for (int j=0;j<colunas;j++)
			cin >> matrizA[i][j];
	cin >> ano2;
	for (int i=0;i<linhas;i++)
		for (int j=0;j<colunas;j++)
			cin >> matrizB[i][j];
	qtdD = qtdR = 0;
	for (int i=0;i<linhas;i++)
		for (int j=0;j<colunas;j++)
		{
			if (matrizA[i][j] == 2 && matrizB[i][j] != 2)
			{
				qtdD++;
				matrizS[i][j] = 'd';
			}
			else if (matrizA[i][j] != 2 && matrizB[i][j] == 2)
			{
				qtdR++;
				matrizS[i][j] = 'r';
			}
			else
				matrizS[i][j] = '.';				
		}
	cout << linhas << " " << colunas << endl << ano1 << " " << ano2 << endl;
	for (int i=0;i<linhas;i++)
	{
		for (int j=0;j<colunas;j++)
		{
			printf("%c", matrizS[i][j]);
		}
		cout << endl;
	}
	printf("%.2f", qtdR/qtdD);
	cout << endl;
}
