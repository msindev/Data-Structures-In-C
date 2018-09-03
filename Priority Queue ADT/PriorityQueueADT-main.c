#include "PriorityQueueADT.h"

int main()
{
	queue q[5];
	int i,choice,element,priority,deleted_element;
	for(i=0;i<5;i++)
	{
		q[i].front = -1;
		q[i].rear = -1;
	}
	while(1)
	{
		printf("1. Enqueue \n 2. Dequeue \n 3. Display \n 4. EXIT \n ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter priority: ");
				scanf("%d", &priority);
				if(!isFull(&q[priority]))
				{
					printf("Enter element: ");
					scanf("%d", &element);
					penqueue(&q, element, priority);
				}
				else
					printf("Queue is Full\n");
				break;
			case 2:
				deleted_element = pdequeue(&q);
				if(deleted_element != -1)
					printf("Dequed Element: %d",deleted_element);
				break;
			case 3:
				pdisplay(&q);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}
