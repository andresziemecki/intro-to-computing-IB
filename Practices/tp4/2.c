#include <stdio.h>
int main (void)
{
	int Acum2 = 0, Acum3 = 0, Acum4 = 0, Acum5 = 0;
	for (int i = 1; i<=1000; i++)
	{
		if ( (i%2) == 0) {Acum2 = Acum2 + i;}
		if ( (i%3) == 0) {Acum3 = Acum3 + i;}
		if ( (i%4) == 0) {Acum4 = Acum4 + i;}
		if ( (i%5) == 0) {Acum5 = Acum5 + i;}
	}
	printf("La suma de los multiplos de 2 es: %d\n", Acum2);
	printf("La suma de los multiplos de 3 es: %d\n", Acum3);
	printf("La suma de los multiplos de 4 es: %d\n", Acum4);
	printf("La suma de los multiplos de 5 es: %d\n", Acum5);
	return 0;
} 
