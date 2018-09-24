#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
typedef struct
{
  int front;
  int rear;
  int arr[SIZE];
}queue;

void enqueue(queue *, int);
char* dequeue(queue *);
void display(queue *);
int isFull(queue *);
int isEmpty(queue *);

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
