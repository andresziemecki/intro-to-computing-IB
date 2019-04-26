#include <stdio.h>

typedef struct Punto2D {
int x;
int y;
} punto2d;

typedef struct complex {
float re;
float im;
} complejo;

void imp(void *); //imprime direccion

int main(void)
{	char a[2];
	int b[2];
	float c[2];
	double d[2];

	complejo c1[2];
	punto2d c2[2];
	
	imp(a);
	imp(&a[1]);
	imp(b);
	imp(&b[1]);
	imp(c);
	imp(&c[1]);
	imp(d);
	imp(&d[1]);
	imp(&c1[0]);
	imp(&c1[1]);
	imp(&c2[0]);
	imp(&c2[1]);
	
	printf("holaaa! %ld\n",(int)&c1[1]-(int)&c1[0]);
	int l;
	l = 1;
	#if __BYTE_ORDER == __LITTLE_ENDIAN
		printf("hola! little\n");
	#else
		printf("BIG!!\n");
	#endif
	*((char *)&l + 3)=5;
	
	printf("l vale: %d\n", l);
	return 0;
}

void imp(void *dir)
{
	printf("%p\n", dir);
	return;
}
