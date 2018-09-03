#include "PriorityQueueADT.h"

void penqueue(queue[5], int element, int priority)
{
	if(!isFull(&queue[priority]))
		enqueue(&queue[priority], element);
	else
		return;
}

void pdisplay(queue[5])
{
	int i;
	for(i=0;i<5;i++)
	{
		if(!isEmpty(&queue[i]))
		{
			printf("Queue %d : ");
			display(&queue[i]);
		}
		else
			printf("Queue %d is Empty\n");
	}
}

int pdequeue(queue[5])
{
	int i;
	for(i = 0;i<5;i++)
	{
		if(!isEmpty(&queue[i]))
			return dequeue(&queue[i]);
	}
	return -1;
}
