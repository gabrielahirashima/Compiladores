#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 1000



    /*** ESTADOS FINAIS
        state 3 -> HE/ELE
        state 6 -> SHE/ELA
        state 8 -> HIS/DELE
        state 10 -> HERS/DELA
        state 13 -> CAT/GATO
        state 14 -> CAR/CARROS
        state 15 -> CATS/GATOS
        state 16 -> CARS/CARROS
        state 17 -> MAIS
        state 18 -> MENOS
        state 19 -> INTEIRO
        state 22 -> REAL
    ***/
 

        /*Identificadores de char
        0 - (0-9);
        1 - a;
        2 - c;
        3 - e;
        4 - h; 
        5 - i;
        6 - r;
        7 - s; 
        8 - t; 
        9 - +;
        10 - -;
        11 - ERRO;
        */

void avaliaToken(int token, int state, char entrada[], int inicio, int fim){
    if(state == 3 || state == 6 || state == 8 || state == 10 || state == 13 || state == 14 || state == 15 || state == 16 || state == 17 || state == 18 || state == 19 || state == 22){
        switch (token){
            case 0:
            if(state == 19){
                printf("INTEIRO ");
                for(int i = inicio; i < fim + 1; i++){
                    printf("%c", entrada[i]);
                }
                printf("\n");
            }
            else if(state == 22){
                printf( "REAL ");
                for(int i = inicio; i < fim + 1; i++){
                    printf("%c", entrada[i]);
                }
                printf("\n");
            }
                break;

            case 3:
            if(state == 3){
                printf( "ELE\n");
            }
            else if(state == 6){
                printf( "ELA\n");
            }
                break;

            case 6:
            if(state == 14){
                printf( "CARRO\n");
            }
                break;

            case 7:
            if(state == 10){
                printf( "DELA\n");
            }
            else if(state == 8){
                printf( "DELE\n");
            }
            else if(state == 15){
                printf( "GATOS\n");
            }
            else if(state == 16){
                printf( "CARROS\n");
            }
                break;
            
            case 8:
            if(state == 13){
                printf( "GATO\n");
            }
                break;

            case 9:
            if(state == 17){
                printf( "MAIS\n");
            }
                break;
            
            case 10:
            if(state == 18){
                printf( "MENOS\n");
            }
                break;
        }
    }

    else if(state == 0){
        if(token == 11){
            printf( "ERRO\n");
        }
    }
   
}

int main(int argc, char *argv[]){

    int edges [][20] = {  /*  0   1   2   3   4   5   6   7   8   9   a   c   e   h   i   r   s   t   +   -*/
    /*state 0*/        {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 1*/        {     19, 19, 19, 19, 19, 19, 19, 19, 19, 19,  0, 11,  0,  2,  0,  0,  4,  0, 17, 18},
    /*state 2*/        {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  7,  0,  0,  0,  0,  0},
    /*state 3*/        {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  0},
    /*state 4*/        {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  0,  0,  0,  0,  0,  0},
    /*state 5*/        {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0},
    /*state 6*/        {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 7*/        {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,  0,  0,  0},
    /*state 8*/        {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 9*/        {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10,  0,  0,  0},
    /*state 10*/       {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 11*/       {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 12*/       {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  0, 13,  0,  0},
    /*state 13*/       {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15,  0,  0,  0},
    /*state 14*/       {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16,  0,  0,  0},
    /*state 15*/       {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 16*/       {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 17*/       {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 18*/       {      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 19*/       {     19, 19, 19, 19, 19, 19, 19, 19, 19, 19,  0,  0, 20,  0,  0,  0,  0,  0,  0,  0},
    /*state 20*/       {     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,  0,  0,  0,  0,  0,  0,  0,  0, 21, 21},
    /*state 21*/       {     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /*state 22*/       {     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    };

    char entrada[MAXSIZE];
    char c;
    int totalCaracteres = 0; 
    

        printf("Insira a string a ser analisada:");

        while(fscanf(stdin, "%c", &c) != EOF){
            entrada[totalCaracteres] = c;
            totalCaracteres += 1;
        }
        
         printf("\nEntrada:\n%s", entrada);

            int ultimoEstadoFinal = 0;
            int estadoAtual = 1; 

            int ponteiroInicio = 0; /*Indica o inicio de um token*/
            int ponteiroFinal = 0; /*Indica até onde o token foi reconhecido*/
            int ponteiroAtual = 0; /*Indica o caracter atualmente sendo reconhecido*/
            int ponteiroUltimoEstadoFinal = 0; /*Armazena onde na sentenca o ultimo estado final foi encontrado*/
            int tokenAtual = 0; /*identificador do char*/
            int tokenUltimoFinal = 0; /*identificador do char*/

            printf("\nSaida:\n");

            while(ponteiroInicio != (totalCaracteres - 1)){
                 char c = entrada[ponteiroAtual];
                 //printf("Ultimo estado final:%d, estado atual: %d, ponteiro atual: %d, ponteiro inicial: %d\n", ultimoEstadoFinal, estadoAtual, ponteiroAtual, ponteiroInicio);
                    switch(c){}
                    if (c == 'a'){
                        if(edges[estadoAtual][10] != 0){
                            estadoAtual = edges[estadoAtual][10];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 1;
                        }
                        else if(edges[estadoAtual][10] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }
                    }

                else if (c == '0'||c == '1'||c == '2'||c == '3'||c == '4'||c == '5'||c == '6'||c == '7'||c == '8'||c == '9'){
                        if(edges[estadoAtual][0] != 0){
                            estadoAtual = edges[estadoAtual][0];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 0;
                                if(estadoAtual == 19){
                                    ultimoEstadoFinal = 19;
                                    tokenUltimoFinal = 0;
                                    ponteiroUltimoEstadoFinal = ponteiroFinal;
                                }
                                else if(estadoAtual == 22){
                                    ultimoEstadoFinal = 22;
                                    tokenUltimoFinal = 0;
                                    ponteiroUltimoEstadoFinal = ponteiroFinal;
                                }
                        }
                        else if(edges[estadoAtual][0] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }       
                }
       
                else if (c == 'c'){
                        if(edges[estadoAtual][11] != 0){
                            estadoAtual = edges[estadoAtual][11];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 2;
                        }
                        else if(edges[estadoAtual][11] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }        
                }

               else if (c == 'e'){
                        if(edges[estadoAtual][12] != 0){
                            estadoAtual = edges[estadoAtual][12];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 3;
                                if(estadoAtual == 3){
                                    ultimoEstadoFinal = 3;
                                    tokenUltimoFinal = 3;
                                    ponteiroUltimoEstadoFinal = ponteiroFinal;
                                }
                                else if(estadoAtual == 6){
                                    ultimoEstadoFinal = 6;
                                    tokenUltimoFinal = 3;
                                    ponteiroUltimoEstadoFinal = ponteiroFinal;
                                }
                        }
                        else if(edges[estadoAtual][12] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                               
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }
                }

                else if (c == 'h'){
                        if(edges[estadoAtual][13] != 0){
                            estadoAtual = edges[estadoAtual][13];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 4;
                        }
                        else if(edges[estadoAtual][13] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }
                }

                else if (c == 'i'){
                        if(edges[estadoAtual][14] != 0){
                            estadoAtual = edges[estadoAtual][14];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 5;
                        }
                        else if(edges[estadoAtual][14] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }
                }

                 else if (c == 'r'){
                        if(edges[estadoAtual][15] != 0){
                            estadoAtual = edges[estadoAtual][15];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 5;
                            if(estadoAtual == 14){
                                ultimoEstadoFinal = 14;
                                tokenUltimoFinal = 6;
                                ponteiroUltimoEstadoFinal = ponteiroFinal;
                            }
                        }
                        else if(edges[estadoAtual][15] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }
                }

                 else if (c == 's'){
                        if(edges[estadoAtual][16] != 0){
                            estadoAtual = edges[estadoAtual][16];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 7;
                            if(estadoAtual == 10){
                                ultimoEstadoFinal = 10;
                                tokenUltimoFinal = 7;
                                ponteiroUltimoEstadoFinal = ponteiroFinal;
                            }
                            else if(estadoAtual == 8){
                                ultimoEstadoFinal = 8;
                                tokenUltimoFinal = 7;
                                ponteiroUltimoEstadoFinal = ponteiroFinal;
                            }
                            else if(estadoAtual == 15){
                                ultimoEstadoFinal = 15;
                                tokenUltimoFinal = 7;
                                ponteiroUltimoEstadoFinal = ponteiroFinal;
                            }
                            else if(estadoAtual == 16){
                                ultimoEstadoFinal = 16;
                                tokenUltimoFinal = 7;
                                ponteiroUltimoEstadoFinal = ponteiroFinal;
                            }
                        }
                        else if(edges[estadoAtual][16] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }
                }

                 else if (c == 't'){
                        if(edges[estadoAtual][17] != 0){
                            estadoAtual = edges[estadoAtual][17];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 8;
                                if(estadoAtual == 13){
                                    ultimoEstadoFinal = 13;
                                    tokenUltimoFinal = 8;
                                    ponteiroUltimoEstadoFinal = ponteiroFinal;
                                }
                        }
                        else if(edges[estadoAtual][17] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }
                }

                 else if (c == '+'){
                        if(edges[estadoAtual][18] != 0){
                            estadoAtual = edges[estadoAtual][18];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 9;
                                if(estadoAtual == 17){
                                    ultimoEstadoFinal = 17;
                                    tokenUltimoFinal = 9;
                                    ponteiroUltimoEstadoFinal = ponteiroFinal;
                                }
                        }
                        else if(edges[estadoAtual][18] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }
                }

                else if (c == '-'){
                        if(edges[estadoAtual][19] != 0){
                            estadoAtual = edges[estadoAtual][19];
                            ponteiroFinal = ponteiroAtual;
                            ponteiroAtual = ponteiroAtual + 1;
                            tokenAtual = 10;
                                if(estadoAtual == 18){
                                    ultimoEstadoFinal = 17;
                                    tokenUltimoFinal = 10;
                                    ponteiroUltimoEstadoFinal = ponteiroFinal;
                                }
                        }
                        else if(edges[estadoAtual][19] == 0){
                            if(ultimoEstadoFinal == 0){
                                /*Se o ultimo estado final é igual a zero, quer dizer que é uma sentenca invalida,
                                logo, precisamos retornar ao inicio do reconhecimento*/
                                avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                                ponteiroAtual = ponteiroInicio + 1;
                                ponteiroInicio = ponteiroInicio + 1;
                                ponteiroFinal = ponteiroInicio;
                                ponteiroUltimoEstadoFinal = 0;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;
                            }
                            else{
                                /*Neste caso, deve haver pelo menos uma sentenca valida, ja que existe um estado final,
                                logo, precisamos descobrir qual é esta sentenca
                                */
                                avaliaToken(tokenUltimoFinal, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroUltimoEstadoFinal);
                                ponteiroInicio = ponteiroUltimoEstadoFinal + 1;
                                ponteiroFinal = ponteiroUltimoEstadoFinal + 1;
                                ponteiroAtual = ponteiroInicio;
                                tokenAtual = 0;
                                tokenUltimoFinal = 0;
                                ultimoEstadoFinal = 0;
                                estadoAtual = 1;

                            }
                        }
                }

                else if (c == ' '){
                    ponteiroAtual = ponteiroAtual + 1;
                }

                else if (c == '\n'){
                    ponteiroAtual = ponteiroAtual + 1;
                }

                else if (c == EOF){
                    if(ultimoEstadoFinal != 0){
                        avaliaToken(tokenUltimoFinal, ultimoEstadoFinal , entrada, ponteiroInicio, ponteiroFinal);
                    }
                    break;
                }
               
                else if(c !='0'||c !='1'||c !='2'||c !='3'||c !='4'||c !='5'||c !='6'||c !='7'||c !='8'||c !='9'||c !='a'||c !='c'||c !='e'||c !='h'||c !='i'||c !='r'||c !='s'||c !='t'||c !='+'||c !='-'||c != ' '|| c!= '\n'|| c!= EOF){
                        if(ultimoEstadoFinal != 0){
                            avaliaToken(tokenUltimoFinal, ultimoEstadoFinal , entrada, ponteiroInicio, ponteiroFinal);
                        }
                        avaliaToken(11, ultimoEstadoFinal, entrada, ponteiroInicio, ponteiroFinal);
                        ponteiroInicio = ponteiroAtual + 1;
                        ponteiroFinal = ponteiroAtual + 1;
                        ponteiroUltimoEstadoFinal = ponteiroFinal;
                        ponteiroAtual += 1;
                        tokenAtual = 11;
                        tokenUltimoFinal = 11;
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                }

            }

}