#include <stdio.h>
#include <stdlib.h>

void limpiar_tablero (int array[][8]);

void encontrar_soluciones (int tabla[][8], int m, int n);

void imprimir_tabla (int tabla[][8]);

int main (void)
{
	// inicio la tabla
	int tabla[8][8];

	//limpio la tabla
	limpiar_tablero(tabla);

	// imprimo la tabla para ver si la limpio bien
	imprimir_tabla(tabla); 

	//Hace todos los movimientos posibles siguiendo el patron: (arriba-izquierda; arriba-derecha; abajo-derecha; abajo-izquierda; derecha-arriba; etc)
	for (int n = 0; n < 4; n++)
	{
		for (int m = 0; m < 4; m++)
		{
 			encontrar_soluciones(tabla, m, n);
			imprimir_tabla(tabla);
			limpiar_tablero(tabla);
		}
	}

	// fin del programa
	return 0;
}

void limpiar_tablero(int array[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            array[i][j] = 0;
        }
    }
    return;
}

void encontrar_soluciones (int tabla[][8], int m, int n)
{
	int verdad = 1;
	while (verdad != 0)
    	{
        	if ( (m + 2) < 8 && (n + 1) < 8 && tabla[m+2][n+1] == 0)
        	{
            		m = m+2;
            		n = n+1;
            		verdad = 1;
            		tabla[m][n] = verdad;
        	}
        	else if ( (m + 2) < 8 && (n - 1) > 0 && tabla[m+2][n-1] == 0)
        	{
            		m = m+2;
            		n = n-1;
            		verdad = 1;
            		tabla[m][n] = verdad;
        	}
        	else if ( (m - 2) > 0 && (n + 1) < 8 && tabla[m-2][n+1] == 0)
        	{
            		m = m-2;
            		n = n+1;
            		verdad = 1;
            		tabla[m][n] = verdad;
        	}
        	else if ( (m - 2) > 0 && (n - 1) > 0 && tabla[m-2][n-1] == 0)
        	{
            		m = m-2;
            		n = n-1;
            		verdad = 1;
            		tabla[m][n] = verdad;
        	}
        	else if ( (n + 2) < 8 && (m + 1) < 8 && tabla[m+1][n+2] == 0)
        	{
            		n = n+2;
            		m = m+1;
            		verdad = 1;
            		tabla[m][n] = verdad;
        	}
        	else if ( (n + 2) < 8 && (m - 1) > 0 && tabla[m-1][n+2] == 0)
        	{
            		n = n+2;
            		m = m-1;
            		verdad = 1;
            		tabla[m][n] = verdad;
        	}
        	else if ( (n - 2) > 0 && (m + 1) < 8 && tabla[m+1][n-2] == 0)
        	{
            		n = n-2;
            		m = m+1;
            		verdad = 1;
            		tabla[m][n] = verdad;
        	}
        	else if ( (n - 2) > 0 && (m - 1) > 0 && tabla[m-1][n-2] == 0)
        	{
            		n = n-2;
            		m = m-1;
            		verdad = 1;
            		tabla[m][n] = verdad;
        	}
        	else
        	{
        	    verdad = 0;
        	}
	}
	printf("\n");
	return;
}

void imprimir_tabla (int tabla[][8])
{
	for (int i = 0; i < 8; i++)
    	{
        	for (int j = 0; j < 8; j++)
        	{
            		printf("%d ", tabla[i][j]);
        	}
        	printf("\n");
    	}
	printf("\n");
	return;
}
