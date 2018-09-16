#include "PolyEval.h"

NODE readPolynomial(NODE first)
{
  int i,n;
  int coeff,exponent;
  printf("Enter no. of terms: ");
  scanf("%d", &n);
  for(i = 0; i < n; i++)
  {
    printf("Enter term %d : \n", i+1);
    printf("Coefficient : ");
    scanf("%d",&coeff);
    printf("Exponent : ");
    scanf("%d", &exponent);
    first = insert(coeff, exponent, first);
  }
  return first;
}

NODE insert(int coeff, int exponent, NODE first)
{
  NODE newnode,cur;
  newnode = (NODE) malloc(sizeof(struct node));
  newnode -> coeff = coeff;
  newnode -> exponent = exponent;
  newnode -> next = NULL;
  if(first == NULL)
    first = newnode;
  else
  {
    cur = first;
    while (cur -> next != NULL)
      cur = cur -> next;
    cur -> next = newnode;
  }
  return first;
}

NODE multiply(NODE p1, NODE p2)
{
  NODE p = p1, q = p2;
  NODE result = NULL;
  if(p == NULL || q == NULL)
  {
    printf("Multiplied Polynomial is a zero degree polynomial.\n");
    exit(0);
  }
  while(p != NULL)
  {
    q = p2;
    while(q != NULL)
    {
      result = insert(p ->coeff * q -> coeff, p -> exponent + q -> exponent, result);
      q = q -> next;
    }
    p = p -> next;
  }
  return result;
}

void display(NODE first)
{
  NODE temp;
  if(first == NULL)
  {
    printf("No Polynomial Exists\n");
    return;
  }
  temp = first;
  while(temp ->next != NULL)
  {
    printf("%dx^%d + ", temp -> coeff, temp -> exponent);
    temp = temp -> next;
  }
  temp = temp -> next;
  printf("%dx^%d + ", temp -> coeff, temp -> exponent);
  printf("\n");
}
