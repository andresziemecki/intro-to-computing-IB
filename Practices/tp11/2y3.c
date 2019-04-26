#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define dim 3

double **AllocaMatSimetrica(int n);
void LiberaMatSimetrica(double **pMat, int n);
double GetElement(double **pMat, int n, int i, int j);
void SetElement(double **pMat, int n, int i, int j, double X);
double **multiplicacion_matriz_simetrica(double **A, double **B, int n);
double **aloca_matriz(int n);
void imprime_matriz_simetrica(double **matriz);
double **suma_matriz_simetrica(double **A, double **B, int n);
void libera_matriz(double **pMat, int n);
void imprime_matriz(double **pMat);
int main(void)
{
	double x;
	double **matriz1 = AllocaMatSimetrica(dim);
	double **matriz2 = AllocaMatSimetrica(dim);
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("ingrese el elemento %d y %d de la matriz A: ", i, j);
			scanf("%lf", &x);
			SetElement(matriz1, dim, i, j, x);
		}
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("ingrese el elemento %d y %d de la matriz B: ", i, j);
			scanf("%lf", &x);
			SetElement(matriz2, dim, i, j, x);
		}
	}
	imprime_matriz_simetrica(matriz1);
	imprime_matriz_simetrica(matriz2);
	
	// multiplicacion de matrices simetricas
	double **matriz4 = multiplicacion_matriz_simetrica(matriz1, matriz2, dim);
	imprime_matriz(matriz4);
	
	//suma de matrices simètricas
	double **matriz3 = suma_matriz_simetrica(matriz1, matriz2, dim);
	imprime_matriz_simetrica(matriz3);
	
	
	LiberaMatSimetrica(matriz1, dim);
	LiberaMatSimetrica(matriz2, dim);
	
	// libera la matriz e la suma
	LiberaMatSimetrica(matriz3, dim);
	
	// libera la matriz de la multiplicacion
	libera_matriz(matriz4, dim);
	
	return 0;
}


double **AllocaMatSimetrica(int n)
{
	double **matriz;
	matriz = (double **) malloc(n*sizeof(double*));
	assert(matriz);
	for (int i = 0; i < n; i++)
	{
		*(matriz + i) = (double*) malloc((i+1)*sizeof(double));
		assert(matriz[i]);
	}
	return matriz;
}

void LiberaMatSimetrica(double **pMat, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(*(pMat + i));
	}
	free(pMat);
	return;
}

double GetElement(double **pMat, int n, int i, int j) // de que me sirve el "n"?
{
	if(i>=n || j>=n || i<0 || j<0){
		printf("Hola!\n");
	}
	if (j>i)
		return pMat[j][i];
	else
		return pMat[i][j];	
}

void SetElement(double **pMat, int n, int i, int j, double X)
{
	double *pointer;
	if(j>i){
		*(*(pMat+j)+i)=X;   // = pMat[j][i]
	}
	else{
		*(*(pMat+i)+j)=X;
	}
	return;
}

double **aloca_matriz(int n)
{
	//define matriz
	double **matriz;
	
	// aloca la cantidad de filas
	matriz = (double **) malloc(n*sizeof(double*));
	assert(matriz);
	
	//aloca la cantidad de columnas en cada fila
	for (int i = 0; i < n; i++)
	{
		*(matriz + i) = (double*) malloc(n*sizeof(double));
		assert(matriz[i]);
	}
	
	return matriz;
}

double **multiplicacion_matriz_simetrica(double **A, double **B, int n)
{
	double **matriz;
	matriz = aloca_matriz(n);
	double x;
	
	int i, j, k;
	for (k = 0; k < n; k++)
	{
		for ( i = 0; i < n; i++)
		{
			x = 0;
			//matriz[k][i];
			for (j = 0; j < n; j++)
			{
				//matriz[k][i] = matriz[k][i] + A[i][j]*B[j][i];
				x = x + (GetElement(A, n, i, j)*GetElement(B, n, i, j));
			}
			*(*(matriz+k)+i) = x;
		}
	}
	return matriz;
}

void imprime_matriz_simetrica(double **matriz)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			printf("%.1lf\t", GetElement(matriz, dim, i, j));
		}
		puts("\n");
	}
	puts("-----------------------------------\n");
	return;
}

double **suma_matriz_simetrica(double **A, double **B, int n)
{
	double **matriz;
	matriz = aloca_matriz(n);
	
	int i, j;
		for ( i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				SetElement(matriz, n, i, j, 0);
				//matriz[i][j] = 0;
				SetElement(matriz, n, i, j, (GetElement(A, n, i, j)+GetElement(B, n, i, j)));
				//matriz[i][j] = A[i][j] + B[i][j];
			}
		}
	return matriz;
}

void imprime_matriz(double **pMat)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			printf("%.1lf\t", *(*(pMat+i)+j));
		}
		puts("\n");
	}
	puts("-----------------------------------\n");
	return;
}

void libera_matriz(double **pMat, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(*(pMat + i));
	}
	free(pMat);
	return;
}

