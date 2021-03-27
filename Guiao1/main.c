/*!
 * @file Ficheiro que contém a função principal do programa.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "parser.h"

/**
 * \brief Esta é a função principal do programa.
 *
 * 
 * 
 *
 * @returns Devolve o valor 0.
 */

int main() {

    char line[10240];

    assert ( fgets (line, 10240, stdin) != NULL);
    assert ( line[strlen(line) - 1] == '\n'    );

    parse(line);

    return 0;
}
