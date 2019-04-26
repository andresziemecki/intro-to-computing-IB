#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct { 
	int valor; // valor de la denominación en centavos 
	int cantidad; // cantidad de billetes/moneda necesarios 
} Denominacion; 

typedef struct { 
	int numDenominaciones; // cantidad de denominaciones 
	Denominacion *pMonedas; // denominaciones a utilizar 
} Monedero; 

// FUNCIONES

Monedero *CreaMonedero(int numDenom);
void DestruyeMonedero(Monedero *pMonedero);
int SetDenominacion(Monedero *pMonedero, int indice, int valor);
int AgregaSueldo(Monedero *pMonedero, double montoSueldo);
int CantidadValor(Monedero *pMonedero, int valor); 

int main(void)
{
	Monedero *Mon = CreaMonedero(5);
	if(SetDenominacion(Mon, 0, 25))
		puts("OK\n");
	if(SetDenominacion(Mon, 1, 50))
		puts("OK\n");
	if(SetDenominacion(Mon, 2, 100))
		puts("OK\n");
	if(SetDenominacion(Mon, 3, 200))
		puts("OK\n");
	if(SetDenominacion(Mon, 4, 500))
		puts("OK\n");
	if(SetDenominacion(Mon, 5, 1000))
		puts("OK\n");
	else
		puts("problem\n");
	if (AgregaSueldo(Mon, 22.75))
		puts("Sueldo entregado\n");
	else
	puts("Error en entregar el sueldo\n");
	printf("La cantidad de monedas/billetes para 2275 centavos es de: %d\n", CantidadValor(Mon, 2275));
	DestruyeMonedero(Mon);
	return 0;
}

Monedero *CreaMonedero(int numDenom)
{
	Monedero *M;
	M = (Monedero *) malloc(sizeof(Monedero));
	assert(M);
	M->pMonedas = (Denominacion *) malloc( numDenom*sizeof(Denominacion) );
	assert(M->pMonedas);
	M->numDenominaciones = numDenom;
	int i;
	for (i = 0; i < numDenom; i++)
		M->pMonedas[i].cantidad = 0;
	return M;
}

void DestruyeMonedero(Monedero *pMonedero)
{
	if (pMonedero != NULL)
	{
		free(pMonedero->pMonedas);
		free(pMonedero);
	}
	return;
}

int SetDenominacion(Monedero *pMonedero, int indice, int valor)
{
	if (indice > (pMonedero->numDenominaciones - 1))
		return 0;
	pMonedero->pMonedas[indice].valor = valor;
	return 1;
}

int AgregaSueldo(Monedero *pMonedero, double montoSueldo)
{
	montoSueldo *= 100;
	int sueldo = (int)montoSueldo;
	int i;
	for (i = 0; i < pMonedero->numDenominaciones; i++ )
	{
		while (pMonedero->pMonedas[pMonedero->numDenominaciones - i -1].valor < sueldo)
		{
			pMonedero->pMonedas[pMonedero->numDenominaciones - i - 1].cantidad += pMonedero->pMonedas[pMonedero->numDenominaciones - i - 1].valor;
			sueldo -= pMonedero->pMonedas[pMonedero->numDenominaciones - i - 1].valor;
		}
	}
	return 1;
}

int CantidadValor(Monedero *pMonedero, int valor)
{
	int i = 0;
	int monedas = 0;
	for (i = 0; i < pMonedero->numDenominaciones; i++ )
	{
		while (pMonedero->pMonedas[pMonedero->numDenominaciones - i -1].valor <= valor)
		{
			printf("%d - %d\n", valor, pMonedero->pMonedas[pMonedero->numDenominaciones - i - 1].valor);
			valor = valor - pMonedero->pMonedas[pMonedero->numDenominaciones - i - 1].valor;
			monedas++;
		}
	}
	return monedas;
}


