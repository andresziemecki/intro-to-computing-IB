#include <stdio.h>

int esDivisiblePor7 (int nro);

int main (void)
{
	for (int i = 0; i < 71; i++)
	{
		if (esDivisiblePor7(i))
			printf("%d\t es divisible por 7\n", i);
		else
			printf("%d\t no es divisible por 7\n", i);
	}
	return 0;	
}

int esDivisiblePor7 (int nro)
{
	int x;
	x = nro%10;
	x *= 2;
	nro /= 10;
	nro = nro - x;
	if (nro > 9)
		esDivisiblePor7 (nro);
	else
	{
		if (nro == 7 || nro == 0 || nro == -7)
			return 1;
		else
			return 0;
	}
}
