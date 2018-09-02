#ifndef CircularQueueADT_h
#define CircularQueueADT_h

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
int dequeue(queue *);
void display(queue *);
int isFull(queue *);
int isEmpty(queue *);

#endif
