#include <stdio.h>

#define MAX_WORD_SZ 32
#define MAX_WORDS 10

typedef struct 
{
	char word[MAX_WORD_SZ]; // palabra en si
	unsigned int repCnt; // cantidad de repeticiones
} StatRecord_t;


typedef struct 
{
	StatRecord_t records[MAX_WORDS];
	unsigned usedCnt; // cantidad de entradas en uso
} StatWords_t;


int cantidad_de_palabras (FILE* file);
void Tolower (char oracion[]);
int StrCmp(char Array1[], char Array2[]);
void load(FILE* file, StatRecord_t t[], int N);
int check (StatRecord_t t[], char checker[], int n);
void stringcopy(char array1[32], char array2[32]);


int main(void)
{
	FILE* file = fopen("dictionary", "r");
	if (file == NULL)
	{
		printf("problem!\n");
		return 1;
	}
	int n = cantidad_de_palabras(file);
	printf("la cantidad de palabras es de: %d\n", n);
	fclose(file);
	
	StatRecord_t palabras[n];
	
	FILE* f = fopen("dictionary", "r");
	if (f == NULL)
	{
		printf("problem!\n");
		return 1;
	}
	load(f, palabras, n);
	fclose(f);
	printf("la cantidad de holas es de: %d\n", palabras[0].repCnt);
	return 0;
}

int cantidad_de_palabras (FILE* file)
{
	int cantidad = 0;
	char c;
	while( (c = fgetc(file)) != EOF)
	{
		
		if ( c >= 'a' && c <= 'z')
		{
			cantidad++;
			do
			{
				c = fgetc(file);
			}
			while(c >= 'a' && c <= 'z');
		}
	}
	return cantidad;
}

void load(FILE* file, StatRecord_t t[], int N)
{
	char c[32];
	int i=0;
	while( fscanf(file, "%s", &c[0]) != EOF)
	{
		if (!check(t, c, N))
			{
			stringcopy(t[i].word, c);
			t[i].repCnt = 1;
			i++;
			}
	}
	return;
}

int StrCmp(char Array1[], char Array2[])
{
	Tolower (Array1);
	Tolower (Array2);
	int i = 0;
	while (Array1[i] != '\0')
	{
		if (Array1[i] == Array2[i])
			i++;
		else if (Array1[i] < Array2[i])
			return -1;
		else
			return 1;
	}
	if (Array2[i] == '\0')
		return 0;
	else
		return -1;
}

void Tolower (char oracion[])
{
	int i = 0;
	while (oracion[i] != '\0')
	{
		if (oracion[i] <= 'Z' && oracion[i] >= 'A')
			oracion[i] = oracion[i] + 'a' - 'A';
		i++;
	}
	return;
}

int check (StatRecord_t t[], char checker[], int n)
{
	int j = 0;
	while (j<n)
		{
		if(!StrCmp (t[j].word, checker))
			{
				t[j].repCnt++;
				return 1;
			}
		j++;
		}
	return 0;
}

void stringcopy(char array1[32], char array2[32])
{
	for (int i = 0; i<32; i++)
	{
		array1[i] = array2[i];
	}
	return;
}
