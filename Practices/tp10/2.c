#include <stdio.h>
#include <stdlib.h>

#define N 6


typedef struct {
	int i;
	int j;
	int value;
	
} Terna;

int compare (const void * a, const void * b);

void Imprime_vector (Terna *z, int n);


int main(void)
{
	Terna x_Terna[N];
	
	
	for (int i = 0; i<N; i++){
		x_Terna[i].value = i;
	}
	
	Imprime_vector(x_Terna, N); 
	
	qsort(x_Terna, N, sizeof(Terna), compare);
	
	Imprime_vector(x_Terna, N); 
	
	return 0;
}

int compare (const void * a, const void * b)
{
  return ( ((Terna*)b)->value - (*(Terna*)a).value );
}

void Imprime_vector (Terna *z, int n)
{
	for (int i = 0; i< n; i++)
	{
		printf("%d\t", z[i].value );
	}
	puts("\n");
	return;
}
