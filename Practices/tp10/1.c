#include <stdio.h>
#include <math.h>

#define N 100

typedef double(*fun_ptr_type)(double);
double integra(double a, double b, fun_ptr_type fun);
double area_bajo_recta (double fa, double fb, double subint);
double funcion_x_al_cuadrado (double x);


int main(void)
{
	double a = 0, b = M_PI;
	//printf("%lf\n", integra(a, b, sin));
	printf("%lf\n", integra(a, b, funcion_x_al_cuadrado));
}

double integra(double a, double b, fun_ptr_type fun)
{
	int i;
	double suma = 0;
	double subintervalo = (b - a)/N;
	double x;
	for (i = 0; i<N; i++)
	{
		suma = suma + area_bajo_recta(fun(x), fun(x+subintervalo), subintervalo);
		x = x + subintervalo;
	}
	return suma;
}

double area_bajo_recta (double fa, double fb, double subint)
{
	return ((fb - fa)*subint + fa*subint);
}

double funcion_x_al_cuadrado (double x)
{
	return x*x;
}
