#ifndef InfixtoPrefix_h
#define InfixtoPrefix_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
void push(stack *s, char);

int isOperand(char);
int precedence(char ch);
void infixToPrefix(char[]);

#endif
