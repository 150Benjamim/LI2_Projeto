#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
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
            PUSH (r);
        } else if (strcmp(token, "#") == 0) {
            long Y = POP();
            long X = POP();
            long x = X;
            while (Y > 1) {
                X *= x;
                Y--;
            }
            PUSH(X);
        }
       else if (strcmp(token, "&") == 0){
            long Y = POP();
            long X = POP();
            int x[20]={0},
                y[20]={0};

            dectoBinary(Y,y,20);

            dectoBinary(X,x,20);

            int final[20];

            long last;

            for (int array = 0; array<20; array++){
                if ((x[array] == y[array]) && (x[array] != 0)) final[array] = 1;
                else final[array] = 0;
            }

            last = binarytoDec(final,20);

            PUSH(last);
        }


    }


    PRINT_STACK();
}