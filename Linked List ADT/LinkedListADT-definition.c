#include "LinkedListADT.h"

void insertFront(nodeptr head, int element)
{
  nodeptr new_node = (nodeptr)malloc(sizeof(node));
  new_node->data = element;
  new_node->next = head;
  head = new_node;
}

void insertRear(nodeptr head, int element)
{
  nodeptr temp = head;
  nodeptr new_node = (nodeptr)malloc(sizeof(node));
  new_node->data = element;
  new_node->next = NULL;
  if(head == NULL)
  {
    head = new_node;
    return;
  }
  while(temp->next != NULL)
    temp = temp->next;
  temp->next = new_node;
}

void insertAtPos(nodeptr head, int element, int position)
{
  nodeptr prev = head;
  int count = -1;
  while(count != position)
  {
    count++;
    prev = prev->next;
  }
  if(prev == NULL)
  {
    printf("The previous node cannot be NULL\n");
    return;
  }
  nodeptr new_node = (nodeptr)malloc(sizeof(node));
  new_node->data = element;
  new_node->next = prev->next;
  prev->next = new_node;
}
