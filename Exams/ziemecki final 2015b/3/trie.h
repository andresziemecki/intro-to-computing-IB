typedef enum { FALSE, TRUE } BOOL;

#define ALPHABET_SIZE 26

typedef struct trie_node {
    unsigned int numReps;    // cantidad de claves
    struct trie_node *children[ALPHABET_SIZE];
} Trie_node_t;
 
typedef struct {
    Trie_node_t *root;		// contenedor real de datos
    unsigned int numKeys;	// número de claves en el trie
} Trie_t;

// función auxiliar: retorna el indice que le corresponde a un caracter dado
static int getIndexForChar(int c);

// función auxiliar: crea un Trie_node_t vacío
static Trie_node_t *createNode(void);

// función auxiliar: busca el nodo que termina de definir 'prefix'
// pone el nodo resultado en *pNode (NULL si el 'prefix' no existe)
static void trieSearchKey(Trie_t *pTrie, const char prefix[], Trie_node_t **ppNode);

// función auxiliar: destruye en forma recursiva un Trie_node_t
static void trieDestroyNodes(Trie_node_t *pNode);

// función auxiliar: retorna la cantida de claves abajo del pNode (cuenta pNode si es clave)
static int trieNumKeys(Trie_node_t *pNode);

// crea un trie vacío
Trie_t *trieCreate();

// destruye un trie
void trieDestroy(Trie_t *pTrie);

// agrega una nueva clave
void trieInsertKey(Trie_t *pTrie, const char key[]);

// retorna true/false de acuerdo a la existencia de una clave en el trie 
BOOL trieExistKey(Trie_t *pTrie, const char key[]);

// chequea la consistencia de un trie
BOOL trieCheck(Trie_t *pTrie);

// retorna la cantidad de claves que comparten un prefix
int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix);

void takelast(char *c);
void putlast(char *c, int n);
void printarray (char *c);
static void trieprintkeys(Trie_node_t *pNode, char *c);
