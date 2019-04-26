#include <stdio.h>
#include <math.h>
#define N 6

double promedio(double datos[], int n);
double standard(double datos[], int n);
void IngreseVector(double Vector[], int NumElementos);

int main(void)
{
	double v[N];
	IngreseVector(v, N);
	printf("promedio: %.2lf\t y desviacion estandar: %.2lf\n", promedio(v, N), standard(v, N));
	return 0;
}

double promedio(double datos[], int n)
{
	double suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += datos[i];
	}
	return suma/(double)n;
}
double standard(double datos[], int n)
{
	double promedio = 0, desviacion = 0;
	for (int i = 0; i < n; i++)
	{
		promedio += datos[i];
	}
	promedio = promedio/(double)n;
	for (int j = 0; j < n; j++)
	{
		desviacion = desviacion + (promedio - datos[j])*(promedio - datos[j]);
	}
	desviacion /= (double)(n-1);
	return sqrt(desviacion);
}
void IngreseVector(double Vector[], int NumElementos)
{
	for (int i = 0; i < NumElementos; i++)
	{
		scanf("%lf", &Vector[i]);
	}
	return;	
}
