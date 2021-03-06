#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define D 2
#define NUM_PASOS 1000000
#define IZQUIERDA 0
#define ARRIBA 1
#define DERECHA 2
#define ABAJO 3
#define QUIETO 4
#define LEFT_UP 5
#define	RIGHT_UP 6
#define LEFT_DOWN 7
#define	RIGHT_DOWN 8
#define PASOS_INTERMEDIOS 100000 

typedef struct {
int x, y;
} Pos_t;
 
int main() {
Pos_t pos = { 0, 0 };
int contador;
srand(5); 

for(contador = 0; contador < NUM_PASOS; contador++) {
	switch(rand() % 9) {    
		case IZQUIERDA:
			pos.x -= D;
			break;
		case DERECHA:
			pos.x += D;
			break;
		case ARRIBA:
			pos.y += D;
			break;
		case ABAJO:
			pos.y -= D;
			break;
		case LEFT_UP:
			pos.x -= D;
			pos.y += D;
			break;
		case RIGHT_UP:
			pos.x += D;
			pos.y += D;
			break;
		case LEFT_DOWN:
			pos.x -= D;
			pos.y -= D;
			break;
		case RIGHT_DOWN:
			pos.x += D;
			pos.y -= D;
			break; 
		}
}
printf("PosX: %d, PosY: %d\nDistancia: %lf\n", pos.x, pos.y, sqrt(pos.x*pos.x+ pos.y*pos.y));
return 0;
}
