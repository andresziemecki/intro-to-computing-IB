#include <stdio.h>

int main (void)
{
	double pi = 0.0;
	for (int n = 1; n <=1000; n++)
		pi = pi + 1.0/((4*(n-1)+1)*(4*(n-1)+3));
	printf("El valor de pi es: %.10lg\n", 8*pi);
	return 0;
}
