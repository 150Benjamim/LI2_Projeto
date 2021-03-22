#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "stack.h"
#include "binariesAndInts.h"


void parse(char *line) {

    char *delims = " \t\n";

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        long val_i = strtol(token, &sobra, 10);
        if (strlen(sobra) == 0) {
            PUSH(val_i);
        } else if (strcmp(token, "+") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X + Y);
        } else if (strcmp(token, "-") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X - Y);
        } else if (strcmp(token, "*") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X * Y);
        } else if (strcmp(token, "/") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X / Y);
        } else if (strcmp(token, "(") == 0) {
            long Y = POP();
            PUSH(Y - 1);
        } else if (strcmp(token, ")") == 0) {
            long Y = POP();
            PUSH(Y + 1);
        } else if (strcmp(token, "%") == 0) {
            long Y = POP();
            long X = POP();
            int x = X;
            int y = Y;
            int r = x % y;
            PUSH(r);
        } else if (strcmp(token, "#") == 0) {
            long Y = POP();
            long X = POP();
            long x = X;
            while (Y > 1) {
                X *= x;
                Y--;
            }
            PUSH(X);
        } else if (strcmp(token, "&") == 0) {
            long Y = POP();
            long X = POP();
            int x[64] = {0},
                y[64] = {0};

            dectoBinary(Y, y, 64);

            dectoBinary(X, x, 64);

            int final[64];

            long last;

            for (int array = 0; array < 64; array++) {
                if ((x[array] == y[array]) && (x[array] != 0)) final[array] = 1;
                else final[array] = 0;
            }

            last = binarytoDec(final, 64);

            PUSH(last);
        } else if (strcmp(token, "|") == 0) {
            long Y = POP();
            long X = POP();
            int x[64] = {0},
                y[64] = {0};

            dectoBinary(Y, y, 64);

            dectoBinary(X, x, 64);

            int final[64];

            long last;

            for (int array = 0; array < 64; array++) {
                if ((x[array] == 1) || (y[array] == 1)) final[array] = 1;
                else final[array] = 0;
            }

            last = binarytoDec(final, 64);

            PUSH(last);
        } else if (strcmp(token, "^") == 0) {
            long Y = POP();
            long X = POP();
            int x[64] = {0},
                y[64] = {0};

            dectoBinary(Y, y, 64);

            dectoBinary(X, x, 64);

            int final[64];

            long last;

            for (int array = 0; array < 64; array++) {
                if (x[array] == y[array]) final[array] = 0;
                else final[array] = 1;
            }

            last = binarytoDec(final, 64);

            PUSH(last);
        } else if (strcmp(token, "~") == 0) {
            long X = POP();
            
            PUSH(-X-1);
        }
    }


    PRINT_STACK();

    printf ("\n");
}
