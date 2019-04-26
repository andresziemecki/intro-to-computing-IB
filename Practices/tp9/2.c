#include <stdio.h>

void TransponeNN(double *matriz, int n);
void Imprime(double *matriz, int n);

int main(void)
{
	double M[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Imprime(&M[0][0], 3);
	TransponeNN((&M[0][0], 3);
	puts("-------------------------------------------");
	Imprime(&M[0][0], 3);
	return 0;
}

void TransponeNN(double *matriz, int n)
{
	double aux;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			aux = *(matriz + i*n + j); 
			*(matriz + i*n + j) = *(matriz + j*n + i);
			*(matriz + j*n + i) = aux;
		}
	}
	return;
}

void Imprime(double *matriz, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.0lf\t", *(matriz + i*n + j));
		}	
		printf("\n");
	}
	return;
}
