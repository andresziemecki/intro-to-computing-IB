#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// representación  *******************
typedef struct
{
	int top;
	int size;
	int * pElements;
}  Stack_t ;

/*
enum keyword {
	{,
	[,
	(
};
*/

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

int CheckExpresion(const char *expr);

int main (void)
{
	const char string[] = "A+Y*{12+z*[sin(34+PI*(2+Y))+3]+Q}+(4*Y)";
	if (CheckExpresion(string))
		puts("It's OK!\n");
	else
		puts("Error!\n");
		
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

int CheckExpresion(const char *expr)
{
	int i = 0, j;
	char c;
	int *pe = &j;
	Stack_t *s = StackCreate( strlen(expr) );
	while( (c = expr[i]) != 0)
	{
		switch (c)
		{
			case '(':
			StackPush (s, (int)c);
			break;
			case '[':
			StackPush (s, (int)c);
			break;
			case '{':
			StackPush (s, (int)c);
			break;
			case ')':
			StackPop (s, pe);
			if ( '(' != *pe )
				return 0;
			break;
			case ']':
			StackPop (s, pe);
			if ( '[' != *pe )
				return 0;
			break;
			case '}':
			StackPop (s, pe);
			if ( '{' != *pe )
				return 0;
			break;			
		}
		i++;
	}
	if (StackIsEmpty(s))
		return 1;
	else
		return 0;
}
