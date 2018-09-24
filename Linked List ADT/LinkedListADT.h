#ifndef LinkedListADT_h
#define LinkedListADT_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node, *nodeptr;

void insertFront(nodeptr, int);
void insertRear(nodeptr, int);
void insertAtPos(nodeptr, int, int);

void deleteFront(nodeptr);
void deleteRear(nodeptr);
void deleteAtPos(nodeptr);

void display(nodeptr);

#endif
