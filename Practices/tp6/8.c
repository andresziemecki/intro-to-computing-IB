#include <stdio.h>
#define N 8

void ImprimeVector(double Vector[], int NumElementos);
void IngreseVector(double Vector[], int NumElementos);
void InvierteVector(double Vector[], int NumElementos);

int main(void)
{
	double v[N];
	IngreseVector(v, N);
	InvierteVector(v, N);
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
