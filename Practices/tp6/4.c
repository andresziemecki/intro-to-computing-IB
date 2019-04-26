#include <stdio.h>
#define N 5

void ImprimeVector(double Vector[], int NumElementos);
void IngreseVector(double Vector[], int NumElementos);

int main(void)
{
	double v[N];
	IngreseVector(v, N);
	ImprimeVector(v, N);
	return 0;
}

void ImprimeVector(double Vector[], int NumElementos)
{
	for (int i = 0; i < NumElementos; i++)
	{
		printf("%.2lf\t", Vector[i]);
	}
	printf("\n");
	return;
}

void IngreseVector(double Vector[], int NumElementos)
{
	for (int i = 0; i < NumElementos; i++)
	{
		scanf("%lf", &Vector[i]);
	}
	return;	
}
