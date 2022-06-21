#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 1000

    /*** ESTADOS FINAIS
        state 2, 4 -> ID
        state 3 -> IF
        state 5, 9, 13 -> ERROR
        state 6, 8 -> REAL
        state 7 -> NUM
        state 11 -> COMMENT
        state 12 -> BLANK SPACE
        state 13 -> ERROR
        ***/
 

        /*Identificadores de token
        1 - (a-e g-h j-z)
        2 - (0-9)
        3 - (f)
        4 - (i)
        5 - (-)
        6 - (.)
        7 - (\n)
        8 - (blank space)
        9 - error

        */

void avaliaToken(int token, int state){
    if(state == 2 || state == 4 || state == 3 || state == 5 || state == 9 || state == 13 || state == 6 || state == 8 || state == 7 || state == 11 || state == 12 || state == 13){
        switch (token)
        {
            case 1:
            if(state == 2 || state == 4){
                printf(" ID\n");
            }
                break;

            case 2:
            if(state == 4){
                printf(" ID\n");
            }
            else if(state == 7){
                printf(" NUM\n");
            }
            else if(state == 6 || state == 8){
                printf(" REAL\n");
            }
                break;

            case 3:
            if(state == 3){
                printf(" IF\n");
            }
            else if(state == 4){
                printf(" ID\n");
            }
                break;

            case 4:
            if(state == 2 || state == 4){
                printf(" ID\n");
            }

            case 5:
            if(state == 9){
                printf(" ERROR\n");
            }
                break;

            case 6:
            if(state == 5){
                printf(" ERROR\n");
            }
            else if(state == 8){
                printf(" REAL\n");
            }
                break;

            case 7:
            if(state == 11){
                printf(" COMMENT\n");
            }
                break;

            case 8:
            if(state == 12){
                printf("WHITE SPACE\n");
            }
                break;
            
            case 9:
            if(state == 13){
                printf(" ERROR\n");
            }
            break;
        }
    }
   
}

int main(int argc, char *argv[]){
    int edges [][39] = {/*  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  y  z  -  . \n ' ' */
    /*state 0*/        {    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 1*/        {    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 9, 5, 11, 12},
    /*state 2*/        {    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0},
    /*state 3*/        {    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0},
    /*state 4*/        {    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0},
    /*state 5*/        {    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 6*/        {    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 7*/        {    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0},
    /*state 8*/        {    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 9*/        {    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0},
    /*state 10*/       {    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 11, 0},
    /*state 11*/       {    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /*state 12*/       {    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12},
    /*state 13*/       {    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
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
        int ponteiroInicio = 0;
        int ponteiroFinal = 0;
        int i, j;

        printf("\nSaida:");

        /*** ESTADOS FINAIS
        state 2, 4 -> ID
        state 3 -> IF
        state 5, 9, 13 -> ERROR
        state 6, 8 -> REAL
        state 7 -> NUM
        state 11 -> COMMENT
        state 12 -> BLANK SPACE
        ***/
 

        /*Identificadores de token
        1 - (a-e g-h j-z)
        2 - (0-9)
        3 - (f)
        4 - (i)
        5 - (-)
        6 - (.)
        7 - (\n)
        8 - (blank space)
        9 - error

        */

        int tokentype = 0;

         for (i = 0; i < totalCaracteres; i++){
            char c = input[i];

                if (c == 'a'||c == 'b'||c == 'c'||c == 'd'||c == 'e'||c == 'g'||c == 'h'||c == 'j'||c == 'k'||c == 'l'||c == 'm'||c == 'n'||c == 'o'||c == 'p'||c == 'q'||c == 'r'||c == 's'||c == 'u'||c == 'v'||c == 'w'||c == 'y'||c == 'z'){
                    if(edges[estadoAtual][12] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][12];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 1;
                    }
                    else if(edges[estadoAtual][12] == 0){
                        avaliaToken(tokentype, ultimoEstadoFinal);
                            if(tokentype != 1){
                                printf("\n");
                            }
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][12];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 1;
                    }
                }

                else if (c == '0'||c == '1'||c == '2'||c == '3'||c == '4'||c == '5'||c == '6'||c == '7'||c == '8'||c == '9'){
                     if(edges[estadoAtual][0] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][0];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 2;
                    }
                    else if(edges[estadoAtual][0] == 0){
                        avaliaToken(tokentype, ultimoEstadoFinal);
                            if(tokentype != 2){
                                printf("\n");
                            }
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][0];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 2;
                    }
                }
       
                else if (c == 'f'){
                     if(edges[estadoAtual][15] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][15];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 3;
                    }
                    else if(edges[estadoAtual][15] == 0){
                        avaliaToken(tokentype, ultimoEstadoFinal);
                            if(tokentype != 3){
                                if(tokentype == 1 || tokentype == 4){

                                }
                                else{
                                    printf("\n");
                                }
                            }
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][15];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 3;
                    }
                }

               else if (c == 'i'){
                     if(edges[estadoAtual][18] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][18];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 4;
                    }
                    else if(edges[estadoAtual][18] == 0){
                        avaliaToken(tokentype, ultimoEstadoFinal);
                          if(tokentype != 4){
                                if(tokentype == 1){

                                }
                                else{
                                    printf("\n");
                                }
                            }
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][18];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 4;
                    }
                }

                else if (c == '-'){
                     if(edges[estadoAtual][35] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][35];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 5;
                    }
                    else if(edges[estadoAtual][35] == 0){
                        avaliaToken(tokentype, ultimoEstadoFinal);
                            if(tokentype != 5){
                                printf("\n");
                            }
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][35];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 5;
                    }
                }

                else if (c == '.'){
                     if(edges[estadoAtual][36] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][36];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 6;
                    }
                    else if(edges[estadoAtual][36] == 0){
                        avaliaToken(tokentype, ultimoEstadoFinal);
                            if(tokentype != 6){
                                printf("\n");
                            }
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][36];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 6;
                    }
                }

                else if (c == '\n'){
                     if(edges[estadoAtual][37] != 0){
                        printf("%c", c);
                        estadoAtual = edges[estadoAtual][37];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 7;
                    }
                    else if(edges[estadoAtual][37] == 0){
                        avaliaToken(tokentype, ultimoEstadoFinal);
                            if(tokentype != 7){
                                printf("\n");
                            }
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][37];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        printf("%c", c);
                        tokentype = 7;
                    }
                }

                 else if (c == ' '){
                     if(edges[estadoAtual][38] != 0){
                        estadoAtual = edges[estadoAtual][38];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 8;
                    }
                    else if(edges[estadoAtual][38] == 0){
                        avaliaToken(tokentype, ultimoEstadoFinal);
                            if(tokentype != 8){
                                printf("\n");
                            }
                        ultimoEstadoFinal = 0;
                        estadoAtual = 1;
                        estadoAtual = edges[estadoAtual][38];
                        if (estadoAtual == 2 || estadoAtual == 4 || estadoAtual == 3 || estadoAtual == 5 || estadoAtual == 9 || estadoAtual == 13 || estadoAtual == 6 || estadoAtual == 8 || estadoAtual == 7 || estadoAtual == 11 || estadoAtual == 12){
                            ultimoEstadoFinal = estadoAtual;
                        }
                        tokentype = 8;
                    }
                }

                else{
                    if(tokentype != 9){
                        avaliaToken(tokentype, ultimoEstadoFinal);
                        printf("\n");
                        ultimoEstadoFinal = 13;
                        estadoAtual = 13;
                        printf("%c", c);
                        tokentype = 9;
                    }
                    else{
                        printf("%c", c);
                        estadoAtual = 13;
                        ultimoEstadoFinal = 13;
                        tokentype = 9;
                    }
                }
         }

       return 0;
} 