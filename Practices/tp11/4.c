#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
	int grado;
	double *coefs;
} Polinomio_t;

Polinomio_t *pol_aloc( int grado );
void pol_free (Polinomio_t *pPol);
int pol_set_coef (Polinomio_t *pPol, int cIdx, double v);
double pol_eval (Polinomio_t *pPol, double x);
Polinomio_t *pol_deriv(Polinomio_t *pPol);
Polinomio_t *pol_integ(Polinomio_t *pPol);

void imprime_pol(Polinomio_t *pPol, int n);
double potencia (double x, int n);

int main(void)
{
	Polinomio_t *pol = pol_aloc(5);
	
	for (int i = 1; i <= 4; i++)
	{
		pol_set_coef( pol, i-1, 5-i );
	}
	imprime_pol(pol, 5);
	pol = pol_deriv(pol);
	imprime_pol(pol, 5);
	pol = pol_integ(pol);
	imprime_pol(pol, 6);
	pol_free(pol);
	return 0;
}

Polinomio_t *pol_aloc( int grado )
{
	int i;
	
	Polinomio_t *pPol = (Polinomio_t *) malloc(sizeof(Polinomio_t));
	assert(pPol);
	
	pPol->grado = grado;
	pPol->coefs = (double *) malloc((grado+1) * sizeof(double));
	assert(pPol->coefs);
	
	for (i = 0; i<= grado; i++)
	{
		pPol->coefs[i] = 0;
	}
	
	return pPol;
}

void pol_free (Polinomio_t *pPol)
{
	free(pPol->coefs);
	free(pPol);
	return;
}

int pol_set_coef (Polinomio_t *pPol, int cIdx, double v)
{
	if (cIdx >= 0 && cIdx <= pPol->grado)
	{
		pPol->coefs[cIdx] = v;
		return 1;
	}
	
	return 0;
}

Polinomio_t *pol_deriv(Polinomio_t *pPol)
{
	for (int i = 0; i < pPol->grado; i++)
	{
		pPol->coefs[i] = *(pPol->coefs + i + 1)*(i+1);
	}
	return pPol;
}

double pol_eval (Polinomio_t *pPol, double x)
{
	int i;
	double result = 0;
	for (i = 0; i < pPol->grado; i++);
	{
		result = result + pPol->coefs[i]*potencia(x, i); 
	}
	return result;
}

double potencia (double x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
		
	double result = x;
	for (int i = 0; i < n-1; i++)
	{
		result *= x;
	}
	return result;
}

void imprime_pol(Polinomio_t *pPol, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%lfx%d\t", pPol->coefs[i], i);
	}
	puts("\n");
	return;
}

Polinomio_t *pol_integ(Polinomio_t *pPol)
{
	int i; 
	Polinomio_t *pPol2 = pol_aloc( pPol->grado + 1);
	
	pPol2->coefs[0] = 0;
	for (int i = 1; i <= pPol->grado; i++)
	{
		*(pPol2->coefs + i) = *(pPol->coefs + i - 1)/(i);
	}
	pol_free(pPol);
	return pPol2;
	
}
