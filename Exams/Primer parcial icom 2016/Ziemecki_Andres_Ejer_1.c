#include <stdio.h>
#include <math.h>

void imprimir(char vector[]);

int N = 0;

void hanoi(int n, char from[], char aux[], char to[])
 {
 	N++;
	if( n == 1 )
	 {
		
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
		imprimir(from);
		imprimir(aux);
		imprimir(to);
		printf("-----------\n");
		
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
