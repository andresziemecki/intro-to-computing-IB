#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "trie.h"

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


void trieGetEnabledKeys(const Trie_t *trie, const char *prefix, int enabledKeys[ALPHABET_SIZE])
{
	Trie_node_t **pNode;
	trieSearchKey(trie, prefix, pNode);
	assert(pNode);
	int i;
	for (int i = 0; i< ALPHABET_SIZE; i++)
	{
		if ((*pNode)->children[i])
			enabledKeys[i] = 1;
		 else
		 	enabledKeys[i] = 0;
	}
	return;
}

ListWord_t trieGetKeys(const Trie_t *trie, const char *prefix)
{
    Trie_node_t *keyNode;
    int i;

    trieSearchKey(trie, prefix, &keyNode);
    if(keyNode == NULL)
        return NULL;

    return Searcher(keyNode, prefix, NULL);
}

ListWord_t Searcher(Trie_node_t *pNode, const char *prefix, ListWord_t lista)
{
	if (pNode->defineKey)
		lista = insertLast(lista, prefix);
	int i;
	for (i =0; i< ALPHABET_SIZE; i++)
	{
		if (pNode->children[i])
		{
			char newPrefix[MAX_KEY_LEN];
			strcpy(newPrefix, prefix);
			
			int len = strlen(prefix);
			newPrefix[len] = getCharForIndex(i);
            newPrefix[len+1] = 0;
            
            lista = Searcher(pNode->children[i], newPrefix, lista);
		}
	}
	return lista;
}


ListWord_t insertLast(ListWord_t list, const char *cont)
{
    if(list == NULL) {
        list = (ListWord_t) malloc(sizeof(struct WordNode ));
        assert(list);
        strcpy(list->key, cont);
        list->pNext = NULL;
        return list;
    }
    list->pNext = insertLast(list->pNext, cont);
    return list;
}

void listPrint(ListWord_t list)
{
    while(list) {
        printf("%s\n", list->key);
        list = list->pNext;
    }
}

void listDestroy(ListWord_t list)
{
    while(list) {
        ListWord_t toDelete = list;
        list = list->pNext;
        free(toDelete);
    }
}

