#include "CircularQueueADT.h"

int main()
{
  int choice,element,deleted_element,front_element,rear_element;
  queue q;
  q.front = q.rear = -1;
  while(1)
  {
    printf("Current Queue: ");
    display(&q);
    printf("\n Front = %d Rear = %d", q.front, q.rear);
    printf("\n 1. Enqueue Element \n 2. Dequeue Element \n 3. Display Queue \n 4. EXIT\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter element to be inserted : ");
        scanf("%d", &element);
        enqueue(&q, element);
        break;
      case 2:
        deleted_element = dequeue(&q);
        if(deleted_element != -1)
          printf("Dequeued Element : %d\n", deleted_element);
        else
          printf("Queue is Empty.\n");
        break;
      case 3:
        display(&q);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid Choice.\n");
    }
  }
  return 0;
}
