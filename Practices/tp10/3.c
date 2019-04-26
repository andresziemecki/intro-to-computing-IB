#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int compare (const void * a, const void * b);

int main(int argc, char *argv[])
{
	qsort(argv, argc, sizeof(char *), compare);
	int n;
	for (int i = 0; i<argc; i++){
		for (int j = 0, n = strlen(argv[i]); j<n; j++){ 
		printf("%c", argv[i][j]);
		}
	puts("\n");
	}
	
	return 0;
}

int compare (const void * p1, const void * p2) // como entra un puntero de un puntero hay que castear a string
{
	char **ps1 = (char **)p1;
	char **ps2 = (char **)p2;
	return strcmp(*ps1, *ps2);
}

