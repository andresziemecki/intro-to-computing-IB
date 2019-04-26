#include <stdio.h>

int Suma (int N);

int main (void)
{
	int N;
	printf("Ingrese el numero a sumar: ");
	scanf("%d", &N);
	printf("la suma es: %d\n", Suma(N));
	return 0;
}

int Suma (int n)
{
	int suma = 0;
	for (int i = 0; i <= n; i++)
	suma = suma + i;
	return suma;
}
