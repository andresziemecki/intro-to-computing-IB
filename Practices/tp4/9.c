#include <stdio.h>
/*

int main(void)
{
	int array[32];
	int num, base, i = 0;
	printf("inserte le numero que desea transormar: ");
	scanf("%d", &num);
	do
	{
		printf("inserte la base a la que la desea transformar: ");
		scanf("%d", &base);
	}
	while (base > 16 || base < 1);
	while(num > 0)
	{
		array[i] = num%base;
		i++;
		num = num/base;
	}
	for (i--; i >= 0; i--)
	{
		if (array[i] == 10)
			printf("%c", 'A');
		else if (array[i] == 11)
			printf("%c", 'B');
		else if (array[i] == 12)
			printf("%c", 'C');
		else if (array[i] == 13)
			printf("%c", 'D');
		else if (array[i] == 14)
			printf("%c", 'E');
		else if (array[i] == 15)
			printf("%c", 'F');
		else
			printf("%d", array[i]);
	} 
	printf("\n");
	return 0;
}

*/
void tiramenum(int num, int base);
int main(void)
{
int num, base, i = 0;
	printf("inserte le numero que desea transormar: ");
	scanf("%d", &num);
	do
	{
		printf("inserte la base a la que la desea transformar: ");
		scanf("%d", &base);
	}
	while (base > 16 || base < 1);
	tiramenum(num, base);
	return 0;
}
void tiramenum(int num, int base)
{
	if (num)
		tiramenum(num/base, base);
	else
		return;
	printf("%d", num%base);
	return;
}


