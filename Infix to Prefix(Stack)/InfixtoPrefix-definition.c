#include "InfixtoPrefix.h"

int isEmpty(stack *s)
{
  return s->top == -1;
}

int isFull(stack *s)
{
  return s->top == SIZE - 1;
}

char peek(stack *s)
{
  return s->arr[s->top];
}

char pop(stack *s)
{
  if(!isEmpty(s))
    return s->arr[s->top--];
  return '#';
}

void push(stack *s, char op)
{
  s->arr[++s->top] = op;
}

int isOperand(char ch)
{
  return isalnum(ch);
}

int precedence(char ch)
{
  switch(ch)
  {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
  }
  return -1;
}

void infixToPrefix(char exp[])
{
  stack temp;
  temp.top = -1;
  char prefix[SIZE];
  int j=0,i;
  for(i = 0; i < strlen(exp); i++)
  {
    if(isOperand(exp[i]))
      prefix[j++] = exp[i];
    else if(exp[i] == ')')
      push(&temp, exp[i]);
    else if(exp[i] == '(')
    {
      while(!isEmpty(&temp) && peek(&temp) != ')')
          prefix[j++] = pop(&temp);
    }
    else
    {
      while(!isEmpty(&temp) && (precedence(exp[i]) <= precedence(peek(&temp))))
          prefix[j++] = pop(&temp);
      push(&temp, exp[i]);
    }
  }
  while(!isEmpty(&temp))
    if(peek(&temp) != ')')
      prefix[j++] = pop(&temp);
    else
      pop(&temp);

  prefix[j] = '\0';
  printf("Prefix Expression : %s\n",strrev(prefix));
}
