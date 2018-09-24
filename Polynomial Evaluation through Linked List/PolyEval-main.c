#include "PolyEval.h"

int main()
{
  NODE poly1 = NULL, poly2 = NULL, poly3 = NULL;
  printf("Enter Polynomial 1 :\n");
  poly1 = readPolynomial(poly1);
  printf("Enter Polynomial 2 : \n");
  poly2 = readPolynomial(poly2);
  poly3 = multiply(poly1, poly2);
  printf("Polynomial 1 : ");
  display(poly1);
  printf("Polynomial 2 : ");
  display(poly2);
  printf("Result : ");
  display(poly3);
  return 0;
}
