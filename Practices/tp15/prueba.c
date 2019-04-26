#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *x = (int *) malloc(sizeof(int));
	free(x);
	return 0;
}
