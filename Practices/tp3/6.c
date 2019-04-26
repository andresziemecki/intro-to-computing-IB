#include <stdio.h>

int main (void)
{
	float x, pol;
	printf("Escriba el valor de x: ");
	scanf("%f", &x);
	pol = 3.0*x*x*x - 5.0*x*x + 6.0;
	printf("El valor del Polinomio 3*x^3 + 5*x^2 + 6 = %f\n", pol);
	return 0;
}
