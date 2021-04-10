#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"


void parse(char *line) {

    char *delims = " \t\n";

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        long val_i = strtol(token, &sobra, 10);
        if (strlen(sobra) == 0) {
            push(val_i);
        } else if (strcmp(token, "+") == 0) {
            long Y = pop();
            long X = pop();
            push(X + Y);
        } else if (strcmp(token, "-") == 0) {
            long Y = pop();
            long X = pop();
            push(X - Y);
        } else if (strcmp(token, "*") == 0) {
            long Y = pop();
            long X = pop();
            push(X * Y);
        } else if (strcmp(token, "/") == 0) {
            long Y = pop();
            long X = pop();
            push(X / Y);
        } else if (strcmp(token, "(") == 0) {
            long X = pop();
            push(X - 1);
        } else if (strcmp(token, ")") == 0) {
            long X = pop();
            push(X + 1);
        } else if (strcmp(token, "%") == 0) {
            long Y = pop();
            long X = pop();
            push(X % Y);
        } else if (strcmp(token, "#") == 0) {
            long Y = pop();
            long X = pop();
            push(pow(X,Y));
        } else if (strcmp(token, "&") == 0) {
            long Y = pop();
            long X = pop();
            push(X & Y);
        } else if (strcmp(token, "|") == 0) {
            long Y = pop();
            long X = pop();
            push(X | Y);
        } else if (strcmp(token, "^") == 0) {
            long Y = pop();
            long X = pop();
            push (X ^ Y);
        } else if (strcmp(token, "~") == 0) {
            long X = pop();
            push(~X);
        }
    }


    print_stack();

    printf ("\n");
}
