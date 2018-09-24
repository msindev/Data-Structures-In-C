#include "CircularQueueADT.h"

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

void enqueue(queue *q, int element)
{
  if(!isFull(q))
  {
    if(q->front == -1)
    {
      q->front = q->rear = 0;
      q->arr[q->rear] = element;
    }
    else if(q->rear == SIZE - 1 && q->front != 0)
    {
      q->rear = 0;
      q->arr[q->rear] = element;
    }
    else
    {
      q->rear++;
      q->arr[q->rear] = element;
    }
  }
  else
  {
    printf("Queue Overflow.\n");
  }
}

int dequeue(queue *q)
{
  if(q->front == -1)
  {
    printf("Queue Underflow\n");
    return -1;
  }
    int data = q->arr[q->front];
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
    return data;
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
        printf("%d ",q->arr[i]);
    }
    else
    {
      for (i = q->front; i < SIZE; i++)
            printf("%d ", q->arr[i]);

        for (i = 0; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
    }
  }
}
