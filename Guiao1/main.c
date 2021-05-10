/*!
 * @file Ficheiro que contém a função principal do programa.
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

/**
 * @param s - Stack
 * \brief   Esta função verifica na stack a existência de "string", "integer", "double" e "number".
 * @returns Devolve os tipos da stack.
 */

void imprime_tipo(STACK *s){
    if (has_type(top(s), STRING)) putchar ('S');
    if (has_type(top(s), INTEGER)) putchar ('I');
    if (has_type(top(s), DOUBLE)) putchar ('D');
    if (has_type(top(s), NUMBER)) putchar ('N');
    printf ("\n");
}

/**
 * \brief Esta é a função principal do programa.
 */


int main() {

    char line[10240];

    assert ( fgets (line, 10240, stdin) != NULL);
    assert ( line[strlen(line) - 1] == '\n'    );

    parse(line);

    return 0;
}