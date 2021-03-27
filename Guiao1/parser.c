/**
 * @file As funções correspondentes ao parser.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"

/**
 * @param line 64 - A condição if verifica se a string dada é de tamanho 0.
 * @returns Devolve a string vazia.
 * 
 * @param line 66 - Aqui verificamos para quando a string tiver o caractér "+".
 * @returns O resultado da soma de dois números.
 *
 * @param line 70 - Aqui verificmos para quando a string tiver o caractér "-".
 * @returns O resultado da diferença de dois números.
 * 
 * @param line 74 - Aqui verificamos para quando a string tiver o caractér "*".
 * @returns O resultado da multiplicação de dois números.
 *
 * @param line 78 - Aqui verificamos para quando a string tiver o caractér "/".
 * @returns O resultado da divisão inteira de dois números.
 *
 * @param line 82 - Aqui verificamos para quando a string tiver o caractér "(".
 * @returns A incrementação de um número.
 *
 * @param line 85 - Aqui verificamos para quando a string tiver o caractér ")".
 * @returns A decrementação de um número.
 *
 * @param line 88 - Aqui verificamos para quando a string tiver o caractér "%".
 * @returns O resto da divisão de dois números.
 *
 * @param line 92 - Aqui verificamos para quando a string tiver o caractér "#".
 * @returns O resultado do primeiro número elevado ao segundo elemento.
 *
 * @param line 96 - Aqui verificamos para quando a string tiver o caractér "&".
 * @returns Transforma os dois elementos em binário e devolve os bites em comum.
 *
 * @param line 100 - Aqui verificamos para quando a string tiver o caractér "|".
 * @returns Transforma os dois elementos em binário e compara os seus bites. Devolve o bit 1, exceto quando ambos os bites em comparação forem 0, neste caso devolve o bit 0.
 *
 * @param line 104 - Aqui verificamos para quando a string tiver o caractér "^".
 * @returns Transforma os dois elementos em binário e compara os seus bites. Se os bites em comparação forem diferentes, devolve o bit 1. No caso, dos bites serem iguais devolve o bit 0.
 *
 * @param line 108 - Aqui verificamos para quando a string tiver o caractér "~".
 * @returns Transforma o seu único elemento em binário e inverte os valores dos seus bites.
 */


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
            long X = POP();
            PUSH(X - 1);
        } else if (strcmp(token, ")") == 0) {
            long X = POP();
            PUSH(X + 1);
        } else if (strcmp(token, "%") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X % Y);
        } else if (strcmp(token, "#") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(pow(X,Y));
        } else if (strcmp(token, "&") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X & Y);
        } else if (strcmp(token, "|") == 0) {
            long Y = POP();
            long X = POP();
            PUSH(X | Y);
        } else if (strcmp(token, "^") == 0) {
            long Y = POP();
            long X = POP();
            PUSH (X ^ Y);
        } else if (strcmp(token, "~") == 0) {
            long X = POP();
            PUSH(~X);
        }
    }


    PRINT_STACK();

    printf ("\n");
}