#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NOMBRE_SZ    32
#define DOMICILIO_SZ 64
typedef struct {
	char nombre[NOMBRE_SZ];
	unsigned dni;
	char domicilio[DOMICILIO_SZ];
// ...
} Persona_t;

typedef struct HashEntry_str {
	unsigned dni;           // clave indexada
	int nroRegistro;        // nro de registro en la tabla maestra
	struct HashEntry_str *next;
} *HashEntry_t;

typedef struct {
	unsigned numEntries;
	HashEntry_t *entries;
} HashTable_t;

// Función que crea y retorna una tabla de hash vacía
HashTable_t *HashTableCreate(unsigned numEntries);

//Función que indexa un conjunto de personas (tabla maestra)
void HashTableFill(HashTable_t *ht, Persona_t *personas, unsigned nPers);
// mete una persona al final de la lista
HashEntry_t ListaCreate (HashEntry_t lista, Persona_t personas, unsigned int nroderegistro);

//Función que busca una persona con un determinado nro de documento.
int HashTableSearch(HashTable_t *ht, unsigned dni);
int NodeSearch(HashEntry_t node, unsigned dni);

//Función que retorna un indicador de eficiencia de búsqueda, definido como 1 dividido por la longitud media de las listas de colisiones no vacía
double HashTableAverageColisionLength(HashTable_t *ht);
// funcion que muestra la cantidad de personas en una lista
double nrodepersonas(HashEntry_t node);

void HashTableDestroy(HashTable_t *ht);
void destroyLista( HashEntry_t node);

int main(void)
{
	return 0;
}

HashTable_t *HashTableCreate(unsigned numEntries)
{
	HashTable_t *tabla_maestra = (HashTable_t *) malloc(sizeof(HashTable_t));
	assert(tabla_maestra);
	
	tabla_maestra->numEntries = numEntries;
	
	// crea la cantidad de punteros a listas igual al numero de numEntries
	tabla_maestra->entries = (HashEntry_t *) malloc(numEntries * sizeof(HashEntry_t));
	assert(tabla_maestra->entries);
	
	//inicializa cada puntero a NULL
	int i;
	for (i = 0; i < numEntries; i++)
		tabla_maestra->entries[i] = NULL;
	return tabla_maestra;
}

void HashTableFill(HashTable_t *ht, Persona_t *personas, unsigned nPers)
{
	int i;
	for ( i= 0; i < nPers; i++)
	{
		//primero verifica si la persona esta en la lista, si no esta, la mete en la lista
		if (HashTableSearch(ht, personas[i].dni) == -1)
			ht->entries[personas[i].dni%ht->numEntries] = ListaCreate(ht->entries[personas[i].dni%ht->numEntries],
																	 personas[i],
																	 personas[i].dni%ht->numEntries);
	
	}
	return;
}

HashEntry_t ListaCreate (HashEntry_t lista, Persona_t personas, unsigned nroderegistro)
{
	if (lista == NULL)
	{
		HashEntry_t lista = (HashEntry_t) malloc(sizeof(HashEntry_t));
		assert(lista);
		
		lista->dni = personas.dni;
		lista->nroRegistro = nroderegistro;//numero de entradas
		lista->next = NULL;
	}
	else
		return ListaCreate(lista->next, personas, nroderegistro);
}


int HashTableSearch(HashTable_t *ht, unsigned dni)
{
		return NodeSearch(ht->entries[dni%ht->numEntries], dni);
}

int NodeSearch(HashEntry_t node, unsigned dni)
{
	if(node == NULL)
		return -1;
	if(node->dni == dni)
		return node->nroRegistro;
	else
		return NodeSearch(node->next, dni);
}

double HashTableAverageColisionLength(HashTable_t *ht)
{
	double nrodelistasnovacias = 0, cantidadpersonas = 0;
	int i;
	for(i = 0; i < ht->numEntries; i++)
	{
		if (ht->entries[i] != NULL)
		{
			nrodelistasnovacias++;
			cantidadpersonas += nrodepersonas(ht->entries[i]); 
		}
	}
	double longitudmedia = nrodelistasnovacias/cantidadpersonas;
	return 1.0/longitudmedia; // 1 dividido la longitud media de las listas de colisiones no vacias
}

double nrodepersonas(HashEntry_t node)
{
	if (node == NULL)
		return 0;
	return 1 + nrodepersonas(node->next);
}

void HashTableDestroy(HashTable_t *ht)
{	// destruye a cada una de las listas y luego al hash
	int i;
	for(i =0 ; i < ht->numEntries; i++)
		destroyLista(ht->entries[i]);
	free(ht);
	return;
}

void destroyLista( HashEntry_t node)
{
	if ( node == NULL)
		return;
	destroyLista(node->next);
	free(node);
	return;
}
