#include <stdio.h>

int main (void)
{
	/*
	*
	*
	Parte A del problema
	*
	*
	*/

	// declaracion de variables
	int rojo, verde, azul;

	//pedir el rojo
	do
	{
		printf("Inserte la componente roja: ");
		scanf("%d", &rojo);
	}
	while (rojo < 0 || rojo > 255);

	// pedir el verde
	do
	{
		printf("Inserte la componente verde: ");
		scanf("%d", &verde);
	}

	//pedir el azul
	while (rojo < 0 || rojo > 255);
	do
	{
		printf("Inserte la componente azul: ");
		scanf("%d", &azul);
	}

	// imprimir el color en hexadecimal
	printf("%X\n", rojo + (verde << 8) + (azul << 16));

	/*
	*
	*
	Parte B del problema
	*
	*
	*/	

	//declaracion de variable tipo hexadecimal
	unsigned int color;

	//Pedir el valor
	printf("Inncerte el valor en hexadecimal del pixel: ");
	scanf("%X", &color);
	
	// Utilizar las operaciones de bits & \ etc del practico anterior el ejercicio de Mask (el penultimo) 
	printf("Rojo: %d\tverde: %d\tazul: %d\n", color & 0xFF, (color & 0xFF00) >> 8, (color & 0xFF0000) >> 16);

	return 0;
}
