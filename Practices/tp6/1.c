#include <stdio.h>

double F2C(double fahr);

double C2F(double celsius);

int main(void)
{
	return 0;
}

double F2C(double fahr)
{
	return (fahr-32.0)*(5.0/9.0);
}

double C2F(double celsius)
{
	return (celsius*(5.0/9.0) + 32.0);
}
