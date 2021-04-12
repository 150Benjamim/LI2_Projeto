#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"

void parse(char *line) {

    char *delims = " \t\n";

    char coca[10240];
    char *aux;

    STACK *s = create_stack();

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        double val_i = strtod(token, &sobra);
        if (strlen(sobra) == 0) {
            push_DOUBLE(s, val_i);
        } else if (strcmp(token, "+") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            if (X.type == 2 || Y.type == 2){
                double r = X.DOUBLE + Y.DOUBLE;
                push_DOUBLE(s,r);
            }
            else {
                float r = X.LONG + Y.LONG;
                push_LONG(s,r);
            }
        } else if (strcmp(token, "-") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s, X - Y);
        } else if (strcmp(token, "*") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s, X * Y);
        } else if (strcmp(token, "/") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s, X / Y);
        } else if (strcmp(token, "(") == 0) {
            long X = pop_LONG(s);
            push_LONG(s, X - 1);
        } else if (strcmp(token, ")") == 0) {
            long X = pop_LONG(s);
            push_LONG(s, X + 1);
        } else if (strcmp(token, "%") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s, X % Y);
        } else if (strcmp(token, "#") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s, pow(X, Y));
        } else if (strcmp(token, "&") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s, X & Y);
        } else if (strcmp(token, "|") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s, X | Y);
        } else if (strcmp(token, "^") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s, X ^ Y);
        } else if (strcmp(token, "~") == 0) {
            long X = pop_LONG(s);
            push_LONG(s, ~X);
        } else if (strcmp(token, "l") == 0) {
            assert (fgets(coca, 10240, stdin) != NULL);
            push_STRING(s, coca);
        } else if (strcmp(token, "i") == 0) {
            char *X = pop_STRING(s);
            long Y = strtol(X, &sobra, 10);
            push_LONG(s, Y);
        } else if (strcmp(token, "f") == 0) {
            char *X = pop_STRING(s);
            double Y = strtod(X, &aux);
            push_DOUBLE(s, Y);
        }
    }

    print_stack(s);
}