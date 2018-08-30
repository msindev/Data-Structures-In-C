#include "QueueADT.h"

int main()
{
  int choice,element;
  queue q;
  q.front = -1;
  q.rear = -1;
  while(1)
  {
    printf("Present Queue: ");
    display(&q);
    printf("1. Enqueue \n 2. Dequeue \n 3. Display \n 4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
        if(!isFull(&q))
        {
          printf("Enter element to be inserted: ");
          scanf("%d", &element);
          enqueue(&q, element);
        }
        else
        {
          printf("Queue Overflow\n");
        }
        break;
      case 2:
        if(!isEmpty(&q))
        {
          dequeue(&q);
        }
        else
        {
          printf("Queue Underflow\n");
        }
        break;
      case 3:
        display(&q);
        break;
      case 4:
        exit(0);
      default:
        printf("%s\n", "Invalid Choice");
    }
  }
  return 0;
}
