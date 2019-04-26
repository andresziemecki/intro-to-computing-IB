#include <stdio.h>

int main(void)
{
	/*
	*
	*
	Parte A
	*
	*
	*/
	int i = 1;
	float f = 1;
	printf("%i\n%f\n", i ,f);
	printf("%+i\n%+f\n", i ,f);
	/*
	*
	*
	Parte B
	*
	*
	*/
	printf(".2f = %.2f\n.8f = %.8f\n.15f = %.15f\n.15f = %.15e\n.30f = %.30f\n", f, f, f, f, 1.0/10.0);
	/*
	*
	*
	Parte C
	*
	*
	*/
	double planck;
	planck = 6.62606869e-34;
	printf("%.6e\n", planck); 
	return 0;
}
