#include "MessageQueue.h"

int isFull(queue *q)
{
  if((q->rear == SIZE - 1 && q->front == 0) || (q->rear == q->front - 1))
  {
    return 1;
  }
  return 0;
}

int isEmpty(queue *q)
{
  if(q->front == -1)
  {
    return 1;
  }
  return 0;
}

void enqueue(queue *q, char message[100])
{
  if(!isFull(q))
  {
    if(q->front == -1)
    {
      q->front = q->rear = 0;
      strcpy(q->arr[q->rear],message);
    }
    else if(q->rear == SIZE - 1 && q->front != 0)
    {
      q->rear = 0;
      strcpy(q->arr[q->rear],message);
    }
    else
    {
      q->rear++;
      strcpy(q->arr[q->rear],message);
    }
  }
  else
  {
    printf("Queue Overflow.\n");
  }
}

void dequeue(queue *q)
{
  if(q->front == -1)
  {
    printf("Queue Underflow\n");
    return;
  }
    char data[100];
    strcpy(data,q->arr[q->front]);
    if(q->front == q->rear)
    {
      q->front = -1;
      q->rear = -1;
    }
    else if(q->front == SIZE - 1 )
    {
      q->front = 0;
    }
    else
    {
      q->front++;
    }
    printf("Dequeued String: %s\n",data);
}

void display(queue *q)
{
  int i,j;
  if(isEmpty(q))
  {
    printf("Queue is Empty\n");
  }
  else
  {
    if(q->rear >= q->front)
    {
      for(i = q->front; i <= q->rear; i++)
        printf("%s\n",q->arr[i]);
    }
    else
    {
      for (i = q->front; i < SIZE; i++)
            printf("%s\n", q->arr[i]);

        for (i = 0; i <= q->rear; i++)
            printf("%s\n", q->arr[i]);
    }
  }
}
