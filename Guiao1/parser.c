#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "stack.h"


void parse(char *line){

    char *delims = " \t\n";

    for (char *token = strtok (line,delims); token != NULL; token = strtok (NULL, delims)){
        char *sobra;
        long val_i  = strtol (token, &sobra, 10);
        if(strlen(sobra)==0){
            PUSH(val_i);
        }
        else if(strcmp(token, "+")==0){
            long Y = POP();
            long X = POP();
            PUSH (X+Y);
        }
        else if(strcmp(token, "-")==0){
            long Y = POP();
            long X = POP();
            PUSH (X-Y);
        }
        else if(strcmp(token, "*")==0){
            long Y = POP();
            long X = POP();
            PUSH (X*Y);
        }
        else if(strcmp(token, "/")==0){
            long Y = POP();
            long X = POP();
            PUSH (X/Y);
        }
        else if(strcmp(token, "(")==0){
            long Y = POP();
            PUSH (Y-1);
        }
        else if(strcmp(token, ")")==0){
            long Y = POP();
            PUSH (Y+1);
        }
    }

    PRINT_STACK();

}