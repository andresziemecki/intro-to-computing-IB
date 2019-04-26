#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double generanums(double nums[1000]);
double media(double array[1000]);

int main(void)
{
	double muestra[1000];
	double Sn[10000];
	srand(time(NULL));
	for (int i= 0; i< 10000; i++)
	{
		Sn[i]=generanums(muestra);
	}
	for (int j= 0; j< 10000; j++)
	{
		printf("%lf\n", Sn[j]);
	}
	return 0;
}

double generanums(double nums[1000])
{
	for (int i=0; i<1000; i++)
	{
		nums[i]=(double)rand()/RAND_MAX;
	}
	return media(nums);	
}


double media(double array[1000])
{
	double suma = 0;
	for (int i = 0; i < 1000; i++)
	{
		suma += array[i];
	}
	return (suma/1000);
}

/*
double varianza(double array[], double media, int n)
{
	double suma;
		for (int i = 0; i < n; i++)
	{
		suma += array[i]*array[i];
	}	
	return (suma/(double)n - media*media);
}
*/
