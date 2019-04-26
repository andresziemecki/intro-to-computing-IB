#include <stdio.h>

int main(void)
{
	printf("Ingrese la cantidad de filas de la matriz: ");
	int M, N;
	scanf("%d", &M);
	printf("Ingrese la cantidad de columnas de la matriz: ");
	scanf("%d", &N);
	for (int i = 0; i <= M; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			printf("%d%d\t", i, j);
		}
		printf("\n");
	} 
	return 0;
}
