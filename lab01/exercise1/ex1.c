// Copyright 2023 Sajid karim"
#include "ex1.h"
#include <string.h>
#include <stdio.h>

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */
int num_occurrences(char *str, char letter) {
  /* TODO: implement num_occurances */
  int srt_len = strlen(str);
  int count = 0;

  for (int i = 0; i < srt_len; i++) {
    /* code */
    if (str[i] == letter) count++;
  }

  return count;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20
nucleotides. All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
  /* TODO: implement compute_nucleotide_occurances */
  int i = 0;

  // run loop till NULL terminator

  while (dna_seq->sequence[i] != '\0') {
    int count = 0;

    /*
     * switch for all the present nucleotide in the sequence
     * default case wrong nucleotide
     * calls num_occurrences to count each nucleotide and stores
     * the value in dna_deq struct for each of them
     */

    switch (dna_seq->sequence[i]) {
      case 'A':
        /* code */
        count = num_occurrences(dna_seq->sequence, dna_seq->sequence[i]);
        printf("%d \n", count);
        dna_seq->A_count = count;
        break;
      case 'C':
        /* code */
        count = num_occurrences(dna_seq->sequence, dna_seq->sequence[i]);
        dna_seq->C_count = count;
        break;
      case 'G':
        /* code */
        count = num_occurrences(dna_seq->sequence, dna_seq->sequence[i]);
        dna_seq->G_count = count;
        break;
      case 'T':
        /* code */
        count = num_occurrences(dna_seq->sequence, dna_seq->sequence[i]);
        dna_seq->T_count = count;
        break;

      default:
        printf("Wrong nucleotide /n");
        break;
    }
    i++;
  }
  return;
}
