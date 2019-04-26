#include <stdio.h>
#include <ctype.h>

int main (void)
{
	int c, caracteres = 0, lineas = 0, palabras = 0;
        int enpal = 0;
	while ((c = getchar()) != EOF)
	{	
		caracteres++;
		if (c == '\n') {
			lineas++;
			palabras++;
		}
		if ( c == ' ' || c == '\t')
		    palabras++;
		}
	printf("caracteres: %d\t lineas: %d\t palabras: %d\n", caracteres, lineas, palabras);
	return 0;
}
