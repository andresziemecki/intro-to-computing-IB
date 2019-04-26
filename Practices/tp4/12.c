#include <stdio.h>

typedef struct complex
{
	float re, im;
}Complejo_t;

Complejo_t sumaComplejos(Complejo_t c1, Complejo_t c2); 
Complejo_t multiplicaComplejos(Complejo_t c1, Complejo_t c2); 

int main(void)
{
	Complejo_t c1, c2;
	printf("Inserte c1.re = ");
	scanf("%f", &c1.re);
	printf("Inserte c1.im = ");
	scanf("%f", &c1.im);
	printf("Inserte c2.re = ");
	scanf("%f", &c2.re);
	printf("Inserte c2.im = ");
	scanf("%f", &c2.im);
	Complejo_t operacion;
	operacion = sumaComplejos(c1, c2);
	printf("suma de los complejos:\n%.2f%+.2fi\n", operacion.re, operacion.im);
	operacion = multiplicaComplejos(c1, c2);
	printf("multiplicacion de los complejos:\n%.2f%+.2fi\n", operacion.re, operacion.im);
	return 0;
}

Complejo_t sumaComplejos(Complejo_t c1, Complejo_t c2)
{
	Complejo_t x;
	x.re = c1.re + c2.re;
	x.im = c1.im + c2.im;
	return  x;
}
Complejo_t multiplicaComplejos(Complejo_t c1, Complejo_t c2)
{
	Complejo_t y;
	y.re = (c1.re * c2.re) - (c1.im * c2.im);
	y.im = (c1.re * c2.im) + (c1.im * c2.re);
	return y;
}

