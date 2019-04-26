#include <stdio.h>
#include "regresion_lineal.h"
#define NDATA 256

int estimaQuiebre (int n, double x[], double y[]);
void InvierteVector(double Vector[], int NumElementos);
void copiavector(double array1[NDATA], double array2[NDATA]);

int main(int argc, char *argv[])
{
	FILE* file = fopen(argv[1], "r");
	if (file == NULL)
	{
		puts("Error to open the file");
		return 1;
	}
	
	double y[NDATA];
	int j = 0;
	while(!feof(file))
	{
		fscanf(file, "%lf", &y[j]);
		j++;
	}
	
	double x[NDATA];
	for (int i = 0; i < NDATA; i++)
	{
		x[i] = i;
	}
	
	fclose(file);
	
	printf("El punto de quiebre se logra en el valor x = %d\n", estimaQuiebre(NDATA, x, y));
	return 0;
}


int estimaQuiebre (int n, double x[], double y[])
{
	double minimo, numero =  1.79e300;
	
	int referencia = 0, i;
	
	double q[NDATA];
	copiavector(y, q);
	InvierteVector(q, NDATA);
	
	FitParams parametros_1, parametros_2;
	
	for (i = 1; i < NDATA; i++)
	{
		parametros_1 = fitLineal(NDATA-i , x, y);
		parametros_2 = fitLineal(i , x, q);
		minimo = parametros_1.chi2*parametros_1.chi2 + parametros_2.chi2*parametros_2.chi2;
		if (minimo<numero)
		{
			numero = minimo;
			referencia = i;
		}
	}
	return referencia;
}

void InvierteVector(double Vector[], int NumElementos)
{
	int x;
		for(int i = 0; i < NumElementos/2; i++)
		{
			x = Vector[i];
			Vector[i] = Vector[NumElementos - i - 1];
			Vector[NumElementos - i - 1] = x;
		}
	return;
}

void copiavector(double array1[NDATA], double array2[NDATA])
{
	for (int i = 0; i<NDATA; i++)
	{
		array1[i] = array2[i];
	}
	return;
}
