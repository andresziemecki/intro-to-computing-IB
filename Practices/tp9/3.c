#include <stdio.h>

int CompareStrings(const char *str1, const char *str2);

int main(void)
{
	 const char *string = "hola";
	 const char *string2 = "hola";
	 const char *string3 = "holo";
	
	printf("%d\n", CompareStrings(string, string2)); 
	
	printf("%d\n", CompareStrings(string2, string3));
	
	printf("%d\n", CompareStrings(string3, string2));
	
	return 0;
}

/* cambiar un const es posible:

void foo(const char *a){
	char *b;
	b = (char *)a;
	*b = '0';
}*/

int CompareStrings(const char *str1, const char *str2)
{
	int i = 0;
	// otra forma de hacerlo: while(*str1 && *str2 && *(str1++) == *(str2++));
	while((*(str1 + i) == *(str2 + i)) && *(str1 + i) && *(str2 + i))
		i++;
	return *(str1 + i) - *(str2 + i);
}
