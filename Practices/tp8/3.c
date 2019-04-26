#include <stdio.h>
int cantidaddeformas (int n);
// int contador = 0;
int main(void)
{
	int n;
	scanf("%d", &n);
	n = cantidaddeformas(n);
	printf("cantidad de formas: %d\n", n);
	return 0;
}

int cantidaddeformas (int n)
{
	static int contador = 0;
	if (n>0)
		cantidaddeformas(n-1);
	if (n>1)
		cantidaddeformas(n-2);
	if (n == 0)
		{
		contador++;
		return contador;
		}
}
