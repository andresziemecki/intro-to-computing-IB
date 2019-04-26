#include <stdio.h>

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
	printf("\n");
	return 0;
}
void tiramenum(int num, int base)
{
	if (num)
		tiramenum(num/base, base);
	else
		return;
		if (num%base == 10)
			printf("%c", 'A');
		else if (num%base == 11)
			printf("%c", 'B');
		else if (num%base == 12)
			printf("%c", 'C');
		else if (num%base == 13)
			printf("%c", 'D');
		else if (num%base == 14)
			printf("%c", 'E');
		else if (num%base == 15)
			printf("%c", 'F');
		else
			printf("%d", num%base);
	return;
}
