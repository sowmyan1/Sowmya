#include <stdio.h>
 
int main()
{
  int c, n=5, fact = 1;
 
  for (c = 1; c <= n; c++)
    fact = fact * c;
 
  return fact;
}
