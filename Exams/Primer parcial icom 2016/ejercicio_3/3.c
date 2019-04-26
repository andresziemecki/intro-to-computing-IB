#include <stdio.h>
#include "regresion_lineal.h"

#define NDATA 256

int estimaQuiebre(double x[], double y[]);

int main(int argc, char* argv[])
{
	if (argc != 2)
		puts("invalid command");
	FILE *f;
	f = fopen(argv[1], "r");
		if (f == NULL)
		{
			puts("problem to open the file");
			return 1;
		}
	double x[NDATA], y[NDATA];
	int i = NDATA;
	for (i = 0; i< NDATA; i++)
	{
		x[i]= (double)i;
		fscanf(f, "%lf", &y[i]);
		printf("x[%i]: %.0lf \t y[%i]: %.2lf\n", i, x[i], i, y[i]);
	}
	printf("El valor del quiebre se produce en: %d\n", estimaQuiebre(x,y));
	fclose(f);
	return 0;
}

int estimaQuiebre(double x[], double y[])
{
	FitParams foo1, foo2;
	int i, j;
	double valor_quiebre;
	for (i = 0; i<NDATA; i++)
	{
		foo1 = fitLineal(NDATA - i, x + i, y + i);
		foo2 = fitLineal(i, x+NDATA-i, y+NDATA-i);
		if (i==0)
			valor_quiebre = foo1.chi2 + foo2.chi2;
		if ( (foo1.chi2 + foo2.chi2) < valor_quiebre)
		{
			valor_quiebre = foo1.chi2 + foo2.chi2;
			j = i;
		}	
	}
	return j;
}
