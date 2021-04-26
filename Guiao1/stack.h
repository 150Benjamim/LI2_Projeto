/*!
 * @file Ficheiro que contém as definições dos tipos.
 */

#ifndef GUIAO1_STACK_H
#define GUIAO1_STACK_H

#include <assert.h>

/**
 * @param line 14 - A função "enum" denomina os tipos com valores, de maneira a simplficar a sua chamada.
 */

typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;

/**
 * @param line 21 - Define que um tipo "LONG" e um tipo "CHAR" é um inteiro.
 * @param line 22 - Define que um tipo "INTEGER" e um tipo "DOUBLE" é um número.
 */

#define INTEGER (LONG | CHAR)
#define NUMBER (INTEGER | DOUBLE)

/**
 * @param line 28 - Apenas define os "data" correspondentes.
 */

typedef struct data {
    TYPE type;
    long LONG;
    double DOUBLE;
    char CHAR;
    char *STRING;
} DATA;

/**
 * @param line 40 - Indica que existe um inteiro para o tamanho e nº de elementos da stack.
 */

typedef struct stack {
    DATA *stack;
    int size;
    int n_elems;
} STACK;

int has_type(DATA elem, int mask);
STACK *create_stack();
void push (STACK *s, DATA elem);
DATA pop (STACK *s);
DATA top (STACK *s);
int is_empty(STACK *s);
void print_stack(STACK *s);

#define STACK_OPERATION_PROTO(_type,_name) \
    void push_##_name(STACK *s, _type val);\
    _type pop_##_name(STACK *s);           \

STACK_OPERATION_PROTO(long,LONG)
STACK_OPERATION_PROTO(double,DOUBLE)
STACK_OPERATION_PROTO(char,CHAR)
STACK_OPERATION_PROTO(char *,STRING)

#endif //GUIAO1_STACK_H
