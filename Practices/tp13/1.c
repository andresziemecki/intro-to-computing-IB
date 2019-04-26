#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define YES 1
#define NO 0
// representación  *******************
typedef struct Stack
{
	struct Stack * next;
	int element;
	int isFree;
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
	for (i = 0; i< 11; i++)
	{
		StackPush(ps, i);
	}
	StackFilter(ps, 3);
	int e;
	while(!StackIsEmpty(ps))
	{
		StackPop(ps, &e);
		printf("->%d\n", e);
	}
	StackDestroy(ps);
 	return 0;
}

Stack_t * StackCreate ( int size )
{
	Stack_t *crawler;

	Stack_t * ns = ( Stack_t *)  malloc ( sizeof ( Stack_t ));
	assert(ns != NULL);
	ns -> isFree = YES;

	crawler = ns;

	int i;
	for (i = 0; i < size-1; i++)
	{
		crawler -> next = ( Stack_t *)  malloc ( sizeof ( Stack_t ));
		assert ( crawler -> next );
		crawler = crawler->next;
		crawler -> isFree = YES;
	}
	crawler = NULL;
	return ns ;
}

void StackDestroy (Stack_t*ps)
{
	if (ps->next != NULL)
		StackDestroy(ps->next);
	else
		free(ps);
	return;
}

int StackPush ( Stack_t * ps ,  int e)
{
	if (ps->isFree == NO)
	{
		puts("Stack is full\n");
		return 0;
	}
	Stack_t *crawler = ps->next;
	while (crawler->isFree == YES)
	{
		ps = ps->next;
		if (crawler->next == NULL)
		{
			crawler->isFree = NO;
			crawler->element = e;
			return 1;
		}
		crawler = crawler->next;
	}
	ps->isFree = NO;
	ps->element = e;
	return 1;
}

int StackPop ( Stack_t * ps ,  int *pe)
{
	if (StackIsEmpty(ps))
	{
		puts("Stack is Empty!\n");
		return 0;
	}
	while (ps->isFree == YES)
		ps = ps->next;
	*pe = ps->element;
	ps->isFree = YES;
	return 1;
}

int StackIsEmpty ( Stack_t * ps )
{
	while (ps->next != NULL)
		ps = ps->next;
	return (ps->isFree);
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

