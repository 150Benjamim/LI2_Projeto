#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#include "binariesAndInts.h"


void dectoBinary (long dec,int lista[],int N){

    int i;

    for (i = (N-1); dec > 0; i--) {
        lista[i] = dec % 2;
        dec = dec / 2;
    }
}

int binarytoDec (int lista[],int N){

    int f=19;
    int numero=0;
    int exp=0;

    while(N > 0) {
        numero += lista[f] * pow(2, exp);
        N--;
        exp++;
        f--;
    }


    return numero;
}