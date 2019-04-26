#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main (void)
{
	srand(time(NULL));
	double x, y;
	int n = 0, N = 0;
	do
	{
	x = (double)rand()/(double)RAND_MAX;
	y = (double)rand()/(double)RAND_MAX;
	(sqrt(x*x+y*y) < 1) && n++;
	N++;
	if (N > 10000000)
		break;
	}
	while(1);
	printf("%f\n", 4.0*(float)n/(float)N);
	return 0;
}
