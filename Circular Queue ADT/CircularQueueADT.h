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
