#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TNode{
	int cont;
	struct TNode *pLeft;
	struct TNode *pRight;
} *Tree_t;

#define TREE_EMPTY     NULL
#define TREE_CONT(t)   ((t)->cont)
#define TREE_LEFT(t)   ((t)->pLeft)
#define TREE_RIGHT(t)  ((t)->pRight)

// retorna la cantidad de nodos del árbol
int TreeNumNodes(Tree_t t);
// retorna verdadero/falso indicando si existe o no dentro de t
int TreeIsMember(int e, Tree_t t);
// retorna la altura
int TreeHeight(Tree_t t);
// función auxiliary para crear un árbol de un solo nodo 
Tree_t TreeCreateNode(int e);
// hace insersión ordenada en el árbol
Tree_t TreeInsertOrdered(int e, Tree_t t);
//Elimina un nodo
Tree_t TreeRemove(Tree_t t, int e);
// encuentra nodo
Tree_t FindNode(int e, Tree_t t);

void TreePrint(Tree_t t);
void TreeDestroy(Tree_t t);
void PrintArbolPorNivel(Tree_t t);
void PrintArbolNivelActual (Tree_t t, int NivelAImprimir);

int main(void)
{
	Tree_t t = TreeCreateNode(5);
	t = TreeInsertOrdered(3, t);
	t = TreeInsertOrdered(7, t);
	t = TreeInsertOrdered(2, t);
	t = TreeInsertOrdered(4, t);
	t = TreeInsertOrdered(6, t);
	t = TreeInsertOrdered(8, t);
	PrintArbolPorNivel(t);
	t = TreeRemove(t,8);
	puts("\n");
	PrintArbolPorNivel(t);
	TreeDestroy(t);
	return 0;
}

// retorna la cantidad de nodos del árbol
int TreeNumNodes(Tree_t t)
{
	if(t == TREE_EMPTY)
	return 0;
	return 1 + TreeNumNodes(TREE_LEFT(t)) + TreeNumNodes(TREE_RIGHT(t));
}

// retorna verdadero/falso indicando si existe o no dentro de t
int TreeIsMember(int e, Tree_t t)
{
	if (t==TREE_EMPTY) // arbol vacio -> no existe
		return 0;
	if (TREE_CONT(t) == e) // contenido a la cabeza -> existe
		return 1;
	if (TREE_CONT(t) > e) // si esta, esta en el lado izquierdo
		return TreeIsMember(e, TREE_LEFT(t));
	return TreeIsMember(e,TREE_RIGHT(t)); //si no en el derecho
}

int TreeHeight(Tree_t t)
{
	int hl, hr;
	if(t==TREE_EMPTY)
		return 0;
	hl = TreeHeight(TREE_LEFT(t));
	hr = TreeHeight(TREE_RIGHT(t));
	return 1+ ((hl > hr ) ? hl : hr);
}

// función auxiliary para crear un árbol de un solo nodo 
Tree_t TreeCreateNode(int e)
{
	Tree_t nT= (Tree_t) malloc(sizeof(struct TNode));
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
	if(t != TREE_EMPTY) {
		TreePrint(TREE_LEFT(t));
		printf("%d\n", TREE_CONT(t));
		TreePrint(TREE_RIGHT(t));
	}
}

// destruye el árbol, liberando recursos
void TreeDestroy(Tree_t t)
{
	if(t != TREE_EMPTY) {
		TreeDestroy(TREE_LEFT(t));
		TreeDestroy(TREE_RIGHT(t));
		free(t);
	}
}

Tree_t TreeRemove(Tree_t t, int e)
{
	if (!TreeIsMember(e, t))
		return NULL;
		
	t = FindNode(e, t);
	
	if (TREE_RIGHT(t) == NULL && TREE_LEFT(t) == NULL)
	{
		free(t);
		return NULL;
	}
	
	Tree_t stay = t;
	if (TREE_LEFT(t) != NULL)
	{
		t = TREE_LEFT(t);
		while(TREE_RIGHT(t) != NULL)
			t = TREE_RIGHT(t);
		stay->cont = TREE_CONT(t);
		free(t);
		return stay;
	}
	
	else if (TREE_RIGHT(t) != NULL)
	{
		t = TREE_RIGHT(t);
		while(TREE_LEFT(t) != NULL)
			t = TREE_LEFT(t);
		TREE_CONT(stay) = TREE_CONT(t);
		free(t);
		return stay;
	}
	
}

Tree_t FindNode(int e, Tree_t t)
{
	if (t==TREE_EMPTY) // arbol vacio -> no existe
		return NULL;
	if (TREE_CONT(t) == e) // contenido a la cabeza -> existe
		return t;
	if (TREE_CONT(t) > e) // si esta, esta en el lado izquierdo
		return FindNode(e, TREE_LEFT(t));
	return FindNode(e,TREE_RIGHT(t)); //si no en el derecho
}	

void PrintArbolPorNivel(Tree_t t)
{
	int NIVEL_MAX = TreeHeight(t); // nivel màximo
	int i;
	for ( i = 0; i<NIVEL_MAX; i++)
	{
		PrintArbolNivelActual(t, i);
		puts("\n");
	}
	return;
	

}
void PrintArbolNivelActual (Tree_t t, int NivelAImprimir)
{
	if (NivelAImprimir == 0)
	{
		printf("%d\t", TREE_CONT(t));
		return;
	}
	if (TREE_LEFT(t) != NULL)
	{
		PrintArbolNivelActual(TREE_LEFT(t), NivelAImprimir -1);
	}
	if (TREE_RIGHT(t) != NULL)
	{
		PrintArbolNivelActual(TREE_RIGHT(t), NivelAImprimir - 1);
	}
	return;
}
