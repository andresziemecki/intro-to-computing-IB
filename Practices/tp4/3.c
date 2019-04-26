#include <stdio.h>
int main (void)
{
	double pi = 0, signo = 1.0;
	for (int i = 1; i< 10000000; i = i + 2)
	{
		pi = pi + signo/i;
		signo = signo*(-1);
	}
	printf("El valor de pi es: %.10lf\n", 4*pi);
	return 0;
}
