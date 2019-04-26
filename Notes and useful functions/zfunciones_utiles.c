// copia un String
void copyString(char *to, char *from) 
{
	while( *to++ = *from++ );
}

// aloca una matriz de 2x2, en el tp 11-ejercicio-2y3 hay muchas mas funciones de matrices
int ** allocaMatriz(int nfil, int ncol) 
{
	int i, **pmat;
	// pmat apunta a un arreglo de nfil punteros
	pmat = (int **) malloc(nfil * sizeof(int*));
	if( pmat == NULL )
		return NULL; 
	// cada elemento de pmat apunta a un arreglo de ncol enteros
	for( i=0; i<nf; i++)
	{
		pmat[i]=(int *) malloc(ncol * sizeof(int));
		if( pmat[i] == NULL )
		{
			liberaMatriz(pmat,i);
			return null;
		}
	}
	return pmat;
}
// libera una matriz de 2x2
void liberaMatriz(int ** pmat, int nfil) 
{
	int i;
	// primero debo liberar los elementos de pmat
	for( i=0; i<nfil; i++)
		free(pmat[i]);
	// y finalmente libero pmat
	free(pmat);
	return;
}

// En la pràctica 11-ejercicio-4 estan todas las funciones de un polinomio
*************************************************************************

// implementacion de Stack, tambien esta en la Practica 12-ejercicio-1
**********************************************************************

/* implementacion de Queue - TP 12 - ejercicio 3
	->a) Semántica de índices directos sobre el arreglo de elementos.
	->b) Semántica de contadores de put y get de elementos.
*/

***************************************************************************************
//Implementacion de Listas, màs funciones en el TP 13
typedef struct Node {
	int cont;
	struct Node *pNext;
	} *List_t; // List_t es sinomimo de puntero a struct Node
#define LIST_EMPTY NULL
#define LIST_CONT(lst) ((lst)->cont)
#define LIST_TAIL(lst) ((lst)->pNext)
int ListNumNodes(List_t lst)
{
	if(lst == LIST_EMPTY) // == if(lst == NULL)
		return 0;
	return 1 + ListNumNodes(LIST_TAIL(lst)); // == return 1 + ListNumNodes(lst->pNext);
}
int ListIsMember(int e, List_t lst)
{
	if(lst == LIST_EMPTY) // == if(lst == NULL)
		return 0;
	if(LIST_CONT(lst) == e) // == if(lst->cont == e)
		return 1;
	return ListIsMember(e, LIST_TAIL(lst)); // == return ListIsMember(e, lst->pNext);
}
static List_t __ListNodeCreate(int e, List_t tail)
{
	List_t newL = (List_t ) malloc(sizeof(struct Node));
	assert(newL);
	LIST_CONT(newL) = e;
	LIST_TAIL(newL) = tail;
	return newL;
}
List_t ListInsert(List_t lst, int e)
{
	if(lst == LIST_EMPTY|| e <= LIST_CONT(lst) )
		return __ListNodeCreate(e, lst);
	LIST_TAIL(lst) = ListInsert(LIST_TAIL(lst), e);
	return lst;
}

***************************************************************************************
// Implementacion de Arboles binarios, TP-13-Ejercicios - 3 y 4 , el TP 14 tambien es binary trie. el TP 15 ya es multi trie.
typedef struct TNode {
	int cont;
	struct TNode *pLeft;
	struct TNode *pRight;
} *Tree_t;
#define TREE_EMPTY NULL
#define TREE_CONT(t) ((t)->cont)
#define TREE_LEFT(t) ((t)->pLeft)
#define TREE_RIGHT(t) ((t)->pRight)

// retorna la cantidad de nodos del árbol
int TreeNumNodes(Tree_t t)
{
	if(t == TREE_EMPTY)
		return 0;
	return 1 + TreeNumNodes(TREE_LEFT(t)) + TreeNumNodes(TREE_RIGHT(t));
}
// retorna verdadero/falso indicando si e existe o nó dentro de t
int TreeIsMember(int e, Tree_t t)
{
	if(t == TREE_EMPTY) // árbol vacío -> no existe
		return 0;
	if(TREE_CONT(t) == e) // contenido a la cabeza -> existe
		return 1;
	if( TREE_CONT(t) > e) // si está, esta en el lado izquierdo
		return TreeIsMember(e, TREE_LEFT(t));
	return TreeIsMember(e, TREE_RIGHT(t)); // si no en el derecho
}
// altura del arbol
int TreeHeight(Tree_t t)
{
	int hl, hr;
	if(t == TREE_EMPTY)
		return 0;
	hl = TreeHeight(TREE_LEFT(t));
	hr = TreeHeight(TREE_RIGHT(t));
	return 1 + ((hl > hr) ? hl : hr);
}
// función auxiliary para crear un árbol de un solo nodo
Tree_t TreeCreateNode(int e)
{
	Tree_t nT = (Tree_t) malloc(sizeof(struct TNode));
	assert(nT);
	TREE_CONT(nT) = e;
	TREE_LEFT(nT) = TREE_RIGHT(nT) = TREE_EMPTY;
	return nT;
}
// hace insersión ordenada en el árbol
Tree_t TreeInsertOrdered(int e, Tree_t t)
{
	if(t == TREE_EMPTY)
		return TreeCreateNode(e);
	if(TREE_CONT(t) >= e)
		TREE_LEFT(t) = TreeInsertOrdered(e, TREE_LEFT(t));
	else
		TREE_RIGHT(t) = TreeInsertOrdered(e, TREE_RIGHT(t));
	return t;
}
// Imprime el contenido del árbon en forma ordenada
void TreePrint(Tree_t t)
{
	if(t != TREE_EMPTY) 
	{
		TreePrint(TREE_LEFT(t));
		printf("%d\n", TREE_CONT(t));
		TreePrint(TREE_RIGHT(t));
	}
}
// destruye el árbol, liberando recursos
void TreeDestroy(Tree_t t)
{
	if(t != TREE_EMPTY) 
	{
		TreeDestroy(TREE_LEFT(t));
		TreeDestroy(TREE_RIGHT(t));
		free(t);
	}
}
