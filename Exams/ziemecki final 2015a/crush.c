#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

#define HEIGHT 6
#define WIDTH  9

#define NTYPES 5

char *candy[] = {
  " ",
  "O",
  "X",
  "+",
  "#",
  "@"
};

void clear(void);
void alldown(int board[HEIGHT][WIDTH], int fila, int columna);

int swapCandy(int board[HEIGHT][WIDTH], int i, int j, int dir);

void slideBoard(int board[HEIGHT][WIDTH]);

int candyCrush(int board[HEIGHT][WIDTH]);

void fillBoard(int board[HEIGHT][WIDTH]);

void printBoard(int board[HEIGHT][WIDTH]){
printf("\n");
	int i,j;

	for(i=0;i<HEIGHT;++i){
		for(j=0;j<WIDTH;++j){
		if ( j == 0)
			printf("%d   ", i);
		printf("%s ",candy[board[i][j]]);
		}
		printf("\n");
	}
	printf("\n");
	printf("    ");
	for(i = 0; i < WIDTH; i++)
		printf("%d ", i);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int board[HEIGHT][WIDTH]={0};
	clear();
	fillBoard(board);
	printBoard(board);
	
	int x, y, z;
	while(1)
	{
		printf("Ingrese la posiciòn de la fila que desea cambiar: ");
		scanf("%d", &x);
		printf("Ingrese la posiciòn de la columna que desea cambiar: ");
		scanf("%d", &y);
		printf("RIGHT: 1 \nLEFT:  2\nUP:    3\nDOWN:  4\n Ingrese hacia donde le gustaria moverla: ");
		do
			scanf("%d", &z);
		while (abs(z)>4);
		if(swapCandy(board, x, y, z))
		{
			usleep(2000000);
			clear();
			printBoard(board);
			candyCrush(board);
			usleep(2000000);
			clear();
			printBoard(board);
			slideBoard(board);
			usleep(2000000);
			clear();
			printBoard(board);
			fillBoard(board);
			usleep(2000000);
			clear();
			printBoard(board);
		}
		else
			printBoard(board);
	}
	
	return 0;
}


void fillBoard(int board[HEIGHT][WIDTH])
{
	int i, j;
	for (i = 0; i < HEIGHT; i ++)
	{
		for ( j = 0; j < WIDTH; j++)
		{
			while ( board[i][j] == 0)
				board[i][j] = rand()%(1+NTYPES);
		}
	}
	return;
}

int swapCandy(int board[HEIGHT][WIDTH], int i, int j, int dir)
{
	int switcher;
	switch (dir){
	case RIGHT:
		switcher = board[i][j+1];
		board[i][j+1] = board[i][j];
		board[i][j] = switcher;  
		break;
	case LEFT:
		switcher = board[i][j-1];
		board[i][j-1] = board[i][j];
		board[i][j] = switcher; 
		break;
	case UP:
		switcher = board[i-1][j];
		board[i-1][j] = board[i][j];
		board[i][j] = switcher;
		break;
	case DOWN:
		switcher = board[i+1][j];
		board[i+1][j] = board[i][j];
		board[i][j] = switcher;
		break;
	default:
		break;
	}
	
	// check filas
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH-2; j++)
		{
			if ( (board[i][j] == board[i][j+1] ) && ( board[i][j] == board[i][j+2] ) )
			return 1;
		}
	}
	// check columnas
	for (j = 0; j < WIDTH; j++)
	{
		for (i = 0; i < HEIGHT-2; i++)
		{
			if ( (board[i][j] == board[i+1][j] ) && ( board[i][j] == board[i+2][j] ) )
				return 1;
		}
	}
	return 0;
}

int candyCrush(int board[HEIGHT][WIDTH])
{
	int boardcopia[HEIGHT][WIDTH];
	int i, j, helper;
	
	// copia la tabla
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
			boardcopia[i][j] = board[i][j];
	}
	
	// check filas
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH-2; j++)
		{
			if ( (boardcopia[i][j] == boardcopia[i][j+1] ) && ( boardcopia[i][j] == boardcopia[i][j+2] ) )
			{
				helper = board[i][j];
				while (helper == boardcopia[i][j] )
				{
					board[i][j] = 0;
					j++;
				}
			}
		}
	}
	// check columnas
	for (j = 0; j < WIDTH; j++)
	{
		for (i = 0; i < HEIGHT-2; i++)
		{
			if ( (boardcopia[i][j] == boardcopia[i+1][j] ) && ( boardcopia[i][j] == boardcopia[i+2][j] ) )
			{
				helper = boardcopia[i][j];
				while (helper == boardcopia[i][j] )
				{
					board[i][j] = 0;
					i++;
				}
			}
		}
	}
	
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
			if (board[i][j] == 0)
				return 1;
	}
	return 0;
}

void slideBoard(int board[HEIGHT][WIDTH])
{
	int i, j, k;
	for ( i = HEIGHT - 1; i >= 0; i--)
	{
		for (j = 0; j < WIDTH; j++)
		{
			if (board[i][j] == 0)
				alldown(board, i, j);
		}
	}
	return;
}

void alldown(int board[HEIGHT][WIDTH], int fila, int columna)
{
	//checkea si hay algo arriba
	int i;
	for (i = fila; i > 0; i--){
		if (board[i][columna] != 0)
			break;
		}
		// si no hay nada arriba retorna
	if (i == 0 && board[0][columna] == 0)
		return;
	else{
		board[fila][columna] = board[i][columna];
		board[i][columna] = 0;
		}
	return;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}
