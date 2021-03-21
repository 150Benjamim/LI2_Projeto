#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int top = -1;

int isempty() {

    if(top == -1)
        return 1;
    else
        return 0;
}

int isfull() {

    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}

int POP() {
    int data;

    if (!isempty()) {
        data = stack[top];
        top = top - 1;
        return data;
    }
    else return 0;
}

int PUSH(int data) {

    if (!isfull()) {
        top = top + 1;
        stack[top] = data;
    }
    return 0;
}

void PRINT_STACK(){

        printf ("%d\n",stack[top]);
}




