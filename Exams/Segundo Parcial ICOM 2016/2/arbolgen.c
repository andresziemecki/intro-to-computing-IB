#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "arbolgen.h"
#include "lista.h"

// Extrae los datos genealogicos de una persona del
// string line y los usa para crear una Persona_t
Persona_t * CreaPersona(char * line,	char * parentesco)
{
    Persona_t * pers = (Persona_t*)malloc(sizeof(Persona_t));

    // extrae el parentesco, dni y nombre
    sscanf(line, "%s %d %s", parentesco, &pers->dni, pers->nombre);

    return pers;
}

// Crea el arbol genealogico completo de una persona
// a partir de los datos contenidos en el archivo
// una persona por linea, con el formato siguiente
// Ejemplo: E.P.P.M.P 8701739 Ireneo
ArbolGen_t CreaArbolGen(char * filename)
{
    ArbolGen_t arb=NULL;
    ArbolGen_t aux=NULL;
    FILE *stream;
    char *c;
	char parentesco[MAX_PARENTESCO];
	int dni;
	char nombre[MAX_NOMBRE];
    int ret;
    // abro el archivo
    stream = fopen(filename, "r");
    assert(stream);

    if (stream == NULL)
       return NULL;

    // leo de a una linea
    while ((ret = fscanf(stream, "%s %d %s", parentesco, &dni, nombre)) != EOF)
    {
        if(ret != 3)
        {
            puts("Fallo en el parseo");
            exit(1);
        }

        //Busco su ubicacion en el arbol genealogico
        // usando la info de parentesco
        for(c=parentesco; *c!=0; c++)
        {
            switch(*c)
            {
 				case 'E':
 				    if(arb==NULL)
                        arb = CreaNodoArbolGen();
                    aux = arb;
					break;
				case 'P':
					if (aux->padre==NULL)
						aux->padre = CreaNodoArbolGen();
					aux=aux->padre;
					break;
				case 'M':
					if (aux->madre==NULL)
						aux->madre = CreaNodoArbolGen();
					aux=aux->madre;
					break;
            }
        }
        setDatosPersona(aux,dni,nombre);
    }

    fclose(stream);
    return arb;
}

// Alloca un struct ArbolGen_s
ArbolGen_t CreaNodoArbolGen()
{
    ArbolGen_t p = (ArbolGen_t)malloc(sizeof(struct ArbolGen_s));
    assert(p);
    p->padre = NULL;
    p->madre = NULL;
    p->pers = (Persona_t*)malloc(sizeof(Persona_t));
    assert(p->pers);

    return p;
}

// Pone los datos de la persona en el nodo apuntado por ar
void setDatosPersona(ArbolGen_t ar, int dni, char * nombre)
{
    ar->pers->dni = dni;
    strcpy(ar->pers->nombre,nombre);
}

// Destruye un arbol genealogico
void DestruyeArbolGen(ArbolGen_t a)
{
    if(a==NULL)
        return;
    DestruyeArbolGen(a->padre);
    DestruyeArbolGen(a->madre);

    free(a->pers);
    free(a);
}

void ImprimeArbol(ArbolGen_t ar)
{
    if (ar==NULL)
        return;
    printf("%d %s\n",ar->pers->dni,ar->pers->nombre);
    ImprimeArbol(ar->padre);
    ImprimeArbol(ar->madre);
}

int BuscaPersona(ArbolGen_t a, int dni)
{
	if (a == NULL) 
		return 0;
	if (a->pers->dni == dni))
		return 1;
	if (BuscaPersona(a->padre, dni))
		return 1
	else
		return BuscaPersona(a->madre, dni);
}

int NivelPersona(ArbolGen_t a, int dni, int * nivel)
{
	if (!BuscaPersona(a, dni))
		return 0;
	else
		*nivel = Nivel(a, dni);
	return 1;
}

int Nivel(ArbolGen_t a, int dni)
{
	if (a->pers->dni == dni))
		return 0;
	if (BuscaPersona(a->madre, dni))
		return 1 + Nivel(a->madre, dni);
	else
		return 1 + Nivel(a->padre, dni);
}

List_t ListaAncestrosComunes(ArbolGen_t a, ArbolGen_t b, List_t lac)
{
	if (a == NULL)
		return lac;
	List_t crawler;
	crawler = lac;
	if (BuscaPersona(b, a->pers->dni))
	{
		if (lac == NULL)
			List_t lista = ListNodeCreate();
		lac->cont = a->pers->dni;
		lac = lac->pNext;
	}
	lac = ListaAncestrosComunes(a->padre, b, lac);
	while (lac != NULL)
		lac = lac->pNext;
	lac = ListaAncestrosComunes(a->madre, b, lac);
	return crawler;
}

double CoefRelacion(ArbolGen_t a, ArbolGen_t b)
{
	List_t lista = ListaAncestrosComunes(a, b)
	int num_ances = ListNumNodes(lista);
	int i;
	double grado = 0.5;
	for (i = 1, i < num_ances; i++)
		grado = grado + potencia(grado, i+1);
	return grado;
}

double potencia (double n, int p)
{
	int i;
	for ( i = 1; i < p; i++)
		n *= n;
	return n;
}

