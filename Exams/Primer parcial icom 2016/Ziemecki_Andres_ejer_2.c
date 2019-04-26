#include <stdio.h>
#define X 500
#define Y 125250
int V[X][X];

typedef struct {
int i;
int j;
int v;
} Terna_t;

void Ordenamiento(Terna_t Vector[], int NumElementos);
void ImprimeVector(Terna_t Vector[], int NumElementos);
void Uber (Terna_t Vector[], int numUber);

int main(void)
{
	Terna_t Vector[Y+1];
	int z = 0;
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (j>=i)
			{
				Vector[z].v = (i+1)*(i+1)*(i+1) + (j+1)*(j+1)*(j+1);
				Vector[z].i = i+1;
				Vector[z].j = j+1;
				z++;
			}
		}
	}
	
	Ordenamiento(Vector, z);
	
	
	Uber(Vector, 1);
	Uber(Vector, 2);
	Uber(Vector, 3);
	
	return 0;

}

void Ordenamiento(Terna_t Vector[], int NumElementos)
{
	int x, z = 1;
	while(z == 1)
	{
		z = 0;
		for(int i = 0; i < NumElementos - 1; i++)
		{
			if (Vector[i].v > Vector[i+1].v)
			{	int q, w;
				x = Vector[i].v;
				q = Vector[i].i;
				w = Vector[i].j;
				Vector[i].v = Vector[i+1].v;
				Vector[i].i = Vector[i+1].i;
				Vector[i].j = Vector[i+1].j;
				Vector[i+1].v = x;
				Vector[i+1].i = q;
				Vector[i+1].j = w;
				z = 1;
			}
		}
	}
	return;
}

void ImprimeVector(Terna_t Vector[], int NumElementos)
{
	for (int i = 0; i < NumElementos; i++)
	{
		printf("%d\n", Vector[i].v);
	}
	return;
}

void Uber (Terna_t Vector[], int numUber)
{
	int i = 0;
	if (numUber == 1)
	{
		printf("El primer numero de Uber es: %d dado por los numeros %d y %d\n", Vector[i].v, Vector[i].i, Vector[i].j); 
	}
	else if (numUber == 2)
	{
		while (Vector[i].v != Vector[i+1].v)
			i++;
		printf("El segundo numero de Uber es: %d dado por los numeros (%d , %d) y (%d , %d)\n", Vector[i].v, Vector[i].i, Vector[i].j, Vector[i+1].i, Vector[i+1].j); 
	}
	else if(numUber == 3)
	{
		while ( (Vector[i].v != Vector[i+1].v) || (Vector[i+1].v != Vector[i+2].v) || (Vector[i].v != Vector[i+2].v) )
			i++;
		printf("El tercer numero de Uber es: %d dado por los numeros (%d , %d) , (%d , %d) y (%d , %d)\n", Vector[i].v, Vector[i].i, Vector[i].j, Vector[i+1].i, Vector[i+1].j, Vector[i+2].i, Vector[i+2].j); 
	}
	else
	{
		printf("Error!\n");
	}
	return;
}
