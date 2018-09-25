#include "MessageQueue.h"

int main()
{
  int choice;
  char message[100];
  queue q;
  q.front = q.rear = -1;
  while(1)
  {
    printf("Current Queue: ");
    display(&q);
    printf("\n Front = %d Rear = %d", q.front, q.rear);
    printf("\n 1. Enqueue message \n 2. Dequeue message \n 3. Display Queue \n 4. EXIT\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter message to be inserted : ");
        scanf("%s", message);
        enqueue(&q, message);
        break;
      case 2:
        dequeue(&q);
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
