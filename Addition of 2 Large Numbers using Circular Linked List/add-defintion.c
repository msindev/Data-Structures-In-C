#include "add.h"

struct node *getnode()
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode -> next = newnode;
  return newnode;
}

struct node *insert(struct node *head, int value)
{
  struct node *newnode = getnode();
  newnode -> data = value;
  if(head -> next == head)
  {
    head -> next = newnode;
    newnode -> next = head;
  }
  else
  {
    newnode -> next = head -> next;
    head -> next = newnode;
  }
  return head;
}

struct node *addToList(struct node *first, struct node *second)
{
  struct node *res = NULL, *temp, *prev = NULL, *h1, *h2;
  int carry = 0, sum;
  res = getnode();
  res -> data = 0;
  res -> next = res;
  h1 = first;
  h2 = second;
  first = first -> next;
  second = second -> next;
  while(first != h1 && second != h2)
  {
    sum = carry + (first ? first -> data : 0) + (second ? second -> data : 0);
    carry = (sum >= 10) ? 1 : 0;
    sum = sum % 10;
    res = insert(res, sum);
    if(first != h1)
      first = first -> next;
    if(second != h2)
      second = second -> next;
  }
  if(first != h1)
  {
    while(first != h1)
    {
      sum = carry + first -> data;
      carry = (sum >= 10) ? 1 : 0;
      sum = sum % 10;
      res = insert(res, sum);
      if(first != h1)
        first = first -> next;
    }
  }
  if(second != h2)
  {
    while(second != h2)
    {
      sum = carry + second -> data;
      carry = (sum >= 10) ? 1 : 0;
      sum = sum % 10;
      res = insert(res, sum);
      if(second != h2)
        second = second -> next;
    }
  }
  if(carry > 0)
  {
    res = insert(res, carry);
  }
  return res;
}

void printlist(struct node *head)
{
  struct node *temp = head;
  temp = temp -> next;
  while(temp != head)
  {
    printf("%d", temp -> data);
    temp = temp -> next;
  }
  printf("\n");
}
