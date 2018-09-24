#include "QueueADT.h"

int isEmpty(queue *q)
{
  if(q->front == -1 && q->rear == -1)
  {
    return 1;
  }
  return 0;
}

int isFull(queue *q)
{
  if(q->front == 0 && q->rear == SIZE)
  {
    return 1;
  }
  return 0;
}

void enqueue(queue *q, int element)
{
  if(q->front == -1 && q->rear == -1)
  {
    q->front = q->rear = 0;
  }
  if(!isFull(q))
  {
    q->arr[(q->rear)++] = element;
  }
  else
  {
    printf("Queue Overflow\n");
  }
}

int dequeue(queue *q)
{
  if(isEmpty(q))
  {
    printf("Queue Underflow\n");
  }
  else
  {
    int element = q->arr[q->front++];
    int i;
    for(i = q->front;i<= q->rear; i++)
    {
      q->arr[i-1] = q->arr[i];
    }
    q->front = 0;
    q->rear--;
    return element;
  }
  return -1;
}

void display(queue *q)
{
  int i;
  if(isEmpty(q))
  {
    printf("Queue is Empty\n");
  }
  else
  {
    for(i = q->front; i < q->rear; i++)
    {
      printf("%d ",q->arr[i]);
    }
    printf("\n");
  }
}
