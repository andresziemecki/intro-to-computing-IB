#include <stdio.h>
#include "misfuncs.h"

#define N 5

int main(void)
{
	double v[N];
	IngreseVector(v, N);
	Ordenamiento(v, N);
	ImprimeVector(v, N);
	return 0;
}
