#include <stdio.h>

void FloodFill(char M[20][20], int X, int Y);
void imprimirmatriz(char M[20][20]);

int main(void)
{
	char M[20][20] = {"--------------------",
				  "----XXX-------------",
				  "--XX---X------------",
				  "-X------XXX---------",
				  "-X---------X--------",
				  "--X---------XX------",
				  "--X-----------X-----",
				  "-X--X----------X----",
				  "-X-X-X---------X----",
				  "--X---X---------X---",
				  "------X---------X---",
				  "------X---------X---",
				  "------X----------X--",
				  "-----X-----XXX---X--",
				  "----X-----X---X--X--",
				  "----X---XX-----XX---",
				  "----X--X------------",
				  "----X--X------------",
				  "-----XX-------------",
				  "--------------------"};
	imprimirmatriz(M);
	FloodFill(M, 10, 10);
	printf("Rellenando...\n");
	imprimirmatriz(M);

	return 0;
}
void imprimirmatriz(char M[20][20])
{
	for (int i=0; i<20; i++)
		{
			for (int j=0; j<20; j++)
				printf("%c", M[i][j]);
		printf("\n");
		}
	return;
}

void FloodFill(char M[20][20], int X, int Y)
{
	if (M[X][Y] == '-')
		M[X][Y] = 'X';
	if (M[X][Y+1] != 'X')
	FloodFill(M, X, Y+1);
	if (M[X+1][Y] != 'X')
	FloodFill(M, X+1, Y);
	if (M[X][Y-1] != 'X')
	FloodFill(M, X, Y-1);
	if (M[X-1][Y] != 'X')
	FloodFill(M, X-1, Y);
	return;
}
