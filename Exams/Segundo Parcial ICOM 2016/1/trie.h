typedef enum { FALSE, TRUE } BOOL;

#define ALPHABET_SIZE 26
#define MAX_KEY_LEN 32

typedef struct trie_node {
    BOOL defineKey;    		                        // true/false si define o no una clave
    struct trie_node *children[ALPHABET_SIZE];      // puntero a los hijos de este prefix
} Trie_node_t;
 
typedef struct {
    Trie_node_t *root;		// contenedor real de datos
    unsigned int numKeys;	// n�mero de claves en el trie
} Trie_t;

typedef struct WordNode 
{
	char key[MAX_KEY_LEN];
	struct WordNode *pNext;
} *ListWord_t;


// funcion a implementar
void trieGetEnabledKeys(const Trie_t *trie, const char *prefix, int enabledKeys[ALPHABET_SIZE]);
ListWord_t trieGetKeys(const Trie_t *trie, const char *prefix);

// funci�n auxiliar: retorna el indice que le corresponde a un caracter dado
static int getIndexForChar(int c);

// funci�n auxiliar: retorna el caracter que le corresponde a un indice dado
static int getCharForIndex(int i);

// funci�n auxiliar: crea un Trie_node_t vac�o
static Trie_node_t *createNode(void);

// funci�n auxiliar: busca el nodo que termina de definir 'prefix'
// pone el nodo resultado en *pNode (NULL si el 'prefix' no existe)
static void trieSearchKey(const Trie_t *pTrie, const char prefix[], Trie_node_t **ppNode);

// funci�n auxiliar: destruye en forma recursiva un Trie_node_t
static void trieDestroyNodes(Trie_node_t *pNode);

// funci�n auxiliar: retorna la cantidad de claves abajo del pNode (cuenta pNode si es clave)
static int trieNumKeys(Trie_node_t *pNode);

// crea un trie vac�o
Trie_t *trieCreate();

// destruye un trie
void trieDestroy(Trie_t *pTrie);

// agrega una nueva clave
void trieInsertKey(Trie_t *pTrie, const char key[]);

// retorna verdadero/falso indicando si la clave ya existe en el trie
BOOL trieExistKey(Trie_t *pTrie, const char key[]);

// chequea la consistencia de un trie
BOOL trieCheck(Trie_t *pTrie);

// retorna la cantidad de claves  que comparten un prefix
int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix);

void listDestroy(ListWord_t list);
void listPrint(ListWord_t list);
ListWord_t insertLast(ListWord_t list, const char *cont);
ListWord_t Searcher(Trie_node_t *pNode, const char *prefix, ListWord_t lista);

