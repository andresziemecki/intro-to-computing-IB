#include <stdio.h>

double calculaE();

int main(void)
{
	printf("e=%.5lg\n", calculaE());
	return 0;
}

double calculaE()
{
	double fact = 1.0, suma = 1.0;
	for (int i=1; i <= 30; i++)
	{	
		fact *= i;
		suma = suma + 1.0/fact;
	}
	return suma; 
}

