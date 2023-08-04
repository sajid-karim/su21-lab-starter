// Copyright sajid karim
#include <stdio.h>
#include <stdlib.h>



int odd_occurring(int *a , int size) {
  int odd = a[0];
  for (int i = 1; i < size; i++) {
    odd ^=  a[i];
  }
  printf("Odd %d \n", odd);

  return odd;
}

int main() {
  int array[] = {12, 12, 14, 90, 14, 14, 14};
  int s = sizeof(array)/sizeof(array[0]);

  odd_occurring(array, s);
  return 0;
}
