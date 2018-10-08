#include "add.h"

int main()
{
  char str1[100], str2[100];
  int i, num;
  struct node *res = NULL;
  struct node *first = NULL;
  struct node *second = NULL;
  first = getnode();
  first -> data = 0;
  first -> next = first;
  second = getnode();
  second -> data = 0;
  second -> next = second;
  printf("Enter number 1: ");
  scanf("%s", str1);
  getchar();
  printf("Enter number 2: ");
  scanf("%s", str2);
  for(i = 0; str1[i] != '\0'; i++)
  {
    num = str1[i] - 48;
    first = insert(first, num);
  }
  printf("1st Number: ");
  puts(str1);
  for(i = 0; str2[i] != '\0'; i++)
  {
    num = str2[i] - 48;
    second = insert(second, num);
  }
  printf("Second Number: ");
  puts(str2);
  res = addToList(first, second);
  printf("Result: ");
  printlist(res);
  return 0;
}
