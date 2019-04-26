#include <stdio.h>

typedef struct Puntos_2D
{
	int x;
	int y;
} p;

void triangulo (p array[3]);
void angulos (p array[3]);

int main(void)
{
	p lado[3];
	for (int i=0; i<3; i++)
	{
		printf("ingrese el punto x del lado %d: ", i);
		scanf("%d", &lado[i].x);
		printf("ingrese el punto y del lado %d: ", i);
		scanf("%d", &lado[i].y);
	}
	triangulo(lado);
	angulos(lado);
	
	return 0;
}

void triangulo (p array[3])
{
	int uno = (array[0].x - array[1].x)*(array[0].x - array[1].x) + (array[0].y - array[1].y)*(array[0].y - array[1].y);
	printf("%d\n", uno);
	int dos = (array[1].x - array[2].x)*(array[1].x - array[2].x) + (array[1].y - array[2].y)*(array[1].y - array[2].y);
	printf("%d\n", dos);
	int tres = (array[0].x - array[2].x)*(array[0].x - array[2].x) + (array[0].y - array[2].y)*(array[0].y - array[2].y);
	printf("%d\n", tres);
	
	if (uno == dos && uno == tres && dos == tres)
		printf("Es equilatero!\n");
	else if (uno == dos || uno == tres || dos == tres)
		printf("Es isoseles!\n");
	else
		printf("Es escaleno!\n");
	return;
}

void angulos (p array[3])
{
	int uno[2] = {array[0].x - array[1].x, array[0].y - array[1].y};
	int dos[2] = {array[1].x - array[2].x, array[1].y - array[2].y};
	int tres[2] = {array[0].x - array[2].x, array[0].y - array[2].y};
	if ( (uno[0]*dos[0]+uno[1]*dos[1] == 0) || (uno[0]*tres[0]+uno[1]*tres[1] == 0) || (tres[0]*dos[0]+tres[1]*dos[1] == 0) )
		printf("Es rectangulo!\n");
	else if ( (uno[0]*dos[0]+uno[1]*dos[1] < 0) || (uno[0]*tres[0]+uno[1]*tres[1] < 0) || (tres[0]*dos[0]+tres[1]*dos[1] < 0) )
		printf("Es obtusangulo!\n");
	else
		printf("Es acutangulo!\n");
	return;
}
