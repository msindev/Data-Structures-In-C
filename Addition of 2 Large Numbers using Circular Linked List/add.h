#ifndef add_h
#define add_h

#include <stdio.h>
#include <stdlib.h>
struct node
{
  struct node *next;
  int data;
};

struct node *getnode();
struct node *insert(struct node *,int);
struct node *addToList(struct node *, struct node *);
void printlist(struct node *);

#endif
