#include "InfixtoPostfix.h"

int main()
{
  char infix[SIZE];
  printf("Enter Infix Expression: ");
  scanf("[^\n]",infix);
  infixToPostfix(infix);
  return 0;
}
