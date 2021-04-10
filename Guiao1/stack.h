#ifndef GUIAO1_STACK_H
#define GUIAO1_STACK_H

#include <assert.h>

typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;

#define INTEGER (LONG | CHAR);
#define NUMBER (INTEGER | DOUBLE);

typedef struct data {
    TYPE type;
    long LONG;
    double DOUBLE;
    char CHAR;
    char *STRING;
} DATA;

typedef struct stack {
    DATA *stack;
    int size;
    int n_elems;
} STACK;

int has_type(DATA elem, int mask);
STACK *create_stack();
void push (STACK *s, DATA elem);
DATA pop (STACK *S);
DATA top (STACK *s);
int is_empty(STACK *s);
void print_stack(STACK *s);

#define STACK_OPERATION_PROTO(_type,_name) \
    void push_##_name(STACK *s, _type val);\
    _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO(long,LONG)
STACK_OPERATION_PROTO(double,DOUBLE)
STACK_OPERATION_PROTO(char,CHAR)
STACK_OPERATION_PROTO(char *,STRING)

#endif //GUIAO1_STACK_H