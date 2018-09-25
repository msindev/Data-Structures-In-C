#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
typedef struct
{
  int front;
  int rear;
  char arr[SIZE][100];
}queue;

void enqueue(queue *, char[100]);
void dequeue(queue *);
void display(queue *);
int isFull(queue *);
int isEmpty(queue *);
