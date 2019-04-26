#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef double (*Fun_t) (double value);
double calculaArea(Fun_t f, double a, double b, double error);

// formula: ((b-a)/6.0)Fun_t(a)+4*Fun_t( (a+b)/2 ) + f(b)

int main(void)
{
	printf("integral del sin de 0 a PI = %lf\n", calculaArea(sin, 0, M_PI, 0.0002));
	return 0;
}

double calculaArea(Fun_t f, double a, double b, double error)
{
	if ( a > b)
	{
		double c = a;
		a = b;
		b = c;
	}
	
	int i, numinterv = 1;
	double subinterv, integral1, integral2, x1 = a, x2 = b;
	
	do
	{
		integral1 = 0;
		integral2 = 0;
		for ( i = 0; i < numinterv; i++)
		{
			integral1 += ((x2-x1)/6.0)*(f(x1) + 4*f( (x1+x2)/2.0 ) + f(x2) );
			x1 = x2;
			x2 += subinterv;
		}	
		numinterv *= 2;
		subinterv = fabs(b - a)/numinterv;
		x1 = a;
		x2 = a + subinterv;
	
		for ( i = 0; i < numinterv; i++)
		{
			integral2 += ((x2-x1)/6.0)*(f(x1)+4*f( (x1+x2)/2 ) + f(x2) );
			x1 = x2;
			x2 += subinterv;
		}
		printf("%lf \t %lf\n", fabs( fabs(integral1) - fabs(integral2) ), error);
	}
	while ( fabs( fabs(integral1) - fabs(integral2) ) > fabs(error));
	return integral2;	
}

