#include <stdio.h>

int numOnes(int value);
int setBit(int value, int bit);
int resetBit(int value, int bit);
int testBit(int value, int bit);

int main(void)
{
	int value, bit;
	printf("ingrese el valor: ");
	scanf("%d", &value);
	printf("ingrese el bit para setBit: ");
	scanf("%d", &bit);
	printf("el bit esta en: %d\n", testBit(value, bit));
	return 0;
}

int setBit(int value, int bit)
{
	int x = 1;
	x = x << (bit-1);
	value = x | value;
	return value;
}
int numOnes(int value)
{
	int i = 0;
	while(value != 0)
	{
		if (value%2 == 1)
			i++;
		value/=2;
	}
	return i; 
}

int resetBit(int value, int bit)
{
	int x = 1;
	x = x << (bit - 1);
	x = ~x;
	value = x & value;
	return value;
}

int testBit(int value, int bit)
{
	int x = 1;
	x = x << (bit - 1);
	value = x & value;
	if (value) 
		return 1;
	else
		return 0;
}
