#include <stdio.h>
#define N 5

void ImprimeVector(double Vector[], int NumElementos);
void IngreseVector(double Vector[], int NumElementos);
void Ordenamiento(double Vector[], int NumElementos);

int main(void)
{
	double v[N];
	IngreseVector(v, N);
	Ordenamiento(v, N);
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

void Ordenamiento(double Vector[], int NumElementos)
{
	int x, z = 1;
	while(z == 1)
	{
		z = 0;
		for(int i = 0; i < NumElementos - 1; i++)
		{
			if (Vector[i] > Vector[i+1])
			{	
				x = Vector[i];
				Vector[i] = Vector[i+1];
				Vector[i+1] = x;
				z = 1;
			}
		}
	}
	return;
}
