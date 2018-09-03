#ifndef InfixtoPostfix_h
#define InfixtoPostfix_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

typedef struct
{
  char arr[SIZE];
  int top;
}stack;

int isEmpty(stack *s);
int isFull(stack *s);
char peek(stack *s);
char pop(stack *s);
void push(stack *s);

int isOperand(char);
int isPrecedence(char ch);
int infixToPostfix(char*);

#endif
