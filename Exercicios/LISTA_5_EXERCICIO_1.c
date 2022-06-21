#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 1000

int main(int argc, char *argv[]){

    int edges[][37] = {/* 0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  y  z  +  - */
    /*state 0*/       {   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 1*/       {   5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4},
    /*state 2*/       {   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0},
    /*state 3*/       {   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 4*/       {   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 5*/       {   5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 6*/       {   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7},
    /*state 7*/       {   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 8*/       {   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    char entrada[1000];
    char input[MAXSIZE];
    int totalCaracteres = 0; 
    

        printf("Insira a string a ser analisada:");
        
        while (fgets(entrada, 1000, stdin) != NULL){ /*fgets retorna NULL ao receber EOF como entrada*/
        int i, j = 0; 
            for(i = totalCaracteres; i < (strlen(entrada) + totalCaracteres); i++){
                if(j < strlen(entrada)){ /*j é um contador para a string atual e insere os caracteres na string de input a partir do ultimo inserido*/
                    input[i] = entrada[j];
                    j++;
                }
            }
            totalCaracteres += strlen(entrada);
            printf("\n%s", entrada);
        }
         printf("\nEntrada:\n%s", input);

        int ultimoEstadoFinal = 0; 
        int estadoAtual = 1; 
        int i, j;

        /*Identificadores de token
        1 - (a-d f-z)
        2 - (0-9)
        3 - (e)
        4 - (+)
        5 - (-)
        6 - ERROR;
        */
        int tokentype = 0;

        printf("\nSaida:");
         for (i = 0; i < totalCaracteres; i++){
            char c = input[i];

                if (c == 'a'||c == 'b'||c == 'c'||c == 'd'||c == 'f'||c == 'g'||c == 'h'||c == 'i'||c == 'j'||c == 'k'||c == 'l'||c == 'm'||c == 'n'||c == 'o'||c == 'p'||c == 'q'||c == 'r'||c == 's'||c == 'u'||c == 'v'||c == 'w'||c == 'y'||c == 'z'){
                    if(tokentype != 1){
                        printf("\n");
                    }
                    if(edges[estadoAtual][12] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][12];
                        if (estadoAtual == 2||3||4||5||8){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 1;
                    }
                    else if(edges[estadoAtual][12] == 0){
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][12];
                        if (estadoAtual == 2||3||4||5||8){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 1;
                    }
                }

                else if (c == 'e'){
                    if(tokentype != 3){
                        printf("\n");
                    }
                     if(edges[estadoAtual][14] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][14];
                        if (estadoAtual == 2||3||4||5||8){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 3;
                    }
                    else if(edges[estadoAtual][14] == 0){
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][14];
                        if (estadoAtual == 2||3||4||5||8){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 3;
                    }
                }

                else if (c == '0'||c == '1'||c == '2'||c == '3'||c == '4'||c == '5'||c == '6'||c == '7'||c == '8'||c == '9'){
                    if(tokentype != 2){
                        printf("\n");
                    }
                     if(edges[estadoAtual][0] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][0];
                        if (estadoAtual == 2||3||4||5||8){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 2;
                    }
                    else if(edges[estadoAtual][0] == 0){
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][0];
                        if (estadoAtual == 2||3||4||5||8){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 2;
                    }
                }

                else if (c == '+'){
                    if(tokentype != 4){
                        printf("\n");
                    }
                     if(edges[estadoAtual][35] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][35];
                        if (estadoAtual == 2||3||4||5||8){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 4;
                    }
                    else if(edges[estadoAtual][35] == 0){
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][35];
                        if (estadoAtual == 2||3||4||5||8){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 4;
                    }
                }

                else if (c == '-'){
                    if(tokentype != 5){
                        printf("\n");
                    }
                     if(edges[estadoAtual][36] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][36];
                        if (estadoAtual == 2||3||4||5||8){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 5;
                    }
                    else if(edges[estadoAtual][36] == 0){
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][36];
                        if (estadoAtual == 2||3||4||5||8){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 5;
                    }
                }

                else if (c == '\n'){
                    printf("\n");
                }

                else{
                    printf("\nERROR");
                    tokentype = 6;
                }
         }


    return 0;
}