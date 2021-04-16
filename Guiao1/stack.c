/**
 * @file As funções correspondentes à stack.
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/**
 * \brief Apenas verifica se a conjunção entre "elem" e "mask" é verdadeira.
 */

int has_type(DATA elem, int mask){
    return (elem.type & mask) != 0;
}

/**
 * @param line 20 - Cria uma stack com 100 elementos e devolve-a.
 */

STACK *create_stack(){
    STACK *s = (STACK *) malloc(sizeof(STACK));
    s->n_elems = 0;
    s->size = 100;
    s->stack = (DATA *) calloc(s->size, sizeof (DATA));
    return s;
}

/**
 * @param line 33 - A função "push" acrescenta um valor à stack.
 */

void push(STACK *s, DATA elem){
    if (s->size == s->n_elems){
        s->size += 100;
        s->stack = (DATA *) realloc(s->stack, s->size * sizeof (DATA));
    }
    s->stack[s->n_elems] = elem;
    s->n_elems++;
}

/**
 * @param line 44 - A "pop" retira um valor ao topo da stack.
 */

DATA pop(STACK *s){
    s->n_elems--;
    return s->stack[s->n_elems];
}

/**
 * @param line 53 - Devolve o elemento que se encontra no topo da stack
 */

DATA top(STACK *s){
    return s->stack[s->n_elems-1];
}

/**
 * @param line 61 - A "is_empty" comprova se a stack está vazia.
 */

int is_empty(STACK *s) {
    return s->n_elems == 0;
}

/**
 * @param line 44 - A função "print_stack" devolve a stack.
 */

void print_stack(STACK *s) {
    for (int K = 0; K < s->n_elems; K++) {
        DATA elem = s->stack[K];
        TYPE type = elem.type;
        switch (type){
            case LONG:
                printf("%ld", elem.LONG);
                break;
            case DOUBLE:
                printf("%g", elem.DOUBLE);
                break;
            case CHAR:
                printf("%c", elem.CHAR);
                break;
            case STRING:
                printf("%s", elem.STRING);
                break;
        }
    }
    printf("\n");
}

/**
 * @param line 69 - Esta função define todas as operações que alteram os elementos da stack ("pop" e "push")
 */

#define STACK_OPERATION(_type, _name)       \
    void push_##_name(STACK *s, _type val){ \
        DATA elem;                          \
        elem.type = _name;                  \
        elem._name = val;                   \
        push(s,elem);                       \
    }                                       \
    _type pop_##_name(STACK *s){            \
        DATA elem = pop(s);                 \
        assert(elem.type == _name);         \
        return elem._name;                  \
    }                                       \


STACK_OPERATION(long,LONG)
STACK_OPERATION(double,DOUBLE)
STACK_OPERATION(char,CHAR)
STACK_OPERATION(char *,STRING)

