#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "trie.h"

// crea una lista
ListWord_t createList (void);

// busca el nodo que contiene a prefix
Trie_node_t *buscaPrefix(Trie_node_t *p, const char *prefix);

// imprime lista
void listPrint(ListWord_t lista);

// destruye lista
void listDestroy(ListWord_t lista);
// pone un char en el ultimo caracter
void poner_char( char c[], int n); 

// funcion a implementar en el inciso a del parcial
void trieGetEnabledKeys(const Trie_t *trie, const char *prefix, int enabledKeys[ALPHABET_SIZE]);

//funcion a implementar en el inciso b del parcial
ListWord_t trieGetKeys(const Trie_t *trie, const char *prefix);
// funcion que ayuda a la funcion anterior
void getTotalKeys (Trie_node_t *node, ListWord_t lista, char palabra[]);

// copia hasta el n-esimo char de un const char
void copyString(char *to, char const *from, int n);

// copia hasta el n-esimo char de un char
void copyString_2(char *to, char *from);

// se fija si existe el nodo correspondiente a la palabra key
BOOL trieExistNode(Trie_t *pTrie, const char key[]);

// funci�n auxiliar: retorna el indice que le corresponde a un caracter dado
static int getIndexForChar(int c)
{
    int ret = toupper(c) - 'A';     //  calcula el indice pasando la letra a may�scula
    assert(ret < ALPHABET_SIZE);
    return ret;
}

// funci�n auxiliar: retorna el caracter que le corresponde a un indice dado
static int getCharForIndex(int i)
{
    assert(i >= 0 && i < ALPHABET_SIZE);
    return i + 'A';
}

// funci�n auxiliar: crea un Trie_node_t vac�o
static Trie_node_t *createNode(void)
{
    Trie_node_t *pNode;
    int i;

    pNode = (Trie_node_t *)malloc(sizeof(Trie_node_t));
    assert(pNode);

    pNode->defineKey = FALSE;

    for(i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// funci�n auxiliar: busca el nodo que termina de definir 'prefix'
// pone el nodo resultado en *pNode (NULL si el 'prefix' no existe)
static void trieSearchKey(const Trie_t *pTrie, const char prefix[], Trie_node_t **ppNode)
{
    int level;
    int length = strlen(prefix);

    *ppNode = pTrie->root;

    for( level = 0; (*ppNode) && level < length; level++ )
        (*ppNode) = (*ppNode)->children[getIndexForChar(prefix[level])];
}

// funci�n auxiliar: destruye en forma recursiva un Trie_node_t
static void trieDestroyNodes(Trie_node_t *pNode)
{
    if(pNode) {
        int i;
        for(i = 0; i < ALPHABET_SIZE; i++)
            trieDestroyNodes(pNode->children[i]);
        free(pNode);
    }
}

// funci�n auxiliar: retorna la cantidad de claves abajo del pNode (cuenta pNode si es clave)
static int trieNumKeys(Trie_node_t *pNode)
{
    int ret = 0;
    if(pNode) {
        int i;
        if(pNode->defineKey)
            ret = 1;
        for(i = 0; i < ALPHABET_SIZE; i++)
            ret += trieNumKeys(pNode->children[i]);
    }
    return ret;
}

///////////////////////////////////////////
// funciones de la interface
///////////////////////////////////////////

// crea un trie vac�o
Trie_t *trieCreate()
{
    Trie_t *nt = (Trie_t *) malloc(sizeof(Trie_t));
    assert(nt);

    nt->root = createNode();
    nt->numKeys = 0;
    return nt;
}

// destruye un trie
void trieDestroy(Trie_t *pTrie)
{
    int i;
    trieDestroyNodes(pTrie->root);
    free(pTrie);
}

// agrega una nueva clave
void trieInsertKey(Trie_t *pTrie, const char key[])
{
    int level;
    int length = strlen(key);
    int index;
    Trie_node_t *pCursor;

    pCursor = pTrie->root;

    // va recorriendo el prefix, creando nodos si es necesario
    for( level = 0; level < length; level++ ) {
        index = getIndexForChar(key[level]);
        if( !pCursor->children[index] )
            pCursor->children[index] = createNode();

        pCursor = pCursor->children[index];
    }
    // marca defineKey en el ultimo valor de pCursor si es que no estaba ya definido como clave
    if( pCursor->defineKey == FALSE) {
        pCursor->defineKey = TRUE;
        pTrie->numKeys++;   // aumento la cantidad de claves del trie
    }
}

// retorna verdadero/falso indicando si la clave ya existe en el trie
BOOL trieExistKey(Trie_t *pTrie, const char key[])
{
    Trie_node_t *keyNode;
    trieSearchKey(pTrie, key, &keyNode);
    if(keyNode && keyNode->defineKey)
        return TRUE;
    return FALSE;
}

// chequea la consistencia de un trie
BOOL trieCheck(Trie_t *pTrie)
{
    int nk = trieNumKeys(pTrie->root);
    return nk == pTrie->numKeys;
}

// retorna la cantidad de claves  que comparten un prefix
int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix)
{
    Trie_node_t *keyNode;
    trieSearchKey(pTrie, prefix, &keyNode);
    return trieNumKeys(keyNode);
}

/////////////////////////////////////////////////////////////////////////////////////
// main de prueba (faltan las funciones solicitadas)
/////////////////////////////////////////////////////////////////////////////////////
int main()
{	
    Trie_t* pTrie=trieCreate();

    FILE *stream = fopen("calles.txt", "r");
    assert(stream != NULL);

    char str[128]={0};

    while (fscanf(stream, "%s", str) == 1) {
        printf(">>%s<<\n", str);
        trieInsertKey(pTrie, str);
    }

    fclose(stream);

    printf("Chequeo: %d\n", trieCheck(pTrie));

    ListWord_t l = trieGetKeys(pTrie, "M");
    printf("\nclaves con M =====>\n");
    listPrint(l);
    listDestroy(l);

    l = trieGetKeys(pTrie, "MO");
    printf("\nclaves con MO =====>\n");
    listPrint(l);
    listDestroy(l);

    l = trieGetKeys(pTrie, "MOR");
    printf("\nclaves con MOR =====>\n");
    listPrint(l);
    listDestroy(l);

    trieDestroy(pTrie);


    return 0;
}

void trieGetEnabledKeys(const Trie_t *trie, const char *prefix, int enabledKeys[ALPHABET_SIZE])
{
	int num = strlen(prefix);
	char copia[num];
	int i = 0;
	// inicializo un nuevo puntero pero sin const para poder trabajar con la funcion trieExistKey
	Trie_t *pTrie = trie;
	
	// este loop va a ver ver si existe el nodo formado de todas las palabras formadas hasta la i-esima letra de prefix
	for (i = 0; i < num; i++)
	{
		copyString(copia, prefix, i+1);
		if (trieExistNode(pTrie, copia))
			enabledKeys[i] = 1;
		else
			break;
	}
	for (; i<num; i++)
		enabledKeys[i] = 0;
	return;
}

BOOL trieExistNode(Trie_t *pTrie, const char key[])
{
    Trie_node_t *keyNode;
    trieSearchKey(pTrie, key, &keyNode);
    if(keyNode)
        return TRUE;
    return FALSE;
}

void copyString(char *to, char const *from, int n) 
{
	for (int i = 0; i < n; i++)
		*to++ = *from++;
	to[n]='\0';
}

void copyString_2(char *to, char *from) 
{
	while( *to++ = *from++ );
	return;
}

ListWord_t trieGetKeys(const Trie_t *trie, const char *prefix)
{
	// crea el nodo que contiene la ultima letra de prefix
	Trie_node_t *prefix_node = buscaPrefix(trie->root, prefix);
	// crea una lista
	ListWord_t lista = createList();
	// crea y copia el prefix en un array para usarlo en la funcion getTotalKeys
	char palabra[MAX_KEY_LEN];
	copyString(palabra, prefix, strlen(prefix));
	// funcion que obtiene todas las keys dentro del arbol con la palabra prefix
	getTotalKeys (prefix_node, lista, palabra);
}

void getTotalKeys (Trie_node_t *node, ListWord_t lista, char palabra[])
{
	// se fija si la palabra en el nodo existente existe, y si existe la copia en la lista
	if (node->defineKey)
	{
		copyString_2 (lista->key, palabra);
		lista->pNext = createList();
		lista = lista->pNext;
	}
	
	int num = strlen(palabra);
	for (int i = 0; i< ALPHABET_SIZE; i++)
	{
		if (node->children[i] != NULL)  // como el nodo children[i] existe, entonces existen palabras ahi adentro
		{
			poner_char(palabra, i); // pone la letra correspondiente a "i" al final de la palabra
			getTotalKeys(node, lista, palabra); // se fija que otras palabras existen con esta nueva palabra
			palabra[num] = '\0'; // como no hemos entrado a los demas children, este reestablece la palabra de antes para hacer el mismo check en los demas children
		}
	}
	return;
}


Trie_node_t *buscaPrefix(Trie_node_t *p, const char *prefix)
{
	if (*prefix == 0)
		return p;
	if (p->children[prefix[0]-'a'] == NULL)
		return NULL;
	else
		return buscaPrefix(p->children[prefix[0]-'a'], prefix + 1);
}

ListWord_t createList (void)
{
	ListWord_t node = (ListWord_t) malloc(sizeof(ListWord_t));
	assert(node);
	return node;
}

void poner_char( char c[], int n)
{
	int i = 0;
	while (c[i] != '\0')
		i++;
	c[i] = getCharForIndex(n);
	return;
}

void listPrint(ListWord_t lista)
{
	if (lista == NULL)
		return;
	int num = strlen(lista->key);
	int i = 0;
	for (i = 0; i< num; i++)
		printf("%c", lista->key[i]);
	listPrint(lista->pNext);
	return;
}

void listDestroy(ListWord_t lista)
{
	if (lista == NULL)
		return;
	listDestroy(lista->pNext);
	free(lista);
	return;
}
