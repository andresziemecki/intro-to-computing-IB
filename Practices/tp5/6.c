#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ITERACIONES 100000
int main(void)
{
	int A = 0, N=0;
	double x, y; // x es la pos del centro, y es la proyeccion en x

	srand(time(NULL));

	while(N < ITERACIONES)
	{
		x = (double)rand()/(RAND_MAX);

		y = cos((double)rand()/1000.0);

		if (x+y<0 || x+y>1)
			A++; 

		N++;
	}
	printf("%lf\n", 2.0*(double)N/(double)A);
	return 0;	
}
