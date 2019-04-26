#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NTYPES 10
#define HEIGHT 40
#define WIDTH 40
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

void fillBoard(int board[HEIGHT][WIDTH]);
int swapCandy(int board[HEIGHT][WIDTH], int i, int j, int dir);
int candyCrush(int board[HEIGHT][WIDTH]);
void slideBoard(int board[HEIGHT][WIDTH]);
void alldown(int board[HEIGHT][WIDTH], int fila, int columna);

int main(void)
{
	srand(time(NULL));
	return 0;
}

void fillBoard(int board[HEIGHT][WIDTH])
{
	int i, j;
	for (i = 0; i < HEIGHT; i ++)
	{
		for ( j = 0; j > WIDTH; j++)
		{
			while ( board[i][j] == 0)
				board[i][j] = rand()%NTYPES;
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
	
	int column = i;
	
	for (i = 0; i < (HEIGHT - 2); i++)
	{
		if ( board[i][column] == board[i+1][column] && board[i][column] == board[i+2][column] )
			return 1;
	}
	
	int fila = j;
	
	for (i = 0; i < (WIDTH - 2); i++)
	{
		if ( board[fila][i] == board[fila][i+1] && board[fila][i] == board[fila][i+2] )
			return 1;
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
	int i, j, k, copy;
	for (j = 0; j < WIDTH; j++)
	{
		for ( i = HEIGHT - 1; i >= 0; i--)
		{
			if (board[i][j] == 0)
				alldown(board, i, j);
		}
	}
	return;
}

void alldown(int board[HEIGHT][WIDTH], int fila, int columna)
{
	int i;
	for (i = fila; i > 0; i ++)
		board[i][columna] = board[i-1][columna];
	board[0][columna] = rand()%NTYPES;
	return;
}
