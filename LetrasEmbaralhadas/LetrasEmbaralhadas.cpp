//
//  main.cpp
//  LetrasEmbaralhadas
//
//  Created by Gabriel A. Dragoni on 3/15/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#include <iostream>                             /*biblioteca cout e cin*/
#include <cstring>                              /*biblioteca para string*/
#include <stdio.h>                              /* printf, NULL */
#include <stdlib.h>                             /* srand, rand */
#include <time.h>                               /* time */

//macro para flexibilidade do codigo//
#define QTD_DE_PALAVRAS 5                       /* Maximo de quantidade de palavras cadastradas no jogo (20) */

using namespace std;

//variaveis publicas da classe//
char matrizDePalavras[QTD_DE_PALAVRAS+1][16];     /*matriz com QUANTIDADEDEPALAVRASx15 caracteres usaveis*/
int  palavrasUsadas[QTD_DE_PALAVRAS];             /*vetor de inteiros para guardar quais indices de palavras ja foram usadas*/

//metodos//
void   carregarMatrizComPalavras();               /*metodo para carregar a matriz com as palavras aleatórias*/
void   mostrarPalavra(string palavraEmbaralhada); /*mostra (cout) palavra com design definido*/
string palavraNoIndiceDaMatriz(int indice);       /*Recupera palavra na matriz com o indice passado como parametro*/
string palavraEmbaralhada(string palavra);        /*Embaralha a palavra passada como parametro*/
string palavraMaiuscula(string palavra);          /*Passa todas as letras da palavra para maiusculo*/
string PalavraAleatoria();                        /*Recupera uma palavra aleatoria*/
bool   testePalavraUsada(int indice);             /*Teste se a palavra ja foi usada*/

int main(int argc, const char * argv[]) {

    string palavra;
    string palavraDigitada;
    int pontos = 0, rodada = 0;

    srand((unsigned)time(NULL));                /*atribuir o relogio para o srand, para que ele sorteie um numero diferente a cada rand() usado*/

    carregarMatrizComPalavras();

    for (int i = 0; i < QTD_DE_PALAVRAS; i++) {

        rodada++;
        palavra = palavraNoIndiceDaMatriz(i);

        cout << "\nRodada: " << rodada << "/"<<QTD_DE_PALAVRAS<<  "\n";

        mostrarPalavra(palavraEmbaralhada(palavra));
        cout << "\n\n Qual e a palavra ?\n";

        cin >> palavraDigitada;

        palavraDigitada = palavraMaiuscula(palavraDigitada);

        if (palavraDigitada == palavra) {

            pontos++;
            cout << "\n ACERTOU !!!\n\n";
        }else{

            cout << "\n ERROU!!!\n\nPalavra Certa :\n";
            mostrarPalavra(palavraNoIndiceDaMatriz(i));
            cout << "\n";
        }

        if (i != QTD_DE_PALAVRAS-1) {

            for (int j = 0; j < 40; j++) {

                cout << "#";
            }
            cout << "\n\n";
        }else{

            cout << "\n\nPontuacao : " << pontos << " palavras certas de "<< QTD_DE_PALAVRAS << "!\n\n";
        }
    }

    return 0;
}

void carregarMatrizComPalavras(){

    string palavra;

    for (int i = 0; i < QTD_DE_PALAVRAS; i++) {

        palavra = PalavraAleatoria();

        for (int j = 0; j <= palavra.length(); j++) {

            matrizDePalavras[i][j] = palavra[j];
        }
    }
}

void mostrarPalavra(string palavraEmbaralhada){

    for (int i = 0; i < palavraEmbaralhada.length()*4; i++) {

        if (i == 0) {
            cout << "=";
        }
        cout << "=";
    }
    cout << "\n";
    for (int i = 0; i < palavraEmbaralhada.length(); i++) {

        if (i == 0) {

            cout << "| ";
        }

        cout << palavraEmbaralhada[i] << " | ";
    }
    cout << "\n";
    for (int i = 0; i < palavraEmbaralhada.length()*4; i++) {

        if (i == 0) {
            cout << "=";
        }
        cout << "=";
    }
}

string palavraNoIndiceDaMatriz(int indice){

    string palavraNoIndice;

    for (int i = 0; i < 15; i++) {

        if (matrizDePalavras[indice][i] != '\0') {

            palavraNoIndice += matrizDePalavras[indice][i];
        }else{
            break;
        }
    }

    return palavraNoIndice;
}

string palavraMaiuscula(string palavra){

    string palavraMaiuscula;

    for (int i = 0; i < palavra.length(); i ++) {

        palavraMaiuscula += toupper(palavra[i]);
    }

    return palavraMaiuscula;
}

string palavraEmbaralhada(string palavra){

    string palavraEmbaralhada;

    for (int i = 0; i < palavra.length(); i ++) {

        int indice;

        do{
            indice = rand() % palavra.length();

        }while(palavra[indice] == '\0');

        palavraEmbaralhada += palavra[indice];
        palavra[indice] = '\0';
    }

    return palavraEmbaralhada;
}

string PalavraAleatoria(){

    string palavra;
    int indice;
    do{

        indice = rand() % 20 +1;

    }while(testePalavraUsada(indice));

    switch (indice) {
        case 1:
            palavra = "CELULAR";
            break;
        case 2:
            palavra = "ARVORE";
            break;
        case 3:
            palavra = "TORPEDO";
            break;
        case 4:
            palavra = "LIVRO";
            break;
        case 5:
            palavra = "REVISTA";
            break;
        case 6:
            palavra = "TELEVISAO";
            break;
        case 7:
            palavra = "REMEDIO";
            break;
        case 8:
            palavra = "BANHEIRO";
            break;
        case 9:
            palavra = "COMPUTADOR";
            break;
        case 10:
            palavra = "SORVETE";
            break;
        case 11:
            palavra = "PREGUICA";
            break;
        case 12:
            palavra = "CAVALO";
            break;
        case 13:
            palavra = "LAGARTO";
            break;
        case 14:
            palavra = "CACHORRO";
            break;
        case 15:
            palavra = "CARRO";
            break;
        case 16:
            palavra = "ELEVADOR";
            break;
        case 17:
            palavra = "ESCADA";
            break;
        case 18:
            palavra = "PREDIO";
            break;
        case 19:
            palavra = "CADERNO";
            break;
        case 20:
            palavra = "JORNAL";
    }

    return palavra;
}

bool testePalavraUsada(int indice){

    for (int i = 0; i < QTD_DE_PALAVRAS; i ++) {

        if (palavrasUsadas[i] == indice) {

            return true;
        }else if (palavrasUsadas[i] == 0){

            palavrasUsadas[i] = indice;
            break;
        }
    }


    return false;
}
