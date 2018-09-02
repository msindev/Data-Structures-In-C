#include "CircularQueueADT.h"

int isFull(queue *q)
{
  if((q->rear == SIZE -1 && q->front == 0) || q->rear == q->front - 1)
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
    if(q->rear == SIZE - 1 && q->front != 0)
    {
      q->rear = 0;
    }
    else if(q->front == -1)
    {
      q->front = q->rear = 0;
    }
    q->arr[q->rear++] = element;
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
  else
  {
    int data = q->arr[q->front];
    if(q->front == q->rear)
    {
      q->front = q->rear = -1;
    }
    else if(q->front == SIZE - 1)
    {
      q->front = 0;
    }
    else
    {
      q->front++;
    }
    return data;
  }
}

int getFront(queue *q)
{
  if(!isEmpty(q))
    return q->arr[q->front];
  return -1;
}

int getRear(queue *q)
{
  if(!isEmpty(q))
    return q->arr[q->rear];
  return -1;
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
    if(q->front > q->rear)
    {
      for(i = q->front ; i < SIZE; i++)
        printf("%d ", q->arr[i]);
      for(j = 0; j <= q->rear; j++)
        printf("%d ", q->arr[i]);
      printf("\n");
    }
    else
    {
      for(i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
      printf("\n");
    }
  }
}
