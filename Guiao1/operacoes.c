#include "stack.h"
#include <math.h>


    void soma(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        double r;
        if (X.type==1) r = X.LONG; else r = X.DOUBLE;
        if (Y.type==1) r += Y.LONG; else r += Y.DOUBLE;
        if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
        else push_LONG(s,r);
    }

    void diferenca(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        double r;
        if (X.type==1) r = X.LONG; else r = X.DOUBLE;
        if (Y.type==1) r -= Y.LONG; else r -= Y.DOUBLE;
        if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
        else push_LONG(s,r);
    }

    void multiplication(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        double r;
        if (X.type==1) r = X.LONG; else r = X.DOUBLE;
        if (Y.type==1) r *= Y.LONG; else r *= Y.DOUBLE;
        if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
        else push_LONG(s,r);
    }

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

    void decrementar(STACK *s){
         DATA X = pop(s);
         if (X.type==2) push_DOUBLE(s,(X.DOUBLE)-1);
         else if (X.type==1) push_LONG(s,(X.LONG)-1);
         else if (X.type==4) push_CHAR(s,(X.CHAR)-1);
    }

    void incrementar(STACK *s){
        DATA X = pop(s);
        if (X.type==2) push_DOUBLE(s,(X.DOUBLE)+1);
        else if (X.type==1) push_LONG(s,(X.LONG)+1);
        else if (X.type==4) push_CHAR(s,(X.CHAR)+1);
    }

    void modulo(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        long r1,r2;
        if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
        if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
        if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1%r2));
        else push_LONG(s,(r1%r2));
    }

    void exponenciacao(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        double r;
        if (X.type==1) r = X.LONG; else r = X.DOUBLE;
        if (Y.type==1) r = pow (r,Y.LONG); else r = pow (r,Y.DOUBLE);
        if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,r);
        else push_LONG(s,r);
    }

    void eee(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        long r1,r2;
        if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
        if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
        if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1&r2));
        else push_LONG(s,(r1&r2));
    }

    void ouou(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        long r1,r2;
        if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
        if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
        if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1|r2));
    }

    void xoe(STACK *s){
        DATA Y = pop(s);
        DATA X = pop(s);
        long r1,r2;
        if (X.type==1) r1 = X.LONG; else r1 = X.DOUBLE;
        if (Y.type==1) r2 = Y.LONG; else r2 = Y.DOUBLE;
        if ((X.type==2) || (Y.type==2)) push_DOUBLE(s,(r1^r2));
    }

    void not(STACK *s){
        long X = pop_LONG(s);
        push_LONG(s, ~X);
    }

    void duplicar(STACK *s){
        DATA X = pop(s);
        push(s,X);
        push(s,X);
    }


    void darpop(STACK *s){
        pop(s);
    }

    void convertcaractere(STACK *s){
        pop(s);
    }

    void trocardois(STACK *s){
        DATA X = pop(s);
        DATA Y = pop(s);
        push(s,X);
        push(s,Y);
    }

    void rodartres(STACK *s){
        DATA Z = pop(s);
        DATA Y = pop(s);
        DATA X = pop(s);
        push(s,Y);
        push(s,Z);
        push(s,X);
    }

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
            if (X.type == 1) push_LONG(s,auxX);
            else push_DOUBLE(s,auxX);
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