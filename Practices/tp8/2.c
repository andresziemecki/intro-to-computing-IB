#include <stdio.h>

int MCD (int A,int B);

int main(void)
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("MCD = %d\nMCM = %d\n", MCD(a,b), (a*b)/MCD(a,b));
	return 0;
}

int MCD (int A, int B)
{
	if (A > B)
		A = A%B;
	else
		B = B%A;
	if (A == 0)
		return B;
	else if (B == 0)
		return A;
	else
		return MCD (A,B);
}
