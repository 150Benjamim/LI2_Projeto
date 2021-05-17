#include "stack.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "+".
 * @returns O resultado da soma de dois elementos.
 */

void soma(STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    double r;
    if (X.type==1) r = X.LONG; else r = X.DOUBLE;
    if (Y.type==1) r += Y.LONG; else r += Y.DOUBLE;
    if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
    else push_LONG(s,r);
}
/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "-".
 * @returns O resultado da diferença de dois elementos.
 */

void diferenca(STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    double r;
    if (X.type==1) r = X.LONG; else r = X.DOUBLE;
    if (Y.type==1) r -= Y.LONG; else r -= Y.DOUBLE;
    if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
    else push_LONG(s,r);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "*".
 * @returns O resultado da multiplicação de dois elementos.
 */

void multiplication(STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    double r;
    if (X.type==1) r = X.LONG; else r = X.DOUBLE;
    if (Y.type==1) r *= Y.LONG; else r *= Y.DOUBLE;
    if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
    else push_LONG(s,r);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "/".
 * @returns O resultado da divisão inteira de dois elementos.
 */

void dividir(STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    double r,r1;
    long r2;
    if (X.type==1) r = X.LONG; else r = X.DOUBLE;
    if (Y.type==1) r1 = Y.LONG; else r1 = Y.DOUBLE;
    if ((X.type==1) && (Y.type==1)){
        r2 = r / r1;
        push_LONG(s,(r2));}
        else{
            push_DOUBLE(s,(r/r1));
        }
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér ")".
 * @returns A decrementação de um elemento.
 */

void decrementar(STACK *s){
    DATA X = pop(s);
    if (X.type==2) push_DOUBLE(s,(X.DOUBLE)-1);
    else if (X.type==1) push_LONG(s,(X.LONG)-1);
    else if (X.type==4) push_CHAR(s,(X.CHAR)-1);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "(".
 * @returns A incrementação de um elemento.
 */
   
void incrementar(STACK *s){
    DATA X = pop(s);
    if (X.type==2) push_DOUBLE(s,(X.DOUBLE)+1);
    else if (X.type==1) push_LONG(s,(X.LONG)+1);
    else if (X.type==4) push_CHAR(s,(X.CHAR)+1);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "%".
 * @returns O resto da divisão de dois elementos.
 */

void modulo(STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    long r1,r2;
    if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
    if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
    if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1%r2));
    else push_LONG(s,(r1%r2));
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "#".
 * @returns O resultado do primeiro elemento elevado ao segundo elemento.
 */

void exponenciacao(STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    double r;
    if (X.type==1) r = X.LONG; else r = X.DOUBLE;
    if (Y.type==1) r = pow (r,Y.LONG); else r = pow (r,Y.DOUBLE);
    if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
    else push_LONG(s,r);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "&".
 * @returns Transforma os dois elementos em binário e devolve os bites em comum.
 */

void eee(STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    long r1,r2;
    if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
    if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
    if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1&r2));
    else push_LONG(s,(r1&r2));
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "|".
 * @returns Transforma os dois elementos em binário e compara os seus bites. Devolve o bit 1, exceto quando ambos os bites em comparação forem 0, neste caso devolve o bit 0.
 */

void ouou(STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    long r1,r2;
    if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
    if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
    if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1|r2));
    else push_LONG(s,(r1|r2));
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "^".
 * @returns Transforma os dois elementos em binário e compara os seus bites. Se os bites em comparação forem diferentes, devolve o bit 1. No caso, dos bites serem iguais devolve o bit 0.
 */

void xoe(STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    long r1,r2;
    if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
    if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
    if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1^r2));
    else push_LONG(s,(r1^r2));
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "~".
 * @returns Transforma o seu único elemento em binário e inverte os valores dos seus bites.
 */

void not(STACK *s){
    long X = pop_LONG(s);
    push_LONG(s, ~X);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "_".
 * @returns Retornar dois "push's" da stack.
 */

void duplicar(STACK *s){
    DATA X = pop(s);
    push(s,X);
    push(s,X);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér ";".
 * @returns Devolve o primeiro elemento da stack.
 */

void darpop(STACK *s){
    pop(s);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "c".
 * @returns Converter o topo da stack para caractér.
 */

void convertcaractere(STACK *s){
    DATA X = pop(s);
    if (X.type==1){
        char r = X.LONG;
        push_CHAR(s,r);
    }
    else push(s,X);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "\\".
 * @returns Trocar os dois primeiros elementos do topo da stack.
 */

void trocardois(STACK *s){
    DATA X = pop(s);
    DATA Y = pop(s);
    push(s,X);
    push(s,Y);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "@".
 * @returns Rodar os 3 primeiros elementos no topo da stack.
 */

void rodartres(STACK *s){
    DATA Z = pop(s);
    DATA Y = pop(s);
    DATA X = pop(s);
    push(s,Y);
    push(s,Z);
    push(s,X);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "$".
 * @returns Copia o n-ésimo elemento para o topo da stack.
 */

void copiarelemento(STACK *s){
    int i = 0;
    int x = pop_LONG(s);
    STACK stackAux = *s;
    while (i!=x) {
        pop(&stackAux);
        i++;
    }
    DATA A = pop(&stackAux);
    push(s,A);
}



void serigual(STACK *s){
    DATA Y = pop(s);
    DATA X = pop(s);
    double auxX;
    double auxY;
    if (X.type == 1) auxX = X.LONG;
    else auxX = X.DOUBLE;
    if (Y.type == 1) auxY = Y.LONG;
    else auxY = Y.DOUBLE;
    if (auxX == auxY) push_LONG(s,1);
    else push_LONG(s,0);
}

    void sermenor(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        double auxX;
        double auxY;
        if (X.type == 1) auxX = X.LONG;
        else auxX = X.DOUBLE;
        if (Y.type == 1) auxY = Y.LONG;
        else auxY = Y.DOUBLE;
        if (auxX < auxY) push_LONG(s,1);
        else push_LONG(s,0);
    }

    void sermaior(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        double auxX;
        double auxY;
        if (X.type == 1) auxX = X.LONG;
        else auxX = X.DOUBLE;
        if (Y.type == 1) auxY = Y.LONG;
        else auxY = Y.DOUBLE;
        if (auxX > auxY) push_LONG(s,1);
        else push_LONG(s,0);
    }

    void nope(STACK *s){
        int X = pop_LONG(s);
        if (X == 0) push_LONG(s,1);
        else push_LONG(s,0);
    }

    void shortcute(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        double auxX;
        double auxY;
        if (X.type == 1) auxX = X.LONG;
        else auxX = X.DOUBLE;
        if (Y.type == 1) auxY = Y.LONG;
        else auxY = Y.DOUBLE;
        if (auxX != 0 && auxY != 0){
            if (X.type == 1) push_LONG(s,auxY);
            else push_DOUBLE(s,auxY);
        }
        else push_LONG(s,0);
    }

    void shortcutou(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        double auxX;
        double auxY;
        if (X.type == 1) auxX = X.LONG;
        else auxX = X.DOUBLE;
        if (Y.type == 1) auxY = Y.LONG;
        else auxY = Y.DOUBLE;
        if (auxX == 0 && auxY == 0){
            push_LONG(s,0);
        }
        else if (auxX != 0){
            if (X.type == 1) push_LONG(s, auxX);
            else push_DOUBLE(s, auxX);
        }
        else {
            if (Y.type == 1) push_LONG(s, auxY);
            else push_DOUBLE(s, auxY);
        }
    }

    void menordosdois(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        double auxX;
        double auxY;
        if (X.type == 1) auxX = X.LONG;
        else auxX = X.DOUBLE;
        if (Y.type == 1) auxY = Y.LONG;
        else auxY = Y.DOUBLE;
        if (auxX <= auxY){
            if (X.type == 1) push_LONG(s, auxX);
            else push_DOUBLE(s, auxX);
        }
        else {
            if (Y.type == 1) push_LONG(s, auxY);
            else push_DOUBLE(s, auxY);
        }
    }

    void maiordosdois(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        double auxX;
        double auxY;
        if (X.type == 1) auxX = X.LONG;
        else auxX = X.DOUBLE;
        if (Y.type == 1) auxY = Y.LONG;
        else auxY = Y.DOUBLE;
        if (auxX >= auxY){
            if (X.type == 1) push_LONG(s, auxX);
            else push_DOUBLE(s, auxX);
        }
        else {
            if (Y.type == 1) push_LONG(s, auxY);
            else push_DOUBLE(s, auxY);
        }
    }

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "l".
 * @returns Apenas lê a linha indicada.
 */
    
void lerlinha(STACK *s, char* x){
    assert (fgets(x, 10240, stdin) != NULL);
    push_STRING(s, x);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "i".
 * @returns Converter o topo da stack num inteiro.
 */

void converteinteiro(STACK *s, char *sobra){
    DATA X = pop(s);
    int Y;
    if (X.type == 4) Y = X.CHAR;
    else if (X.type == 8) Y = strtol(X.STRING, &sobra, 10);
    else if (X.type == 1) Y = X.LONG;
    else Y = X.DOUBLE;
    push_LONG(s, Y);
}

/**
 * @param s - Stack
 * \brief   Aqui verificamos para quando a string tiver o caractér "f".
 * @returns Converter o topo da stack num double.
 */

void convertedouble(STACK *s, char *sobra){
    DATA X = pop(s);
    float Y;
    if (X.type == 4) Y = X.CHAR;
    else if (X.type == 8) Y = strtof(X.STRING, &sobra);
    else if (X.type == 1) Y = X.LONG;
    else Y = X.DOUBLE;
    push_DOUBLE(s, Y);
}


void ifthenelse(STACK *s){

    DATA Z = pop(s);
    DATA Y = pop(s);
    DATA X = pop(s);
    double auxX, auxY, auxZ;
    if (X.type == 1) auxX = X.LONG;
    else auxX = X.DOUBLE;
    if (Y.type == 1) auxY = Y.LONG;
    else auxY = Y.DOUBLE;
    if (Z.type == 1) auxZ = Z.LONG;
    else auxZ = Z.DOUBLE;
    if (auxX == auxY) {
        if (X.type == 1) push_LONG(s, auxX);
        else push_DOUBLE(s, auxX);
        if (auxX != 0) {
            if (Y.type == 1) push_LONG(s, auxY);
            else push_DOUBLE(s, auxY);
        } else {
            if (Z.type == 1) push_LONG(s, auxZ);
            else push_DOUBLE(s, auxZ);
        }
    }
}