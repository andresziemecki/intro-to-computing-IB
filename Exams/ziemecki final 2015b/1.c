#include <stdio.h>
#include <string.h>
#include <ctype.h>


int is_anagrama(const char *str1, const char *str2);
void sort(int vector[], int dim);

int main (void)
{
	char str1[20] = "Salvador Dali";
	char str2[19] = "Avida Dollars";
	
	if(is_anagrama(str1,str2))
		puts("si");
	else
		puts("no");
	return 0;
}




int is_anagrama(const char *str1, const char *str2)
{
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	if (n1 != n2)
		return 0;
	int string1[n1];
	int string2[n1];
	int i;
	for (i = 0; i < n1; i++)
		string1[i] = (int)(tolower(str1[i]));
	for (i = 0; i < n1; i++)
		string2[i] = (int)(tolower(str2[i]));
	sort(string1, n1);
	sort(string2, n1);
	for (i = 0; i< n1; i++)
	{
		if (string1[i] != string2[i])
			return 0;
	}
	return 1;
}

void sort(int vector[], int dim)
{
	int i, k =1, aux;
	while ( k != 0)
	{
		k = 0;
		for (i = 0; i < dim - 1; i++)
		{
			if (vector[i] > vector[i+1])
			{
				aux = vector[i+1];
				vector[i+1] = vector[i];
				vector[i] = aux;
				k++;
			}
		}
	}
	return;
}
