#include "InfixtoPostfix.h"

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
  return '$'
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

void infixToPostfix(char exp[])
{
  stack temp;
  char postfix[50];
  int j=0;
  for(i = 0; i < strlen(exp); i++)
  {
    if(isOperand(exp[i]))
      postfix[j++] = exp[i];
    else if(exp[i] == '(')
      push(&t, exp[i]);
    else if(exp[i] == ')')
    {
      while(!isEmpty(&temp) && peek(&temp) != '(')
        postfix[j++] = pop(&temp);
    }
    else
    {
      while(!isEmpty(&temp) && precedence(exp[i]) <= precedence(peek(&temp)))
        postfix[j++] = pop(&temp);
      push(&temp, exp[i]);
    }
  }
  while(!isEmpty(&temp))
    postfix[j++] = pop(&temp);

  postfix[j] = '\0';
  printf("Postfix Expression : %s\n",postfix);
}
