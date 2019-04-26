#include <stdio.h>

int main (void)
{
	typedef struct Complex{
		float re, im;
	} complejo;

	complejo x, y;
	printf("Inserte el valor real de x: ");
	scanf("%f", &x.re);
	printf("Inserte la imagen de x: ");
	scanf("%f", &x.im);
	printf("Inserte el valor real de y: ");
	scanf("%f", &y.re);
	printf("Inserte la imagen de y: ");
	scanf("%f", &y.im);

	printf("la suma es: %.2f%+.2fi\n", x.re + y.re, x.im + y.im);
	printf("la multiplicacion es: %.2f%+.2fi\n", (x.re * y.re) - (x.im * y.im), (x.re * y.im) + (x.im * y.re));

	return 0;
}
