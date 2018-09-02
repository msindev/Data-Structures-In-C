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
    printf("\n 1. Enqueue Element \n 2. Dequeue Element \n 3. Display Queue \n 4. Get Front \n 5. Get Rear \n 6. EXIT\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter element to be inseted : ");
        scanf("%d", &element);
        enqueue(&q, element);
        break;
      case 2:
        deleted_element = dequeue(&q);
        if(deleted_element != -1)
          printf("Dequeued Element : %d\n", deleted_element);
        break;
      case 3:
        display(&q);
        break;
      case 4:
        front_element = getFront(&q);
        if(front_element == -1)
          printf("Queue is Empty\n");
        else
          printf("Element at Front: %d\n", front_element);
        break;
      case 5:
        rear_element = getRear(&q);
        if(rear_element = -1)
          printf("Queue is Empty\n");
        else
          printf("Element at Rear: %d\n", rear_element);
        break;
      case 6:
        exit(0);
      default:
        printf("Invalid Choice.\n");
    }
  }
  return 0;
}
