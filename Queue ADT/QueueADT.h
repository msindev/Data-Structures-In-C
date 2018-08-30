#ifndef QueueADT_h
#define QueueADT_h

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct
{
  int arr[SIZE];
  int front,top;
}queue;

void display(queue *);
void enqueue(queue *, int);
int dequeue(queue *);
int isFull(queue *);
int isEmpty(queue *);

#endif
