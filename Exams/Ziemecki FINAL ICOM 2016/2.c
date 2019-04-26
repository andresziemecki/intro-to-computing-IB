#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
	*
	*
	Se utilizara la Semántica de índices directos sobre el arreglo de elementos
	*
	*
*/

#define QUEUE_SIZE 100

typedef struct {
	unsigned int head;
	unsigned int tail;
	unsigned int q_size;
	int *pElements;
	} Queue_t;
	
// Crea una cola y la retorna
Queue_t *QueueCreate();

// Inserta un nuevo elemento en la cola, retorna verdadero
// si la operación fue satisfactoria o falso si no lo fue
int QueuePut(Queue_t *queue, int eltValue);
// verifica que el queue esta lleno
int queue_full(Queue_t *q);

// Remueve un elemento de la cola, colocando su valor en
// el contenido de pVal. Retorna verdadero si la operación
// fue satisfactoria o falso si no lo fue
int QueueGet(Queue_t *queue, int *pVal);

// Retorna verdadero si la cola estávacía o falso si tiene
// algún elemento
int QueueIsEmpty(Queue_t *queue);

// Imprime los valores almacenados en la cola
void QueuePrint(Queue_t *queue);

// Retorna la cantidad de elementos en la cola
int QueueSize(Queue_t *queue);

// Destruye una cola liberando toda la memoria
void QueueDestroy(Queue_t *queue);

int main(void)
{
	return 0;
}

Queue_t *QueueCreate()
{
	Queue_t *q = (Queue_t *) malloc(sizeof(Queue_t));
	assert(q);
	((*q).pElements) = (int *) malloc(QUEUE_SIZE*sizeof(int));
	assert(q->pElements);
	q->q_size = QUEUE_SIZE;
	q->head = 0;
	q->tail = 0;
	return q;
}	

int QueuePut(Queue_t *queue, int eltValue)
{
	if (queue_full(queue))
		return 0;
	queue->pElements[queue->head++] = eltValue;
	queue->head = queue->head%queue->q_size;
	return 1;
}
int queue_full(Queue_t *q)
{
	if ((((q->head - q->tail) + q->q_size) % q->q_size) == (q->q_size - 1))
		return 1;
	else
		return 0;
}

int QueueGet(Queue_t *queue, int *pVal)
{
	if (QueueIsEmpty(queue))
		return 0;
	*pVal = queue->pElements[queue->tail++];
	queue->tail = queue->tail % queue->q_size;
	return 1;	
}

int QueueIsEmpty(Queue_t *queue)
{
	if ( abs(queue->head - queue->tail) == 0)
		return 1;
	else
		return 0;
}

void QueuePrint(Queue_t *queue)
{
	int num = QueueSize(queue), i;
	for (i = 0; i < num; i++)
		printf("%d\n", queue->pElements[(queue->head + i)%queue->q_size]);
	return;
}

int QueueSize(Queue_t *queue)
{
	return abs(queue->head - queue->tail);
}

void QueueDestroy(Queue_t *queue)
{
	if (queue == NULL)
		return;
	free(queue->pElements);
	free(queue);
	return;
}
