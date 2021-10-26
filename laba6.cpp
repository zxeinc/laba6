#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <queue>
using namespace std;

void matrix(int** g, int size)
{

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			g[i][j] = rand() % 2;

		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				g[i][j] = 0;
			else
				g[i][j] = g[j][i];
		}
	}

	printf("Матрица: \n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%2d", g[i][j]);

		}
		printf("\n");
	}

}

void F(int** g, int* NUM, int v, int size)
{
	queue <int> q;
	q.push(v);
	NUM[v] = 0;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		//printf("%d ", NUM[v]);

		for (int i = 0; i < size; i++)
		{

			if ((g[v][i] == 1) && (NUM[i] == -1))
			{
				q.push(i);
				NUM[i] = 1 + NUM[v];
			}

		}

	}
	printf("\n\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", NUM[i]);
	}
}


void main()
{
	setlocale(LC_ALL, "RUS");

	int i = 0;
	int j = 0;
	int size = 0;
	int** g = 0;
	int v = 0;

	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	printf("Введите размер матрицы: ");
	scanf("%d", &size);

	g = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++)
	{
		g[i] = (int*)malloc(size * sizeof(int));
	}

	matrix(g, size);

	printf("Точка входа: ");
	scanf("%d", &v);

	int* NUM = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		NUM[i] = -1;
	}


	F(g, NUM, v, size);

	printf("\n");

	system("pause");
}