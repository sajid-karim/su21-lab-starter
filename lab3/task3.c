#include <stdio.h>

#define CSR_VAL 0x8000abcd00001234UL

#define ADDRESS 0x5300f000U

unsigned long int my_csr = CSR_VAL;


int main(void) {
  // (a) here:
  // set bit 0 to 1
  my_csr = my_csr | 0x1;
  // (b) here:
  // set third bit to 0
  my_csr = my_csr & ~(0x1 << 2);

  // (c) here:
  // mask for 0xEE
  unsigned long int mask = 0xEE << 8;

  // mask our mask and my_csr to set the bits 8 to 15 to 0xEE
  my_csr = my_csr | mask;
  my_csr = (my_csr ^ (0xf << 12)) | (0xE << 12);

  // (d) here:
  // extract bits 12 to 27 from the Address
  unsigned long int mask2 = (ADDRESS >> 12) & 0xFFFF;

// set bits 16 to 31 with the extracted bits using OR operation
  my_csr |= mask2 << 16;


  printf("%lx \n", my_csr);

  return 0;
}