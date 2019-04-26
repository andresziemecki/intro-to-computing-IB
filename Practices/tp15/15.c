#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef enum {FALSE, TRUE } BOOL;

#define ALPHABET_SIZE 26

typedef struct trie_node {
	BOOL defineKey;    // true/false si define o no una clave
	struct trie_node *children[ALPHABET_SIZE];
} Trie_node_t;

typedef struct {
	Trie_node_t *root; // contenedor real de datos
	unsigned int numKeys; // número de claves en el trie
} Trie_t;

// crea un trie vacio y lo retorna
Trie_t *trieCreate();


// inserta una nueva clave si no está presente o
// lo marca con defineKey si ya existía como prefix de otras claves
void trieInsertKey(Trie_t *pTrie, const char *key);

void trieInsertNode(Trie_node_t *node, const char *key);
Trie_node_t *nodeCreate();
// retorna verdadero/falso indicando si la clave existe.
BOOL trieExistKey(Trie_t *pTrie, const char *key);
BOOL searcher ( Trie_node_t *s, const char *key);

// Chequea la consistencia entre la cantidad de nodos que dice el
// trie y la cantidad de nodos que definen key.
// Retorna TRUE/FALSE indicando si hay o nó consistencia.
BOOL trieCheck(Trie_t *pTrie);
int Checker(Trie_node_t *c);

// Retorna la cantidad de claves que tienen un prefix determinado.
int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix);
Trie_node_t *buscaPrefix(Trie_node_t *p, const char *prefix);


// destruye un trie liberando todos los recursos alocados
void trieDestroy(Trie_t *pTrie);
void DestroyNode(Trie_node_t *node);

int main(void)
{
	Trie_t *RAIZ = trieCreate();
	trieInsertKey(RAIZ, "a");
	trieInsertKey(RAIZ, "ama");
	trieInsertKey(RAIZ, "amargo");
	trieInsertKey(RAIZ, "amar");
	trieInsertKey(RAIZ, "azul");
	trieInsertKey(RAIZ, "azucana");
	trieInsertKey(RAIZ, "bien");
	trieInsertKey(RAIZ, "bienal");
	trieInsertKey(RAIZ, "birra");
	trieInsertKey(RAIZ, "parco");
	trieInsertKey(RAIZ, "parcial");
	trieInsertKey(RAIZ, "parcela");
	if (trieExistKey(RAIZ, "ab"))
		puts("existe");
	else
		puts("no existe");

	if (trieCheck(RAIZ))
		puts("Ok!");
	else
		puts("Problem!");
	printf("la cantidad de claves despues de ama es de: %d\n", trieNumWordsWithPrefix(RAIZ, "ama"));
	trieDestroy(RAIZ);
	return 0;
}

Trie_t *trieCreate()
{
	Trie_t *raiz = (Trie_t *) malloc(sizeof(Trie_t));
	assert(raiz);
	raiz->numKeys = 0;
	raiz->root = (Trie_node_t *) malloc(sizeof(Trie_node_t));
	assert(raiz->root);
	raiz->root->defineKey = FALSE;
	for (int i = 0; i< ALPHABET_SIZE; i++)
		raiz->root->children[i] = NULL;
	return raiz;
}

void trieInsertKey(Trie_t *pTrie, const char *key)
{
	if (trieExistKey(pTrie, key))
		return;
	else
	{
		pTrie->numKeys++;
		trieInsertNode(pTrie->root, key);
		return;
	}
}

void trieInsertNode(Trie_node_t *node, const char *key)
{
	if (*key == 0)
	{
		node->defineKey = TRUE;
		return;
	}
	if (node->children[key[0]-'a'] == NULL)
		node->children[key[0]-'a'] = nodeCreate();
	trieInsertNode(node->children[key[0]-'a'], key+1);
	return;
}

Trie_node_t *nodeCreate()
{
		Trie_node_t *node =  (Trie_node_t *) malloc(sizeof (Trie_node_t));
		assert(node);
		node->defineKey=FALSE;
		for (int i = 0; i< ALPHABET_SIZE; i++)
			node->children[i] = NULL;
		return node;
}

BOOL trieExistKey(Trie_t *pTrie, const char *key)
{
	return searcher(pTrie->root, key);
}

BOOL searcher ( Trie_node_t *s, const char *key)
{
	if (*key == 0)
		return s->defineKey;
	if (s->children[key[0]-'a'] == NULL)
		return FALSE;
	else
		return searcher(s->children[key[0]-'a'], key + 1);
}

BOOL trieCheck(Trie_t *pTrie)
{
		printf("numKeys: %d \t Checker: %d\n",pTrie->numKeys , Checker(pTrie->root));
	if (pTrie->numKeys == Checker(pTrie->root))
		return TRUE;
	else
		return FALSE;
}

int Checker(Trie_node_t *c)
{
	if (c == NULL)
		return 0;
	int i, suma = 0;
	if (c->defineKey)
		suma++;
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		suma = suma + Checker(c->children[i]);
	}
	return suma;
}

int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix)
{
	Trie_node_t *node = buscaPrefix(pTrie->root, prefix);
	if (node == NULL)
		return 0;
	else
		return Checker(node);
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

void trieDestroy(Trie_t *pTrie)
{
	if (pTrie == NULL)
		return;
	DestroyNode(pTrie->root);
	free (pTrie);
	return;
}

void DestroyNode(Trie_node_t *node)
{
	if (node == NULL)
		return;
	int i;
	for (i = 0; i< ALPHABET_SIZE; i++)
			DestroyNode(node->children[i]);
	free(node);
	return;
}
