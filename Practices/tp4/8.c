#include <stdio.h>
#include <math.h>
void raices(double a, double b, double c);
int main(void)
{
	double a, b, c;
	printf("inserte el valor de a = ");
	scanf("%lg", &a);
	printf("inserte el valor de b = ");
	scanf("%lg", &b);
	printf("inserte el valor de c = ");
	scanf("%lg", &c);
	
	raices(a, b, c);
}

void raices(double a, double b, double c)
{
	if ((b*b - 4*a*c) < 0)
		printf("las raices son: \nx1 = %.4lg%+.4lgi\nx2 = %.4lg%+.4lgi\n", (-1.0)*b/(2.0*a), sqrt(4*a*c - b*b)/(2.0*a), (-1.0)*b/(2.0*a), (-1.0)*sqrt(4*a*c - b*b)/(2.0*a));
	else
		printf("las raices son: \nx1 = %.4lg\nx2 = %.4lg\n", (-1.0)*b/(2.0*a) + sqrt(b*b - 4*a*c)/(2.0*a), (-1.0)*b/(2.0*a) - sqrt(b*b - 4*a*c)/(2.0*a));
	return; 
}
