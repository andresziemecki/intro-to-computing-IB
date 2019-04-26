Otros ejemplos de punteros:
	double *pd;
	struct complex *pc;
	char **ppc;
	int *ap[15];
	int (*fp)(char *);
	int *f(char *);

Equivalencia:
	pc->re ≡ (*pc).re

Un vector es un puntero al primer elemento del vector.
	int vec[100];
	int *pi = vec;

Los vectores son punteros que no pueden ser “reapuntados”.
	int a, v1[10], v2[10], *pi;
	pi = &a;
	pi = v1;
	pi = &v2[3];
	v2 = v1; <<< Error: v2 es un puntero, pero no lo puedo reasignar

Resta de 2 punteros del mismo tipo. El resultado es un entero con
signo (entero de tipo ptrdiff_t).

Equivalencias.
	*(ptr + i) ≡ ptr[i]
	(ptr + i) ≡ &ptr[i]

Punteros a funcion. Declaración de una variable puntero a función:
	int (*fnPtr)(void);
Esto declara la variable fnPtr como un puntero a una función que retorna un entero y no recibe argumentos.
Asignación de un puntero a función:
	fnPtr = rand;
Llamado a una función a través de un puntero a función:
	int r = fnPtr();
	
Puntero a función como argumento de una función:
	#include <math.h>
	typedef double(*fun_ptr_type)(double);
	double integra(double x0, double x1, fun_ptr_type fun);
	int main() {
	double i;
	i = integra(0, M_PI, sin);
	i = integra(0, M_PI, cos);
	return 0;}
	
	
Las matrices, o arreglos de más de una dimensión, no tienen una equivalencia directa con los punteros.
	int *ptr, v[5], a[3][3];
		ptr = &v[1];<<< OK
		ptr = v;	<<< OK
		ptr[4] = 8; <<< OK
		ptr = a;   		<<< Error
		ptr[1][1] = 8; 	<<< Error
		ptr = &a[0][0];	 <<< OK
		ptr[3*1+1] = 8;	 <<< OK
		
Las punteros pueden apuntar a su vez a otros punteros. De esta forma se puede imitar la sintaxis de los arreglos multidimensionales.
	int ***ptr, t[3][3][3];
	// Inicializando apropiadamente ptr podríamos usarlo como si fuera un arreglo similar a t
	t[1][0][3] = 3;
	ptr[1][0][3] = 8; // que es equivalente a *(*(*(ptr + 1))+3)
	// Pero no podemos inicializarlo así
	ptr = t;	<<< Error // Ya que t es equivalente a un int * y no a un int ***
	
ENUMERACIONES - pagina 197

UNIONES - pagina 199

BIT FIELDS - pagina 202

PILA STACK -pagina 206

QUEUE - pagina 213

LISTAS - pagina 223

LISTAS DOBLEMENTE LIGADAS - pagina 228

ARBOLES BINARIOS - pagina 229

FUNCIONES HASH - pagina 237

