#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "trie.h"

#define MAX_SIZE 10 
int main(void)
{
	FILE* f = fopen("libro.txt", "r");
	if (f == NULL)
		return 1;
	char palabra[MAX_SIZE];
	Trie_t *arbol = trieCreate();
	
	int i = 0;
	while(fscanf(f, "%s", palabra) != EOF)
	{
		trieInsertKey(arbol, palabra);
		printf("%d\n", i);
		i++;
	}
	palabra[0]='\0';
	palabra[1]='\0';
	trieprintkeys(arbol->root->children[0], palabra); 
	
	return 0;
}

void printarray (char *c)
{
	while (*c != '\0'){
		printf("%c", *c);
		c++;}
	return;
}

void putlast(char *c, int n)
{
	while(*c != '\0')
	c++;
	*c = (char)(n+97);
	*(c+1)='\0';
	return;
}

void takelast(char *c)
{
	while(*c != '\0')
	c++;
	*(c-1) = '\0';
	return;
}

static void trieprintkeys(Trie_node_t *pNode, char *c)
{
    if(pNode) 
    {
        int i;
        if(pNode->numReps)
        {
        	printf("La cantidad de: ");
            printarray(c);
            printf(" es de %d\n", pNode->numReps);
         }
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
        	putlast(c, i);
            trieprintkeys(pNode->children[i], c);
            takelast(c);
        }
    }
    return;
}

// función auxiliar: retorna el indice que le corresponde a un caracter dado
static int getIndexForChar(int c)
{
    int ret = toupper(c) - 'A';     //  calcula el indice pasando la letra a mayúscula
    assert(ret < ALPHABET_SIZE);
    return ret;
}

// función auxiliar: crea un Trie_node_t vacío
static Trie_node_t *createNode(void)
{
    Trie_node_t *pNode;
    int i;
 
    pNode = (Trie_node_t *)malloc(sizeof(Trie_node_t));
    assert(pNode);

    pNode->numReps = 0;

    for(i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

// función auxiliar: busca el nodo que termina de definir 'prefix'
// pone el nodo resultado en *pNode (NULL si el 'prefix' no existe)
static void trieSearchKey(Trie_t *pTrie, const char prefix[], Trie_node_t **ppNode)
{
    int level;
    int length = strlen(prefix);

    *ppNode = pTrie->root;
 
    for( level = 0; (*ppNode) && level < length; level++ ) 
        (*ppNode) = (*ppNode)->children[getIndexForChar(prefix[level])];
}

// función auxiliar: destruye en forma recursiva un Trie_node_t
static void trieDestroyNodes(Trie_node_t *pNode)
{
    if(pNode) {
        int i;
        for(i = 0; i < ALPHABET_SIZE; i++)
            trieDestroyNodes(pNode->children[i]);
        free(pNode);
    }
}

// función auxiliar: retorna la cantida de claves abajo del pNode (cuenta pNode si es clave)
static int trieNumKeys(Trie_node_t *pNode)
{
    int ret = 0;
    if(pNode) {
        int i;
        if(pNode->numReps)
            ret = pNode->numReps;
        for(i = 0; i < ALPHABET_SIZE; i++)
            ret += trieNumKeys(pNode->children[i]);
    }
    return ret;
}

///////////////////////////////////////////
// funciones pedidas
///////////////////////////////////////////

// crea un trie vacío
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
 
    pTrie->numKeys++;
    pCursor = pTrie->root;
 
    for( level = 0; level < length; level++ ) {
        index = getIndexForChar(key[level]);
        if( !pCursor->children[index] )
            pCursor->children[index] = createNode();
 
        pCursor = pCursor->children[index];
    }
    // marca dnumReps en el ultimo valor de pCursor (haya sido creado ahora o ya existia)
    pCursor->numReps++;
}

// retorna true/false de acuerdo a la existencia de una clave en el trie 
BOOL trieExistKey(Trie_t *pTrie, const char key[])
{
    Trie_node_t *keyNode;
    trieSearchKey(pTrie, key, &keyNode);
    if(keyNode && keyNode->numReps > 0)
        return TRUE;
    return FALSE;
}

// chequea la consistencia de un trie
BOOL trieCheck(Trie_t *pTrie)
{
    int nk = trieNumKeys(pTrie->root);
    return nk == pTrie->numKeys;
}

// retorna la cantidad de claves que comparten un prefix
int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix)
{
    Trie_node_t *keyNode;
    trieSearchKey(pTrie, prefix, &keyNode);
    return trieNumKeys(keyNode);
}



