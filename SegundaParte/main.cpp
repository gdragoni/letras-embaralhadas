//
//  main.cpp
//  LetrasEmbaralhadas
//
//  Created by Gabriel A. Dragoni on 3/15/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#include "Constant.h"
#include "GeradorDePalavrasAleatorias.h"
#include "MinhaArray.h"
#include "StringAd.h"

GeradorDePalavrasAleatorias gerPalavras;
MinhaArray mArray;
StringAd mString;
Tema tema;
int qtdDePalavras;

void carregarArrayComPalavras();                    /*metodo para carregar a matriz com as palavras aleatórias*/
int  calcularPoncentagem(int *total, int *parcial); /*calcula porcentagem*/

int main(int argc, const char * argv[]) {
    string palavra;
    string palavraDigitada;
    int pontos = 0, rodada = 0;
    srand((unsigned)time(NULL));                /*atribuir o time para o srand, para que ele sorteie um numero diferente a cada rand() usado*/
    do{
        mString.escreve("Digite a quantidade de palavras (1~20):\n");
        cin >> qtdDePalavras;
        mString.escreve("\n");
    }while (qtdDePalavras < 1 || qtdDePalavras > MAX_QTD_DE_PALAVRAS);
    do{
        string temaEsc;
        mString.escreve("Digite um tema: NOME, COMIDA, VEICULO, ANIMAL:\n");
        temaEsc = mString.palavraMaiuscula(mString.leia());
        tema = temaEsc == "NOME" ? NomeProprio : temaEsc == "COMIDA" ? Comida : temaEsc == "VEICULO" ? Veiculo : temaEsc == "ANIMAL" ? Animal : erro;
        mString.escreve("\n");
    }while(tema == erro);
    carregarArrayComPalavras();
    for (int i = 0; i < qtdDePalavras; i++) {
        rodada++;
        palavra = mArray.palavraNoIndice(i);
        mArray.deletarPalavraNoIndice(i);
        mString.escreve("\nRodada: " + to_string(rodada) + "/" + to_string(qtdDePalavras) + "\n");
        mString.mostrarPalavra(mString.palavraEmbaralhada(palavra));
        mString.escreve("\n\n Qual e a palavra ?\n");
        palavraDigitada = mString.leia();
        palavraDigitada = mString.palavraMaiuscula(palavraDigitada);
        if (palavraDigitada == palavra) {
            pontos++;
            mString.escreve("\n ACERTOU !!!\n\n");
        }else{
            mString.escreve("\n ERROU!!!\n\nPalavra Certa:\n");
            mString.mostrarPalavra(palavra);
            mString.escreve("\n");
        }
        if (i != qtdDePalavras-1) {
            for (int j = 0; j < 40; j++) {
                mString.escreve("#");
            }
            mString.escreve("\n\n");
        }else{
            mString.escreve("\n\nPontuacao: " + to_string(pontos) + " palavras certas de " + to_string(qtdDePalavras) + "!\nPorcentagem de acerto: " + to_string(calcularPoncentagem(&qtdDePalavras, &pontos)) + "%");
            mString.escreve("\n\n");
            break;
        }
    }
    system("PAUSE");
    return 0;
}

void carregarArrayComPalavras(){
    string palavra;
    for (int i = 0; i < qtdDePalavras; i++) {
        mArray.adicionarPalavra(gerPalavras.palavraAleatoria(tema));
    }
}

int calcularPoncentagem(int *total, int *parcial){
    float porcent = (float)*parcial/(float)*total * 100;
    return (int)porcent;
}