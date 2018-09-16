#ifndef PolyEval_h
#define PolyEval_h

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int coeff;
  int exp;
  struct node *next;
};

typedef struct node *NODE;

NODE readPolynomial(NODE first);
NODE insert(int, int, NODE);
NODE multiply(NODE, NODE);
void display(NODE);

#endif
