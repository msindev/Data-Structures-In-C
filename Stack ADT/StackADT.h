#include <stdio.h>
#include <stdlib.h>

#ifndef "StackADT_h"
#define "StackADT_h"

#define SIZE 5

struct
{
  int arr[SIZE];
  int top;
}stack;

void push(stack * , int);
int pop(stack *);
void display(stack *);
int topElement(stack *);

#endif
