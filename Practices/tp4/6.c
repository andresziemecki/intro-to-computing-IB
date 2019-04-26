#include <stdio.h>
#include <math.h>

double miSqrt(double a);

#define abs(x) ((x)<0?-x:x)

int main (void)
{
	double a, raiz;
	printf("Ingrese el valor que quiere calcular la raiz: ");
	scanf("%lf", &a);
	raiz = miSqrt(a);
	printf("La raiz de %.2lg es: %.6lg\n", a, raiz);
	printf("Comparacion del resultado con sqrt(%.2lg) = %.6lg\n", a, sqrt(a)); 
	return 0;
}

double miSqrt(double a)
{
	int i = 0;
	double x2 = 0, x1 = 1.0;
	while (fabs(x1 - x2)>0.000001) // tambien se puede definir abs para doble como "fabs"
	{
		i++;
		x2 = x1;
		x1 = (x1 + a/x1)/2;
	}
	printf("cantidad de iteraciones: %d\n", i);
	return x1;
}
