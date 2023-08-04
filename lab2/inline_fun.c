// Copyright sajid karim
#include <stdio.h>
#include <stdlib.h>

// #include "inline_fun.h"

static inline int intc() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  return n;
}

int main() {
  int n =  intc();

  printf("Integer returned : %d \n", n);
  return 0;
}
