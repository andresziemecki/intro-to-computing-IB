#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define CANTIDAD 1000000

int main(void)
{
	int f[N] = {0};

	int x = RAND_MAX/N, suma = 0;

	srand(time(NULL));

	for (int i = 0; i < CANTIDAD; i++)
	{
		f[rand()/x]++;
	}
	for (int j = 0; j < N; j++)
	{
		suma += f[j];
	}
	for (int k = 0; k < N; k++)
	{
		printf("%d\t", f[k]);
	}

	printf("\n y la suma de todos es: %d\n", suma);
	return 0;
}

