#include "InfixtoPrefix.h"

int main()
{
  char infix[SIZE];
  printf("Enter Infix Expression: ");
  scanf("%[^\n]",infix);
  printf("Infix Expression : %s\n",infix);
  infixToPrefix(infix);
  return 0;
}
