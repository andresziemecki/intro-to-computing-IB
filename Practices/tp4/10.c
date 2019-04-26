#include <stdio.h>

int esPrimo(int N);
#define TRUE 1
#define FALSE 0


int main(void)
{
	unsigned int N;
	printf("inserte el valor que desea ver si es primo: ");
	scanf("%d", &N);
	(esPrimo(N)) ? printf("Es primo\n") : printf("No es primo\n");
	return 0;
}

int esPrimo(int N)
{
	for (int i = 2; i < N; i++)
	{
		if(N%i == 0)
			return FALSE;
	}
	return TRUE;
}
