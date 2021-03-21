#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"


void parse(char *line){

    char *delims = " \t\n";

    for (char *token = strtok (line,delims); token != NULL; token = strtok (NULL, delims)){
        char *sobra;
        long val_i  = strtol (token, &sobra, 10);
        if(strlen(sobra)==0){
            printf("INT: %ld\n",val_i);
        }
        else{
            double val_d = strtod(token, &sobra);
            if (strlen(sobra)==0){
                printf("DOUBLE: %lf\n",val_d);
            }
            else printf ("%s\n", token);
        }
    }

    
}