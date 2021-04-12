#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"

void parse(char *line) {

    char *delims = " \t\n";

    char coca[10240];

    char *fodasse;

    STACK *s = create_stack();

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        long val_i = strtol(token, &sobra, 10);
        if (strlen(sobra) == 0) {
            push_LONG(s, val_i);
        } else if (strcmp(token, "+") == 0) {
            long Y = pop_LONG(s);
            long X = pop_LONG(s);
            push_LONG(s, X + Y);
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
            double Y = strtod(X, &fodasse);
            push_DOUBLE(s, Y);
        }
    }

    print_stack(s);
}
