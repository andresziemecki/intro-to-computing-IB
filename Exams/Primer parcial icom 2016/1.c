#include <stdio.h>
#include <math.h>

void imprimir(char vector[]);

void hanoi(int n, char from[], char aux[], char to[])
 {
 	static int nmvs = 0;
 	static int nextprint = 2;
 	
	if( n == 1 )
	 {
		nmvs++;
		//buscar las ultimas posicione de cada array
 		int i = 0;
 		int j = 0;
		while(from[i] != '\0')
			i++;
		while(to[j] != '\0')
			j++;
		
		// mover de from a to
		to[j] = from[i-1];
		from[i-1] = '\0';
		
		//imprime 
		if (nmvs == nextprint-1)
        {
            printf("\n\nNumero de Movimientos = %d\n",nmvs);
            		imprimir(from);
					imprimir(aux);
					imprimir(to);
            nextprint <<= 1;
            printf("-----------\n");
        }
		return;
	 }
	hanoi(n-1, from, to, aux);
	hanoi(1, from, aux, to);
	hanoi(n-1, aux, from, to);
}

int main() 
{
	char A[13]="A:9876543210";
	char B[13]="B:";
	char C[13]="C:";
	hanoi(10, A, B, C);
	return 0;
}

void imprimir(char vector[])
{
	int j = 0;
	while (vector[j] != '\0')
	{
		printf("%c", vector[j]);
		j++;
	}
	printf("\n");
	return;
}
