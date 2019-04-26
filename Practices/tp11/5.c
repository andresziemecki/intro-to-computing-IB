#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define dim 3

typedef struct
{
	double X, Y;

} Punto2D;

typedef struct
{
	int numPuntos;
	Punto2D *Vertices;

} Poligono;

double perimetro (Poligono *p);
Poligono *creaPoligono(int N);
int setVertice(Poligono *p, int n, double x, double y);
double area(Poligono *p);

int main(void) {
	Poligono *pol = creaPoligono(dim);
	setVertice (pol, 1, 1, 0);
	setVertice (pol, 2, 0, 1);
	setVertice (pol, 3, 1, 1);
	printf("el perìmetro es: %lf y el area es: %lf\n", perimetro (pol), area(pol));
	return 0;
}

Poligono *creaPoligono(int N)
{
	Poligono *pol = (Poligono *) malloc (sizeof(Poligono));
	assert(pol);
	pol->Vertices = (Punto2D *) malloc(N*sizeof(Punto2D));
	assert(pol->Vertices);
	return pol;
}

int setVertice(Poligono *p, int n, double x, double y)
{
	n = n-1;
	if ((p->Vertices + n) != NULL)
	{
		(*(p->Vertices + n)).X = x;
		p->Vertices[n].Y = y;
		return 1;
	}

	else
		return 0;

	// ESTA MAL ESTO NO MIRAR
	//pol->X; ===== (*pol).x;
	//*(V+n)  ===== V[n];

	//(*pol).Vertices[n]->x;
	//(*(*((*pol).Vertices+n))).X;

	//*(pol->Vertices + n)->X = x;
	//*((*pol).Vertices + n)->X = x;
	//(*(*((*pol).Vertices + n))).X = x;

}

double perimetro (Poligono *p)
{
	int i = 0;
	double lado1, lado2, suma = 0;
	while (i < (dim-1) ) //( (p->Vertices + i) != NULL)
	{
		lado1 = ((p->Vertices[i].X)-(p->Vertices[i+1].X));
		lado2 = ((p->Vertices[i].Y)-(p->Vertices[i+1].Y));
		suma = suma + sqrt ( lado1*lado1 + lado2*lado2 );
		//ALGUNAS FORMAS DE ANOTAR LOS PUNTEROS sqrt( (p->Vertices[i].Y) *  ( (*((*p).Vertices + i)).Y ) + (p->Vertices[i].X) * ((*(p->Vertices + i)).X) );
		i++;
	}
	
	// falta el vector del ultimo punto al primer lado
	lado1 = ((p->Vertices[0].X)-(p->Vertices[dim-1].X));
	lado2 = ((p->Vertices[0].Y)-(p->Vertices[dim-1].Y));
	suma = suma + sqrt( lado1*lado1 + lado2*lado2 );
	return suma;
}

double area(Poligono *p) // formula de heron
{
	int i;
	double area = 0, h1, h2, base;
	for (i = 0; i < (dim-1); i++)
	{
		base = p->Vertices[i+1].X - p->Vertices[i].X;
		h1 = p->Vertices[i].Y;
		h2 = p->Vertices[i+1].Y;
		area = area + base*h1 + base*(h2-h1)/2;
	}
	
	//falta el ultimo lado
		base = p->Vertices[dim-1].X - p->Vertices[0].X;
		h1 = p->Vertices[0].Y;
		h2 = p->Vertices[dim-1].Y;
		area = area + base*h1 + base*(h2-h1)/2;
	return area;
}
