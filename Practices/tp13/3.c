#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef struct TNode{
	const char *string;
	struct TNode *pLeft;
	struct TNode *pRight;
} *Tree_t;

#define TREE_EMPTY     NULL
#define TREE_CONT(t)   ((t)->string)
#define TREE_LEFT(t)   ((t)->pLeft)
#define TREE_RIGHT(t)  ((t)->pRight)

// retorna la cantidad de nodos del árbol
int TreeNumNodes(Tree_t t);
// retorna verdadero/falso indicando si existe o no dentro de t
int TreeIsMember(const char *e, Tree_t t);
// retorna la altura
int TreeHeight(Tree_t t);
// función auxiliary para crear un árbol de un solo nodo 
Tree_t TreeCreateNode(const char *e);
// hace insersión ordenada en el árbol
Tree_t TreeInsertOrdered(const char *e, Tree_t t);
// imprime el arbol
void TreePrint(Tree_t t);
// destruye el arbol
void TreeDestroy(Tree_t t);
// imprime el arbol por nivel
void PrintArbolPorNivel(Tree_t t);
// imprime el nivel necesario
void PrintArbolNivelActual (Tree_t t, int NivelAImprimir);
//distancia entre dos nodos
int DistanciaArbol(Tree_t t, const char *A, const char *B);
// encuentra la birfurcacion entre dos nodos
int EncuentraBifurcacion(Tree_t t, const char *A, const char *B);
//profundiad de un string
int profundidad (Tree_t t, const char *e);



int main(int argc,const char *argv[])
{
	Tree_t node = TreeCreateNode(argv[0]);
	int i;
	for (i = 1; i < argc; i++)
		node = TreeInsertOrdered(argv[i], node);
	//TreePrint(node);
	PrintArbolPorNivel(node);
	printf("la distancia es de: %d\n", DistanciaArbol(node, argv[1], argv[2]));
	TreeDestroy(node);
	return 0;
}

int TreeNumNodes(Tree_t t)
{
	if(t == TREE_EMPTY)
	return 0;
	return 1 + TreeNumNodes(TREE_LEFT(t)) + TreeNumNodes(TREE_RIGHT(t));
}

int TreeIsMember(const char *e, Tree_t t)
{
	if (t==TREE_EMPTY) // arbol vacio -> no existe
		return 0;
	if (!strcmp(TREE_CONT(t) , e)) // contenido a la cabeza -> existe
		return 1;
	if (strcmp(TREE_CONT(t) , e)) // si esta, esta en el lado izquierdo
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

Tree_t TreeCreateNode(const char *e)
{
	Tree_t nT= (Tree_t) malloc(sizeof(struct TNode));
	assert(nT);
	TREE_CONT(nT) = e;
	TREE_LEFT(nT) = TREE_RIGHT(nT) = TREE_EMPTY;
	return nT;
}

Tree_t TreeInsertOrdered(const char *e, Tree_t t)
{
	if(t == TREE_EMPTY)
		return TreeCreateNode(e);
	if(strcmp(TREE_CONT(t), e) >= 0) 
		TREE_LEFT(t) = TreeInsertOrdered(e, TREE_LEFT(t));
	else
		TREE_RIGHT(t) = TreeInsertOrdered(e, TREE_RIGHT(t));
	return t;
}

void TreePrint(Tree_t t)
{
	if(t != TREE_EMPTY) {
		TreePrint(TREE_LEFT(t));
		printf("%s\n", TREE_CONT(t));
		TreePrint(TREE_RIGHT(t));
	}
}

void TreeDestroy(Tree_t t)
{
	if(t != TREE_EMPTY) {
		TreeDestroy(TREE_LEFT(t));
		TreeDestroy(TREE_RIGHT(t));
		free(t);
	}
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
		printf("%s\t", TREE_CONT(t));
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

/*
// podria hacer primero encontrar el nodo de bifurcacion entregarlo y ver la distancia entre los dos y ya
*********************************************************************************************************
*/
int DistanciaArbol(Tree_t t, const char *A, const char *B)
{
	if(IsMember(A) && IsMember(B))
	int distancia = profundidad(t, A) + profundidad(t, B) - 2*EncuentraBifurcacion( t, A, B);
	printf("Distancia A: %d y distancia B: %d y bifur: %d\n", profundidad(t, A), profundidad(t, B), EncuentraBifurcacion( t, A, B));
	return distancia;
}

int EncuentraBifurcacion(Tree_t t, const char *A, const char *B)
{
	if ( (strcmp(TREE_CONT(t), A)*strcmp(TREE_CONT(t), B) <= 0) )
		return 0;
	else if (strcmp(TREE_CONT(t), A) < 0 && TREE_LEFT(t) != NULL)
		return 1 + EncuentraBifurcacion(TREE_LEFT(t), A, B);
	else if (TREE_RIGHT(t) != NULL)
		return 1 + EncuentraBifurcacion(TREE_RIGHT(t), A, B);
}

int profundidad (Tree_t t, const char *e)
{
	if (!strcmp(TREE_CONT(t) , e)) // contenido a la cabeza -> existe
		return 0;
	else if (strcmp(TREE_CONT(t) , e) < 0 && TREE_RIGHT(t) != NULL) // si esta, esta en el lado izquierdo
		return 1 + profundidad(TREE_RIGHT(t), e);
	else if (TREE_LEFT(t) != NULL)
		return 1 + profundidad(TREE_LEFT(t), e); //si no en el derecho
	else
		return 0;
}

