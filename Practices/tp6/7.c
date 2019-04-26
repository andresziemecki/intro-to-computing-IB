#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ImprimeVector(double Vector[], int NumElementos);
void IngreseVector(double Vector[], int NumElementos);
void Ordenamiento(double Vector[], int NumElementos);

int main(void)
{
	srand(time(NULL));
	int N;
	printf("Ingrese la cantidad de elementos: ");
	scanf("%d", &N);
	double v[N];
	clock_t begin = clock();
	IngreseVector(v, N);
	Ordenamiento(v, N);
	ImprimeVector(v, N);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("El tiempo empleado es: %lf segundos de CPU\n",time_spent);
	return 0;
}

void ImprimeVector(double Vector[], int NumElementos)
{
	for (int i = 0; i < NumElementos; i++)
	{
		printf("%.2lf\n", Vector[i]);
	}
	printf("\n");
	return;
}

void IngreseVector(double Vector[], int NumElementos)
{
	for (int i = 0; i < NumElementos; i++)
	{
		Vector[i] = rand();
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
