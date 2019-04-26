#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// representación  *******************
typedef struct
{
	int top;
	int size;
	int * pElements;
}  Stack_t ;

//  interfase *************************

// crea y retorna un nuevo  stack de capacidad ‘ size ’
Stack_t * StackCreate ( int size );
// destruye un  stack liberando  reursos asociados
void StackDestroy ( Stack_t * ps );
// agrega  el elemento ‘e’ y  retorna  true/false(falta de lugar)
int StackPush ( Stack_t * ps ,  int e );
//  remueve elemento y lo coloca en *pe, retorna true/false( vacio )
int StackPop ( Stack_t * ps ,  int *pe );
// chequea por  stack vacio , retorna true/false
int StackIsEmpty ( Stack_t * ps );

void StackFilter(Stack_t *pStk, int e);

int main (void)
{
	int i;
	Stack_t *ps = StackCreate(10);
	for (i = 0; i< 10; i++)
		StackPush(ps, i);
	StackFilter(ps, 3);
	int e;
	while(!StackIsEmpty(ps))
	{
		int r = StackPop(ps, &e);
		assert(r);
		printf("->%d\n", e);
	}
	StackDestroy(ps);
 	return 0;
}

Stack_t * StackCreate ( int size )
{
	Stack_t * ns = ( Stack_t *)  malloc ( sizeof ( Stack_t ));
	assert(ns != NULL);

	ns -> pElements = ( int *)  malloc ( size *  sizeof ( int ));
	assert ( ns -> pElements );

	ns -> size =  size ;
	ns -> top = 0;

	return ns ;
}

void StackDestroy (Stack_t*ps)
{
	free(ps->pElements);
	free(ps);
}

int StackPush ( Stack_t * ps ,  int e)
{
	if ( ps->top ==  ps->size )
		return 0;
	ps -> pElements[ps->top++] = e;
	return 1;
}

int StackPop ( Stack_t * ps ,  int *pe)
{
	if ( ps->top == 0)
		return 0;
	*pe = ps->pElements[--ps->top];
	return 1;
}

int StackIsEmpty ( Stack_t * ps )
{
	return ps->top == 0;
}

void StackFilter(Stack_t *pStk, int e)
{
	if (StackIsEmpty(pStk))
		return;
	int pe;
	StackPop(pStk, &pe);
	StackFilter(pStk, e);
	if (pe != e)
		StackPush(pStk, pe);
	return;
}
