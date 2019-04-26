#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
	*
	*
	Se utilizara la semántica de índices directos sobre el arreglo de elementos
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
	// verifica primero si el Queue_t se encuentra lleno
	if (queue_full(queue))
		return 0;
		
	// introduce el elemento
	queue->pElements[queue->head++] = eltValue;
	
	// si llega al final de la cola, el puntero regresara al principio
	queue->head = queue->head%queue->q_size;
	return 1;
}
int queue_full(Queue_t *q)
{
	// verifica si el queue se encuentra lleno, es decir si tiene q_size - 1 elementos
	if (((abs(q->head - q->tail) + q->q_size) % q->q_size) == (q->q_size - 1))
		return 1;
	else
		return 0;
}

int QueueGet(Queue_t *queue, int *pVal)
{
	// primero verifica si la cola esta vacia
	if (QueueIsEmpty(queue))
		return 0;
	// si no esta vacia, saca el elemento de la posicion tail es decir en el final de la cola
	*pVal = queue->pElements[queue->tail++];
	// si la cola llega al final de la lista, que se actualice y se ponga en el principio
	queue->tail = queue->tail % queue->q_size;
	return 1;	
}

int QueueIsEmpty(Queue_t *queue)
{ // verifica que la lista este vacia, retorna verdadero si lo esta sino falso
	if ( (queue->head - queue->tail) == 0)
		return 1;
	else
		return 0;
}

void QueuePrint(Queue_t *queue)
{	// primero mira la cantidad de elementos de la lista y luego las imprime
	int num = QueueSize(queue), i;
	for (i = 0; i < num; i++)
		printf("%d\n", queue->pElements[(queue->head + i)%queue->q_size]);
	return;
}

// retorna la cantidad de elementos que se encuentran en la cola
int QueueSize(Queue_t *queue)
{
	return abs(queue->head - queue->tail);
}

// destruye la cola
void QueueDestroy(Queue_t *queue)
{
	// primero verifica el caso trivial que se haya creado la lista
	if (queue == NULL)
		return;
	free(queue->pElements);
	free(queue);
	return;
}
