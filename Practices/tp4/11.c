#include <stdio.h>

int main(void)
{
	// para float
	float suma, x1 = 1.126, x2 = -1.125 , x3 = -0.001 ;
	for (int i = 1; i < 0xFFFFFF; i++)
		suma = x1 + x2 + x3;
	printf("suma float  =\t%.14f\n", suma);
	// para double
	double suma_double, y1 = 1.126, y2 = -1.125 , y3 = -0.001 ;
	for (int i = 1; i < 0xFFFFFF; i++)
		suma_double = y1 + y2 + y3;
	printf("suma double =\t%.20lf\n", suma_double);
	return 0;
}
