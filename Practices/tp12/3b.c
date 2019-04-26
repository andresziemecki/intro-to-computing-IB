#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FULL 0
#define SUCCESSFUL 1

typedef struct {
	unsigned int head;
	unsigned int tail;
	unsigned int q_size;
	int *pElements;
	} type_queue;
	
type_queue *create_queue(int size);
void destroy_queue(type_queue *q);
int put(type_queue *q, int e);
int get(type_queue *q, int *pe);
int queue_empty(type_queue *q);
int queue_full(type_queue *q);

int main(void)
{
	type_queue *q = create_queue(4);
	if (put(q, 1))
		puts("put successful\n");
	else
		puts("problem\n");
	if (put(q, 2))
		puts("put successful\n");
	else
		puts("problem\n");
	if (put(q, 3))
		puts("put successful\n");
	else
		puts("problem\n");
	if (put(q, 4))
		puts("put successful\n");
	else
		puts("problem\n");
	int x;
	if (get(q, &x))
		puts("get successful\n");
	else
	puts("problem\n");
		if (get(q, &x))
		puts("get successful\n");
	else
	puts("problem\n");
		if (get(q, &x))
		puts("get successful\n");
	else
	puts("problem\n");
		if (get(q, &x))
		puts("get successful\n");
	else
	puts("problem\n");
	destroy_queue(q);
	return 0;
	
}

type_queue *create_queue(int size)
{
	type_queue *q = (type_queue *) malloc(sizeof(type_queue));
	assert(q);
	((*q).pElements) = (int *) malloc(size*sizeof(int));
	assert(q->pElements);
	q->q_size = size;
	q->head = 0;
	q->tail = 0;
	return q;
}	

void destroy_queue(type_queue *q)
{
	if (q == NULL)
		return;
	free(q->pElements);
	free(q);
	return;
}

int put(type_queue *q, int e)
{
	if (queue_full(q))
		return FULL;
	q->pElements[q->head++] = e;
	return SUCCESSFUL;
}

int get(type_queue *q, int *pe)
{
	if (queue_empty(q))
		return 0;
	*pe = q->pElements[q->tail++];
	return 1;
	
}

int queue_empty(type_queue *q)
{
	if ((q->head - q->tail) == 0)
		return 1;
	else
		return 0;
}

int queue_full(type_queue *q)
{
	if (	(q->head - q->tail) == q->q_size	)
		return 1;
	else
		return 0;
}
