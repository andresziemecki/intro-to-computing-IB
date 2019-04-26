#include <stdio.h>

typedef struct 
{
	unsigned char R, G, B;
} RGB;

int compositeColor(RGB color);

RGB decompositeColor(int compColor);

int main(void)

{

	RGB color;
	scanf("%hhu", &(color.R));
	scanf("%hhu", &(color.G));
	scanf("%hhu", &(color.B));
	printf("%X\n", compositeColor(color));
	color = decompositeColor(compositeColor(color));
	printf("rojo: %hhu\t verde: %hhu\t azul: %hhu\t\n", color.R, color.G, color.B); 
return 0;


}

int compositeColor(RGB color)
{
	int total = color.R + (color.G << 8) + (color.B << 16);
	return total;
}

RGB decompositeColor(int compColor)
{
	RGB intensidad;
	intensidad.R = compColor & 0xFF;
	intensidad.G = (compColor & 0xFF00) >> 8;
	intensidad.B = (compColor & 0xFF0000) >> 16;
	return intensidad;
}
