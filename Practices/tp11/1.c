#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


#define N 5000000


// Alloca y devuelve un vector de n doubles
double *AllocVector(int n);
// libera el vector
void FreeVector(double *pVect);
// completa el vector con valores aleatorios en [0,1]
void FillRandVector(double *pVect, int n);
// Ordena el vector en forma creciente utilizando qsort
void SortVector(double *pVect, int n);
// imprime el vector
void PrintVector(double *pVect, int n);

int compare (const void * a, const void * b);


int main(void)
{
	double *v = AllocVector(N);
	srand(time(NULL));
	FillRandVector(v , N);
	//PrintVector(v , N);
	clock_t begin = clock();
	SortVector(v, N);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("El tiempo empleado es: %lf segundos de CPU\n",time_spent);
	//PrintVector(v , N);
	FreeVector(v);
	return 0;
}

double *AllocVector(int n)
{
	double *vector = (double *) malloc( n*sizeof(double) );
	assert(vector);
	return vector;
}

void FreeVector(double *pVect)
{
	free(pVect);
	return;
}

void FillRandVector(double *pVect, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(pVect + i) = (double)rand()/RAND_MAX;
	}
	return;
}

int compare (const void * a, const void * b)
{
	double n; 
	n = ( *(double *)a - *(double *)b );
	if (n>0)
		return 1;
	else if (n<0)
		return -1;
	else
		return 0;
}

void SortVector(double *pVect, int n)
{
	qsort (pVect, n, sizeof(double), compare);
	return;
}

void PrintVector(double *pVect, int n)
{
	for(int i = 0; i< n; i++) 
	{
		printf("%lf\t", pVect[i]);
	}
	puts("\n");
	return;
}
