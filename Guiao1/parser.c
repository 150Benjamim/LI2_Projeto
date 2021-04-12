#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"

void parse(char *line) {

    char *delims = " \t\n";

    char coca[10240];

    STACK *s = create_stack();

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        float val_i = strtof(token, &sobra);
        if (strlen(sobra) == 0) {
            int aux = val_i;
            if (aux == val_i) push_LONG(s,val_i);
            else push_DOUBLE(s,val_i);
        } else if (strcmp(token, "+") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r=0;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r += Y.LONG; else r += Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
            else push_LONG(s,r);
        } else if (strcmp(token, "-") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r -= Y.LONG; else r -= Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
            else push_LONG(s,r);
        } else if (strcmp(token, "*") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r *= Y.LONG; else r *= Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
            else push_LONG(s,r);
        } else if (strcmp(token, "/") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r = r / Y.LONG; else r = r / Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
            else push_LONG(s,r);
        } else if (strcmp(token, "(") == 0) {
            DATA X = pop(s);
            if (X.type==2) push_DOUBLE(s,(X.DOUBLE)--);
            else push_LONG(s,(X.LONG)--);
        } else if (strcmp(token, ")") == 0) {
            DATA X = pop(s);
            if (X.type==2) push_DOUBLE(s,(X.DOUBLE)++);
            else push_LONG(s,(X.LONG)++);
        } else if (strcmp(token, "%") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            long r1,r2;
            if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
            if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1%r2));
            else push_LONG(s,(r1%r2));
        } else if (strcmp(token, "#") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r = pow (r,Y.LONG); else r = pow (r,Y.DOUBLE);
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
            else push_LONG(s,r);
        } else if (strcmp(token, "&") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            long r1,r2;
            if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
            if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1&r2));
            else push_LONG(s,(r1&r2));
        } else if (strcmp(token, "|") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            long r1,r2;
            if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
            if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1|r2));
        } else if (strcmp(token, "^") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            long r1,r2;
            if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
            if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1^r2));
        } else if (strcmp(token, "~") == 0) {
            long X = pop_LONG(s);
            push_LONG(s, ~X);
        } else if (strcmp(token, "l") == 0) {
            assert (fgets(coca, 10240, stdin) != NULL);
            push_STRING(s, coca);
        } else if (strcmp(token, "i") == 0) {
            DATA X = pop(s);
            int Y;
            if ((X.type == 4) || (X.type == 8)) {
                Y = strtol(X.STRING, &sobra, 10);
            }
            else if (X.type == 1) Y = X.LONG;
            else Y = X.DOUBLE;
            push_LONG(s, Y);
        } else if (strcmp(token, "f") == 0) {
            DATA X = pop(s);
            float Y;
            if ((X.type == 4) || (X.type == 8)) {
                Y = strtof(X.STRING, &sobra);
            }
            else if (X.type == 1) Y = X.LONG;
            else Y = X.DOUBLE;
            push_DOUBLE(s, Y);
        }
    }

    print_stack(s);
}