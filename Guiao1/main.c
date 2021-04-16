/*!
 * @file Ficheiro que contém a função principal do programa.
 */

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

/**
 * @param line 15 - A função "imprime_tipo" verifica na stack a existência de "string", "integer", "double" e "number".
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


/**
int main(void) {

    STACK *s = create_stack();

    push_STRING (s, strdup("ola mundo")); imprime_tipo(s);
    push_LONG (s, 2); imprime_tipo(s);
    push_DOUBLE (s,3.2); imprime_tipo(s);
    push_CHAR (s, 'A'); imprime_tipo(s);
    print_stack(s);

    printf("%c\n", pop_CHAR(s));
    printf ("%g\n",pop_DOUBLE(s));
    printf("%ld\n",pop_LONG(s));

    return 0;
}
**/


