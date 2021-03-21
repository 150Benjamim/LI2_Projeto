#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"


void parse(char *line){

    char *delims = " \t\n";

    for (char *token = strtok (line,delims); token != NULL; token = strtok (NULL, delims)){
        printf ("%s\n", token);
    }

    



}