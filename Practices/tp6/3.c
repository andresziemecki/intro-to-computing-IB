#include <stdio.h>

void ImprimeVector(double Vector[], int NumElementos);

int main(void)
{
	return 0;
}

void ImprimeVector(double Vector[], int NumElementos)
{
	for (int i = 0; i < NumElementos; i++)
	{
	printf("%lf\t", Vector[i]);
	}
	return;
}
