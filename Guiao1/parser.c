#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"

void parse(char *line) {

    char *delims = " \t\n";

    STACK *s = create_stack();

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        long val_i = strtol(token, &sobra, 10);
        if (strlen(sobra) == 0){
            push_LONG(s, val_i);
        } else if (strcmp(token, "+") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s, X + Y);
        } else if (strcmp(token, "-") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s,X - Y);
        } else if (strcmp(token, "*") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s,X * Y);
        } else if (strcmp(token, "/") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s,X / Y);
        } else if (strcmp(token, "(") == 0) {
            long X = pop_LONG(s);
            push_LONG(s,X - 1);
        } else if (strcmp(token, ")") == 0) {
            long X = pop_LONG(s);
            push_LONG(s,X + 1);
        } else if (strcmp(token, "%") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s,X % Y);
        } else if (strcmp(token, "#") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s,pow(X,Y));
        } else if (strcmp(token, "&") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s,X & Y);
        } else if (strcmp(token, "|") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s,X | Y);
        } else if (strcmp(token, "^") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s,X ^ Y);
        } else if (strcmp(token, "~") == 0) {
            long X = pop_LONG(s);
            push_LONG(s,~X);
        }

        print_stack(s);

        printf("\n");
    }
}
