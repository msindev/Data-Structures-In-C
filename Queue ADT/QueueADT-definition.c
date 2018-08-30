#include "QueueADT.h"

void isEmpty(queue *q)
{
  if(q->front == q->rear == -1)
  {
    return 1;
  }
  return 0;
}

void isFull(queue *q)
{
  if(q->front == 0 && q->rear == SIZE - 1)
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
  if(!isFUll(q))
  {
    q->arr[(q->rear)++] = element;
  }
  else
  {
    printf("Queue Overflow\n");
  }
}

void dequeue(queue *q)
{
  int element = q->arr[q->front++];
  int i;
  for(i = 0;i< q->rear; i++)
  {
    q->arr[i] = q->arr[i+1];
  }
}

void display(queue *q)
{
  int i;
  for(i = q->front; i <= q->rear; i++)
  {
    printf("%d ",q->arr[i]);
  }
  printf("\n");
}
