#include <stdio.h>
#include <stdlib.h>

void creartablero(char tabla[8][8]);
void imprimirtabla(char tabla[8][8]);
int cantidadmax(char tabla[8][8]);
int checkamenaza(char tabla[8][8], int x, int y);
void ponechar(char tabla[8][8],int posx,int posy, char c);

int main(void)
{
	char tabla[8][8] = {0};
	//imprimirtabla(tabla);
	creartablero(tabla);
	imprimirtabla(tabla);
	printf("La cantidad maxima es: %d\n", cantidadmax(tabla)/(7*6*5*4*3*2));
	//imprimirtabla(tabla);
	return 0;
}

void creartablero(char tabla[8][8])
{
	int i, j, k;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j+=2)
			tabla[i][j] = 'N';
		for (k = 1; k < 8; k+=2)
			tabla[i][k] = '0';
	}
	for (i = 0; i < 8; i += 2)
	{
		for (j = 0; j < 8; j+=2)
			tabla[i][j] = '0';
		for (k = 1; k < 8; k+=2)
			tabla[i][k] = 'N';
	}
	return;
}

void imprimirtabla(char tabla[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			printf(" %c", tabla[i][j]);
		printf("\n");
	}
	printf("----------------------------------------\n");
	return;
}


int checkamenaza(char tabla[8][8], int x, int y)
{
	if (tabla[x][y] == '0' || tabla[x][y] == 'A')
		return 0;
	int i=1, j=1; 
	while( ( (x+i) < 8 ) && ( (y+j) < 8 ) )
	{
		if (tabla[x+i][y+j] == 'A')
			return 0;
		i++;
		j++;
	}
	
	i = 1;
	j = 1;
	while( ( (x-i) >= 0 ) && ( (y-j) >= 0 ) )
	{
		if(tabla[x-i][y-j] == 'A')
			return 0;
		i++;
		j++;
	}
	i = 1;
	j = 1;
	while( ( (x+i) < 8) && ( (y-j) >= 0 ) )
	{
		if(tabla[x+i][y-j] == 'A')
			return 0;
		i++;
		j++;
	}
	i = 1;
	j = 1;
	while( ( (x-i) >= 0 ) && ( (y+j) < 8 ) )
	{
		if(tabla[x-i][y+j] == 'A')
			return 0;
		i++;
		j++;
	}
	return 1;
}

int existeotra(char tabla[8][8])
{
	int i, j;
	for (i = 0; i< 8; i++)
	{
		for (j = 0; j< 8; j++)
		{
			if (checkamenaza(tabla, i, j))
				return 1;
		}
	}
	return 0;
}

int cantidadmax(char tabla[8][8])
{
	static int max = 0, num = 0, iteraciones = 0;
	int i, j;
	for(i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			if(checkamenaza(tabla, i, j))
			{
				ponechar(tabla, i, j, 'A');
				num++;
				if (num > max)
					max = num;
				if (num == 7)
					iteraciones++;
				cantidadmax(tabla);
				ponechar(tabla, i, j, 'N');
				num--;
			}
		}
	}
	return iteraciones;
}

void ponechar(char tabla[8][8],int posx,int posy, char c)
{
	tabla[posx][posy] = c;
	return;
}
