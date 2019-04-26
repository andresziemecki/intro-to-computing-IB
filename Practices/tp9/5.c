#include <stdio.h>


typedef struct Persona {
	char nombre[64];
	char apellido[64];
	int dni;
} p;

void CargaPersona(p *pper);


int main(void)
{
	p persona1;
	p *direccion = &persona1;
	CargaPersona(direccion);
	printf("%s\n", direccion->nombre);
	return 0;
}

void CargaPersona(p *pper)
{
	puts("Escriba su nombre: ");
	scanf("%s", pper->nombre);
	puts("Escriba su apellido: ");
	scanf("%s", pper->apellido);
	puts("Inserte su DNI: ");
	scanf("%d", &pper->dni);
	return;
}
