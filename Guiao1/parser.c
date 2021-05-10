/**
 * @file As funções correspondentes ao parser.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"
#include "operacoes.h"

/**
 *
 * 
 * @param line 213 - Aqui verificamos para quando a string tiver o caractér "\\".
 * @returns Trocar os dois primeiros elementos do topo da stack.
 * 
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

    STACK *s = create_stack ();

    
    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra;
        char *val_i = token;
        long val_l = strtol(token, &sobra,10);
        double val_d = strtod(token,&sobra);
        if (strlen(sobra) == 0) {
            int i = 0, flag = 0;
            while (val_i[i++] != '\0') {
                if (val_i[i] == '.') {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) push_DOUBLE(s, val_d);
            else push_LONG(s, val_l);
        }
        switch (*token)
        {
            case '+':
                soma(s);
                break;
            case '-':
                diferenca(s);
                break;
            case '*':
                multiplication(s);
                break;
            case '/':
                dividir(s);
                break;
            case '(':
                decrementar(s);
                break;
            case ')':
                incrementar(s);
                break;
            case '%':
                modulo(s);
                break;
            case '#':
                exponenciacao(s);
                break;
            case '&':
                eee(s);
                break;
            case '|':
                ouou(s);
                break;
            case '^':
                xoe(s);
                break;
            case '~':
                not(s);
                break;
            case '_':
                duplicar(s);
                break;
            case ';':
                darpop(s);
                break;
            case 'c':
                convertcaractere(s);
                break;
            case '\\':
                trocardois(s);
                break;
            case '@':
                rodartres(s);
                break;
            case '$':
                copiarelemento(s);
                break;
            case '=':
                serigual(s);
                break;
            case '<':
                sermenor(s);
                break;
            case '>':
                sermaior(s);
                break;
            case '!':
                nope(s);
                break;
            case '?':
                ifthenelse(s);
                break;
            case 'l':
                lerlinha(s,coca);
                break;
            case 'i':
                converteinteiro(s, sobra);
                break;
            case 'f':
                convertedouble(s, sobra);
                break;
        }
        if (strcmp(token, "e&") == 0) shortcute(s);
        else if (strcmp(token, "e|") == 0) shortcutou(s);
        else if (strcmp(token, "e<") == 0) menordosdois(s);
        else if (strcmp(token, "e>") == 0) maiordosdois(s);
        else if (strcmp(token, "A") == 0) {
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
            DATA X = pop(s);
            push(s,X);
            A = X;
        } else if (strcmp(token, ":B") == 0) {
            DATA X = pop(s);
            push(s,X);
            B = X;
        } else if (strcmp(token, ":C") == 0) {
            DATA X = pop(s);
            push(s,X);
            C = X;
        } else if (strcmp(token, ":D") == 0) {
            DATA X = pop(s);
            push(s,X);
            D = X;
        } else if (strcmp(token, ":E") == 0) {
            DATA X = pop(s);
            push(s,X);
            E = X;
        }   else if (strcmp(token, ":F") == 0) {
            DATA X = pop(s);
            push(s,X);
            F = X;
        } else if (strcmp(token, ":N") == 0) {
            DATA X = pop(s);
            push(s,X);
            N = X;
        } else if (strcmp(token, ":S") == 0) {
            DATA X = pop(s);
            push(s,X);
            S = X;
        } else if (strcmp(token, ":X") == 0) {
            DATA X = pop(s);
            push(s,X);
            XX = X;
        } else if (strcmp(token, ":Y") == 0) {
            DATA X = pop(s);
            push(s,X);
            YY = X;
        } else if (strcmp(token, ":Z") == 0) {
            DATA X = pop(s);
            push(s,X);
            ZZ = X;
        }

    }

    print_stack(s);
}