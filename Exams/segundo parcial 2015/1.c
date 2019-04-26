#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>


typedef enum 
{
	FALSE, TRUE 
} BOOL;

#define ALPHABET_SIZE 26

typedef struct trie_node 
{
	BOOL defineKey;    // true/false si define o no una clave
	struct trie_node *children[ALPHABET_SIZE];
} Trie_node_t;

typedef struct 
{
	Trie_node_t *root; // contenedor real de datos
	unsigned int numKeys; // número de claves en el trie
} Trie_t;

// crea un trie vacio y lo retorna
Trie_t *trieCreate();
Trie_node_t *trienodecreate();
// inserta una nueva clave si no está presenteo
// lo marca con defineKey si ya existía como prefix de otras claves
void trieInsertKey(Trie_t *pTrie, const char *key);
void trieinsertkey2(Trie_node_t *node, const char *key);
int change_char_int (const char c);

// returna verdadero/falso indicando si la clave existe.
BOOL trieExistKey(Trie_t *pTrie, const char *key);
BOOL existkey(Trie_node_t *node, const char *key);

// Chequea la consistencia entre la cantidad de nodos que dice el
// trie y la cantidad de nodos que definen key.
// Retorna TRUE/FALSE indicando si hay o nó consistencia.
BOOL trieCheck(Trie_t *pTrie);
int trienodecheck(Trie_node_t *node, int x);

// Retorna la cantidad de claves que tienen un prefix determinado.
int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix);
Trie_node_t *foo(Trie_node_t *node, const char *prefix);

// destruye un trie liberando todos los recursos alocados
void trieDestroy(Trie_t *pTrie);
void trienodedestroy(Trie_node_t *node);

int main(void)
{
	Trie_t *arbol = trieCreate();
	trieInsertKey(arbol, "amargo");
	trieInsertKey(arbol, "amar");
	trieInsertKey(arbol, "ama");
	trieInsertKey(arbol, "a");
	trieInsertKey(arbol, "azul");
	trieInsertKey(arbol, "azucena");
	trieInsertKey(arbol, "bienal");
	trieInsertKey(arbol, "bien");
	trieInsertKey(arbol, "birra");
	trieInsertKey(arbol, "parcela");
	trieInsertKey(arbol, "parcial");
	trieInsertKey(arbol, "parco");
	
	if (trieExistKey(arbol, "a"))
		puts("Si existe a");
	else
		puts("no existe \"a\"");
	
	if (trieExistKey(arbol, "amar"))
		puts("Si");
	else
		puts("no");
	
	if (trieExistKey(arbol, "am"))
		puts("Si");
	else
		puts("no");
	if (trieCheck(arbol))
		puts("todo OK");
	else
		puts("Error");
	printf("La cantidad de palabras con \"a\" son: %d\n", trieNumWordsWithPrefix(arbol, "a"));
	trieDestroy(arbol);
	return 0;
}

Trie_t *trieCreate()
{
	Trie_t *trie = (Trie_t *) malloc(sizeof(Trie_t));
	assert(trie);
	trie->numKeys = 0;
	trie->root = (Trie_node_t *) malloc(sizeof(Trie_node_t));
	assert(trie->root);
	trie->root->defineKey = FALSE;
	return trie;
}

void trieInsertKey(Trie_t *pTrie, const char *key)
{
	if (key[0] == '\0')
		return;
	else
	{
		if(trieExistKey(pTrie, key))
			return;
		else
		{
			trieinsertkey2(pTrie->root, key);
			pTrie->numKeys++;
			return;
		}	
	}
}

void trieinsertkey2(Trie_node_t *node, const char *key)
{
	if (*key == '\0')
		node->defineKey = TRUE;
	else
		{
			int numkey = change_char_int(*key);
			if (node->children[numkey] == NULL)
				node->children[numkey] = trienodecreate();
			trieinsertkey2(node->children[numkey], key+1);
		}
	return;
}

Trie_node_t *trienodecreate()
{
	Trie_node_t *node = (Trie_node_t *) malloc(sizeof (Trie_node_t));
	assert(node);
	node->defineKey = FALSE;
	int i;
	for (i = 0; i < ALPHABET_SIZE; i++)
		node->children[i] = NULL;
	return node;
}

int change_char_int (const char c)
{
	char a = c;
	a = tolower(a);
	return (int)a - 97;
}

BOOL trieExistKey(Trie_t *pTrie, const char *key)
{
	return existkey(pTrie->root, key);
}

BOOL existkey(Trie_node_t *node, const char *key)
{
	if (node == NULL)
		return FALSE;
	if (*key == '\0')
		return node->defineKey;
	existkey(node->children[change_char_int(*key)], key+1);
}

BOOL trieCheck(Trie_t *pTrie)
{
	if (trienodecheck(pTrie->root, 0) == pTrie->numKeys)
		return TRUE;
	else
		return FALSE;	
}

int trienodecheck(Trie_node_t *node, int x)
{
	if (node == NULL)
		return 0;
	if (node->defineKey)
		x++;
	int i;
	for (i = 0; i < ALPHABET_SIZE; i++)
		x += trienodecheck(node->children[i], 0);
	return x;
}

int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix)
{
	if (!trieExistKey(pTrie, prefix))
		return 0;
	else
		return trienodecheck(foo(pTrie->root, prefix), 0);
}

Trie_node_t *foo(Trie_node_t *node, const char *prefix)
{
	if (*prefix == '\0')
		return node;
	else
		return foo(node->children[change_char_int(*prefix)], prefix+1);
}

void trieDestroy(Trie_t *pTrie)
{
	trienodedestroy(pTrie->root);
	free (pTrie);
	return;
}
void trienodedestroy(Trie_node_t *node)
{
	if (node == NULL)
		return;
	int i;
	for (i = 0; i < ALPHABET_SIZE; i++)
		trienodedestroy(node->children[i]);
	free(node);
	return;
}
