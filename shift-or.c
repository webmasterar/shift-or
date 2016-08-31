//License MIT 2016 Ahmad Retha
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shift-or.h"

void preprocess(WORD ** B, const char * p, unsigned int m)
{
    unsigned int i;
    WORD x = (1ul << m) - 1; //11111111

    //step 1: Fill B with 1s up to length m
    for (i = 0; i < CHARLIMIT; i++) {
	(*B)[i] = x;
    }

    //step 2: demarcate positions characters occur in the pattern as 0s
    for (i = 0; i < m; i++) {
	(*B)[p[i]] = (1ul << i) ^ (*B)[p[i]];
    }
}

void search(const char * t, unsigned int n, const char * p, unsigned int m)
{
    WORD * B;
    B = (WORD *) malloc(CHARLIMIT * WORDSIZE);

    preprocess(&B, p, m);

    //a is the starting state
    WORD a = (1ul << m) - 1; //11111111
    //z is a number with 1 at the end state
    WORD z = 1ul << (m  - 1);

    unsigned int i;
    for (i = 0; i < n; i++)
    {
	a = (a << 1) | B[t[i]];

	//invert a and if 1 is present at end state then match found
        if (~a & z) {
            printf("Match found at position %u\n", i - m + 1);
        }
    }

    free(B);
}
