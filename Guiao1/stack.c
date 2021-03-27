/**
 * @file As funções correspondentes à stack.
 */

#include <stdio.h>

#include "stack.h"

int top = -1;
int stack [MAXSIZE];

/**
 * @param line 17 - Vai verificar qual é o elemento que está no topo da stack.
 * @returns Se o topo contiver algum elemento, então devolve o valor de falso. Porém, se o topo estiver vazio entao devolve o valor de verdadeiro.
 */

int isempty() { 

    if(top == -1)
        return 1;
    else
        return 0;
}

/**
* @param line 30 - Vai verificar se o topo da stack está ocupada.
* @returns Caso o topo da stack esteja ocupada devolve verdade, caso contrário devolve falso.
*/

int isfull() { 

    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}

/**
* @param line 43 - Vai verificar se a stack está vazia. 
* @returns Se a stack estiver vazia, não executa nada, caso contrário, retira um elemento do topo da stack.
*/

int POP() { 
    int data;

    if (!isempty()) {
        data = stack[top];
        top = top - 1;
        return data;
    }
    return 0;
}

/**
* @param line 59 - Vai verificar se a stack está cheia.
* @returns Se a stack estiver cheia, não executa nada, caso contrário, acrescenta um elemento ao topo da stack.
*/ 

int PUSH(int data) { 

    if (!isfull()) {
        top = top + 1;
        stack[top] = data;
    }
    return 0;
}

/**
* @param line 72 - Imprime os elementos da stack, enquanto houver elementos que ainda não tenham sido imprimidos.
*/ 

void PRINT_STACK(){

    int i = 0;

    while (i<=top){
        printf ("%d",stack[i]);
        i++;
    }

}