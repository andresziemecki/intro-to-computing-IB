#include <stdio.h>
#include <string.h>

char *Invierte(char *str);

int main(void)
{
	char mandinga[] = "mandinga";
	printf("%s\n", mandinga);
	Invierte(mandinga);
	printf("%s\n", mandinga);
	return 0;
}

char *Invierte(char *str)
{
	int j, i = strlen(str) - 1;
	char aux;
	for (j = 0; j <= i/2; j++)
	{
		aux = *(str + j);
		*(str + j) = *(str + i - j);
		*(str + i - j) = aux;
	}
	return str;
}
