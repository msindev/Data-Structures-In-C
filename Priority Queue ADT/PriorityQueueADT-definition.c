#include "PriorityQueueADT.h"

void penqueue(queue *q, int element, int priority)
{
	if(!isFull(&q[i])
		enqueue(&q[i], element);
	else
		return;
}

void pdisplay(queue *q)
{
	int i;
	for(i=0;i<5;i++)
	{
		if(!isEmpty(q[i])
		{
			printf("Queue %d : ");
			display(q[i]);
		}
		else
			printf("Queue %d is Empty\n");
	}
}

int pdequeue(queue *q)
{
	int i;
	for(i = 0;i<5;i++)
	{
		if(!isEmpty(q[i])
			return dequeue(q[i]);
	}
	return -1;
}
		
