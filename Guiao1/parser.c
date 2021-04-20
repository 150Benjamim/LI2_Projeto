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
 * @param line 104 - Aqui verificamos para quando a string tiver o caractér "+".
 * @returns O resultado da soma de dois elementos.
 *
 * @param line 112 - Aqui verificmos para quando a string tiver o caractér "-".
 * @returns O resultado da diferença de dois elementos.
 * 
 * @param line 120 - Aqui verificamos para quando a string tiver o caractér "*".
 * @returns O resultado da multiplicação de dois elementos.
 *
 * @param line 128 - Aqui verificamos para quando a string tiver o caractér "/".
 * @returns O resultado da divisão inteira de dois elementos.
 *
 * @param line 142 - Aqui verificamos para quando a string tiver o caractér "(".
 * @returns A incrementação de um elemento.
 *
 * @param line 146 - Aqui verificamos para quando a string tiver o caractér ")".
 * @returns A decrementação de um elemento.
 *
 * @param line 150 - Aqui verificamos para quando a string tiver o caractér "%".
 * @returns O resto da divisão de dois elementos.
 *
 * @param line 158 - Aqui verificamos para quando a string tiver o caractér "#".
 * @returns O resultado do primeiro elemento elevado ao segundo elemento.
 *
 * @param line 166 - Aqui verificamos para quando a string tiver o caractér "&".
 * @returns Transforma os dois elementos em binário e devolve os bites em comum.
 *
 * @param line 174 - Aqui verificamos para quando a string tiver o caractér "|".
 * @returns Transforma os dois elementos em binário e compara os seus bites. Devolve o bit 1, exceto quando ambos os bites em comparação forem 0, neste caso devolve o bit 0.
 *
 * @param line 181 - Aqui verificamos para quando a string tiver o caractér "^".
 * @returns Transforma os dois elementos em binário e compara os seus bites. Se os bites em comparação forem diferentes, devolve o bit 1. No caso, dos bites serem iguais devolve o bit 0.
 *
 * @param line 188 - Aqui verificamos para quando a string tiver o caractér "~".
 * @returns Transforma o seu único elemento em binário e inverte os valores dos seus bites.
 * 
 * @param line 191 - Aqui verificamos para quando a string tiver o caractér "_".
 * @returns Retornar dois "push's" da stack.
 * 
 * @param line 205 - Aqui verificamos para quando a string tiver o caractér ";".
 * @returns Devolve o primeiro elemento da stack.
 * 
 * @param line 207 - Aqui verificamos para quando a string tiver o caractér "c".
 * @returns Converter o topo da stack para caractér.
 * 
 * @param line 213 - Aqui verificamos para quando a string tiver o caractér "\\".
 * @returns Trocar os dois primeiros elementos do topo da stack.
 * 
 * @param line 218 - Aqui verificamos para quando a string tiver o caractér "@".
 * @returns Rodar os 3 primeiros elementos no topo da stack.
 *
 * @param line 225 - Aqui verificamos para quando a string tiver o caractér "$".
 * @returns Copia o n-ésimo elemento para o topo da stack.
 * 
 * @param line 237 - Aqui verificamos para quando a string tiver o caractér "l".
 * @returns Apenas lê a linha indicada.
 * 
 * @param line 240 - Aqui verificamos para quando a string tiver o caractér "i".
 * @returns Converter o topo da stack num inteiro.
 * 
 * @param line 249 - Aqui verificamos para quando a string tiver o caractér "f".
 * @returns Converter o topo da stack num double.
 */

void parse(char *line) {

    char *delims = " \t\n";

    char coca[10240];

    DATA A = {1,10,0,0,0};
    DATA B = {1,11,0,0,0};
    DATA C = {1,12,0,0,0};
    DATA D = {1,13,0,0,0};
    DATA E = {1,14,0,0,0};
    DATA F = {1,15,0,0,0};
    DATA N = {4,0,0,'\n',0};
    DATA S = {4,0,0,' ',0};
    DATA XX = {1,0,0,0,0};
    DATA YY = {1,1,0,0,0};
    DATA ZZ = {1,2,0,0,0};

    STACK *s = create_stack();

    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        char *val_i = token;
        long val_l = strtol(token, &sobra,10);
        double val_d = strtod(token,&sobra);
        if (strlen(sobra) == 0){
            int i = 0, flag = 0;
            while(val_i[i++] != '\0'){
                if(val_i[i] == '.'){
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) push_DOUBLE(s,val_d);
            else push_LONG(s,val_l);
        } else if (strcmp(token, "+") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r += Y.LONG; else r += Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
            else push_LONG(s,r);
        } else if (strcmp(token, "-") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r -= Y.LONG; else r -= Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
            else push_LONG(s,r);
        } else if (strcmp(token, "*") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r *= Y.LONG; else r *= Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
            else push_LONG(s,r);
        } else if (strcmp(token, "/") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r,r1;
            long r2;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r1 = Y.LONG; else r1 = Y.DOUBLE;
            if ((X.type==1) && (Y.type==1)){
                r2 = r / r1;
                push_LONG(s,(r2));
            }
            else{
                push_DOUBLE(s,(r/r1));
            }
        } else if (strcmp(token, "(") == 0) {
            DATA X = pop(s);
            if (X.type==2) push_DOUBLE(s,(X.DOUBLE)-1);
            else if (X.type==1) push_LONG(s,(X.LONG)-1);
            else if (X.type==4) push_CHAR(s,(X.CHAR)-1);
        } else if (strcmp(token, ")") == 0) {
            DATA X = pop(s);
            if (X.type==2) push_DOUBLE(s,(X.DOUBLE)+1);
            else if (X.type==1) push_LONG(s,(X.LONG)+1);
            else if (X.type==4) push_CHAR(s,(X.CHAR)+1);
        } else if (strcmp(token, "%") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            long r1,r2;
            if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
            if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1%r2));
            else push_LONG(s,(r1%r2));
        } else if (strcmp(token, "#") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            double r;
            if (X.type==1) r = X.LONG; else r = X.DOUBLE;
            if (Y.type==1) r = pow (r,Y.LONG); else r = pow (r,Y.DOUBLE);
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
            else push_LONG(s,r);
        } else if (strcmp(token, "&") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            long r1,r2;
            if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
            if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1&r2));
            else push_LONG(s,(r1&r2));
        } else if (strcmp(token, "|") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            long r1,r2;
            if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
            if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1|r2));
        } else if (strcmp(token, "^") == 0) {
            DATA Y = pop(s);
            DATA X = pop(s);
            long r1,r2;
            if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
            if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
            if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1^r2));
        } else if (strcmp(token, "~") == 0) {
            long X = pop_LONG(s);
            push_LONG(s, ~X);
        } else if (strcmp(token, "_") == 0){
            DATA X = pop(s);
            push(s,X);
            push(s,X);
        }else if (strcmp(token, ";")== 0){
            pop(s);
        }else if (strcmp(token, "c") == 0) {
            DATA X = pop(s);
            if (X.type==1){
                char r = X.LONG;
                push_CHAR(s,r);
            }
            else push(s,X);
        }else if (strcmp(token, "\\") == 0){
            DATA X = pop(s);
            DATA Y = pop(s);
            push(s,X);
            push(s,Y);
        } else if (strcmp(token, "@") == 0) {
            DATA Z = pop(s);
            DATA Y = pop(s);
            DATA X = pop(s);
            push(s,Y);
            push(s,Z);
            push(s,X);
        } else if (strcmp(token, "$") == 0) {
            int i = 0;
            int x = pop_LONG(s);
            STACK stackAux = *s;
            while (i!=x) {
                pop(&stackAux);
                i++;
            }
            DATA A = pop(&stackAux);
            push(s,A);
        }else if (strcmp(token, "=") == 0) {
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
        } else if (strcmp(token, "<") == 0) {
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
        } else if (strcmp(token, ">") == 0) {
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
        } else if (strcmp(token, "!") == 0) {
            DATA X = pop(s);
            if (X.type == 1) {
                if (X.LONG == 0) push_LONG(s,1);
                else push_LONG(s,0);
            }
            else if (X.type == 2){
                if (X.DOUBLE == 0) push_LONG(s,1);
                else push_LONG(s,0);
            }
            else {
                float x = X.CHAR;
                if (x == 0) push_LONG(s,1);
                else push_LONG(s,0);
            }
        } else if (strcmp(token, "e&") == 0) {
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
        } else if (strcmp(token, "e|") == 0) {
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
        } else if (strcmp(token, "e<") == 0) {
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
        } else if (strcmp(token, "e>") == 0) {
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
        } else if (strcmp(token, "?") == 0) {
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
            if (auxX != 0){
                if (Y.type == 1) push_LONG(s, auxY);
                else push_DOUBLE(s, auxY);
            }
            else {
                if (Z.type == 1) push_LONG(s, auxZ);
                else push_DOUBLE(s, auxZ);
            }
        } else if (strcmp(token, "A") == 0) {
            push(s,A);
        } else if (strcmp(token, "B") == 0) {
            push(s,B);
        } else if (strcmp(token, "C") == 0) {
            push(s,C);
        } else if (strcmp(token, "D") == 0) {
            push(s,D);
        } else if (strcmp(token, "E") == 0) {
            push(s,E);
        }   else if (strcmp(token, "F") == 0) {
            push(s,F);
        } else if (strcmp(token, "N") == 0) {
            push(s,N);
        } else if (strcmp(token, "S") == 0) {
            push(s,S);
        } else if (strcmp(token, "X") == 0) {
            push(s,XX);
        } else if (strcmp(token, "Y") == 0) {
            push(s,YY);
        } else if (strcmp(token, "Z") == 0) {
            push(s,ZZ);
        } else if (strcmp(token, ":A") == 0) {
            A = pop(s);
            push(s,A);
        } else if (strcmp(token, ":B") == 0) {
            B = pop(s);
            push(s,B);
        } else if (strcmp(token, ":C") == 0) {
            C = pop(s);
            push(s,C);
        } else if (strcmp(token, ":D") == 0) {
            D = pop(s);
            push(s,D);
        } else if (strcmp(token, ":E") == 0) {
            E = pop(s);
            push(s,E);
        }   else if (strcmp(token, ":F") == 0) {
            F = pop(s);
            push(s,F);
        } else if (strcmp(token, ":N") == 0) {
            N = pop(s);
            push(s,N);
        } else if (strcmp(token, ":S") == 0) {
            S = pop(s);
            push(s,S);
        } else if (strcmp(token, ":X") == 0) {
            XX = pop(s);
            push(s,XX);
        } else if (strcmp(token, ":Y") == 0) {
            YY = pop(s);
            push(s,YY);
        } else if (strcmp(token, ":Z") == 0) {
            ZZ = pop(s);
            push(s,ZZ);
        } else if (strcmp(token, "l") == 0) {
            assert (fgets(coca, 10240, stdin) != NULL);
            push_STRING(s, coca);
        } else if (strcmp(token, "i") == 0) {
            DATA X = pop(s);
            int Y;
            if (X.type == 4) Y = X.CHAR;
            else if (X.type == 8) Y = strtol(X.STRING, &sobra, 10);
            else if (X.type == 1) Y = X.LONG;
            else Y = X.DOUBLE;
            push_LONG(s, Y);
        } else if (strcmp(token, "f") == 0) {
            DATA X = pop(s);
            float Y;
            if (X.type == 4) Y = X.CHAR;
            else if (X.type == 8) Y = strtof(X.STRING, &sobra);
            else if (X.type == 1) Y = X.LONG;
            else Y = X.DOUBLE;
            push_DOUBLE(s, Y);
        }
    }

    print_stack(s);
}