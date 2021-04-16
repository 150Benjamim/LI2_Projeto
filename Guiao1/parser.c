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
        char *val_i = token;
        long val_l = strtol(token, &sobra,10);
        double val_d = strtod(token,&sobra);
        if (strlen(sobra) == 0){
            int i = 0, flag = 0;
            while(val_i[i++] != '\0'){
                if(val_i[i] == '.'){
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) push_DOUBLE(s,val_d);
            else push_LONG(s,val_l);
        } else if (strcmp(token, "+") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r;
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
            double r,r1;
            long r2;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r1 = Y.LONG; else r1 = Y.DOUBLE;
            if ((X.type==1) && (Y.type==1)){
                r2 = r / r1;
                push_LONG(s,(r2));
            }
            else{
                push_DOUBLE(s,(r/r1));
            }
        } else if (strcmp(token, "(") == 0) {
            DATA X = pop(s);
            if (X.type==2) push_DOUBLE(s,(X.DOUBLE)-1);
            else if (X.type==1) push_LONG(s,(X.LONG)-1);
            else if (X.type==4) push_CHAR(s,(X.CHAR)-1);
        } else if (strcmp(token, ")") == 0) {
            DATA X = pop(s);
            if (X.type==2) push_DOUBLE(s,(X.DOUBLE)+1);
            else if (X.type==1) push_LONG(s,(X.LONG)+1);
            else if (X.type==4) push_CHAR(s,(X.CHAR)+1);
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
        } else if (strcmp(token, "_") == 0){
            DATA X = pop(s);
            DATA Y = X;
            push(s,X);
            push(s,Y);
        }else if (strcmp(token, ";")== 0){
            pop(s);
        }else if (strcmp(token, "c") == 0) {
            DATA X = pop(s);
            if (X.type==1){
                char r = X.LONG;
                push_CHAR(s,r);
            }
            else push(s,X);
        }else if (strcmp(token, "\\") == 0){
            DATA X = pop(s);
            DATA Y = pop(s);
            push(s,X);
            push(s,Y);
        } else if (strcmp(token, "@") == 0) {
            DATA Z = pop(s);
            DATA Y = pop(s);
            DATA X = pop(s);
            push(s,Y);
            push(s,Z);
            push(s,X);
        } else if (strcmp(token, "$") == 0) {

            int i = 0;
            int x = pop_LONG(s);
            STACK stackAux = *s;

            while (i!=x) {
                pop(&stackAux);
                i++;
            }
            DATA A = pop(&stackAux);
            push(s,A);
        }else if (strcmp(token, "l") == 0) {
            assert (fgets(coca, 10240, stdin) != NULL);
            push_STRING(s, coca);
        } else if (strcmp(token, "i") == 0) {
            DATA X = pop(s);
            int Y;
            if (X.type == 4) Y = X.CHAR;
            else if (X.type == 8) Y = strtol(X.STRING, &sobra, 10);
            else if (X.type == 1) Y = X.LONG;
            else Y = X.DOUBLE;
            push_LONG(s, Y);
        } else if (strcmp(token, "f") == 0) {
            DATA X = pop(s);
            float Y;
            if (X.type == 4) Y = X.CHAR;
            else if (X.type == 8) Y = strtof(X.STRING, &sobra);
            else if (X.type == 1) Y = X.LONG;
            else Y = X.DOUBLE;
            push_DOUBLE(s, Y);
        }
    }

    print_stack(s);
}