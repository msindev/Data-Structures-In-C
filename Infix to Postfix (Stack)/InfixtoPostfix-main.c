#include "InfixtoPostfix.h"

int main()
{
  char infix[SIZE];
  printf("Enter Infix Expression: ");
  scanf("%[^\n]",infix);
  printf("Infix Expression : %s\n",infix);
  infixToPostfix(infix);
  return 0;
}
