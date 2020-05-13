//
//  GeradorDePalavrasAleatorias.cpp
//  PalavrasEmbaralhadas
//
//  Created by Gabriel A. Dragoni on 5/11/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#include "GeradorDePalavrasAleatorias.h"

string sortearPalavra(Tema tema);           /*sorteia uma palavra por tema*/
string nomeProprio(int indice);             /*retorna um nome por indice*/
string animal(int indice);                  /*retorna um animal por indice*/
string veiculo(int indice);                 /*retorna um veiculo por indice*/
string comida(int indice);                  /*retorna uma comida por indice*/
bool testePalavraUsada(int indice);         /*teste se palavra ja foi usada*/

int  palavrasUsadas[MAX_QTD_DE_PALAVRAS];             /*vetor de inteiros para guardar quais indices de palavras ja foram usadas*/

string GeradorDePalavrasAleatorias:: palavraAleatoria(Tema tema){
    return sortearPalavra(tema);
}

string sortearPalavra(Tema tema){
    int indice;
    do{
        indice = rand() % MAX_QTD_DE_PALAVRAS +1;
    }while(testePalavraUsada(indice));
    return tema == NomeProprio ? nomeProprio(indice) : tema == Comida ? comida(indice) : tema == Animal ? animal(indice) : veiculo(indice);
}

string nomeProprio(int indice){
    switch (indice) {
        case 1:
            return "GABRIEL";
        case 2:
            return "WELLINGTON";
        case 3:
            return "YURI";
        case 4:
           return "MATHEUS";
        case 5:
            return "IAGO";
        case 6:
            return "SUZETE";
        case 7:
            return "LUCIANA";
        case 8:
            return "JOAO";
        case 9:
            return "LEONARDO";
        case 10:
            return "GUILHERME";
        case 11:
            return "FLAVIO";
        case 12:
            return "PAULO";
        case 13:
            return "RENATO";
        case 14:
            return "BRUNO";
        case 15:
            return "LETICIA";
        case 16:
            return "MARIA";
        case 17:
            return "TEODORO";
        case 18:
            return "DOUGLAS";
        case 19:
            return "VANESSA";
        case 20:
            return "JULIANA";
    }
    return NULL;
}

string animal(int indice){
    switch (indice) {
        case 1:
            return "CAMELO";
        case 2:
            return "LEOPARDO";
        case 3:
            return "TUCANO";
        case 4:
            return "ELEFANTE";
        case 5:
            return "GAFANHOTO";
        case 6:
            return "BARATA";
        case 7:
            return "PATO";
        case 8:
            return "CACHORRO";
        case 9:
            return "GATO";
        case 10:
            return "ESQUILO";
        case 11:
            return "CEGONHA";
        case 12:
            return "JAVALI";
        case 13:
            return "PORCO";
        case 14:
            return "BALEIA";
        case 15:
            return "TUBARAO";
        case 16:
            return "VACA";
        case 17:
            return "CROCODILO";
        case 18:
            return "PELICANO";
        case 19:
            return "SUAMAE";
        case 20:
            return "GORILA";
    }
    return NULL;
}
string veiculo(int indice){
    switch (indice) {
        case 1:
            return "CHEVROLET";
        case 2:
            return "VOLKSWAGEN";
        case 3:
            return "TRATOR";
        case 4:
            return "FERRARI";
        case 5:
            return "PORSCHE";
        case 6:
            return "JETSKI";
        case 7:
            return "IATE";
        case 8:
            return "LANCHA";
        case 9:
            return "KAWASAKI";
        case 10:
            return "SUZUKI";
        case 11:
            return "HONDA";
        case 12:
            return "CAMINHAO";
        case 13:
            return "CARRO";
        case 14:
            return "MOTO";
        case 15:
            return "BICICLETA";
        case 16:
            return "AVIAO";
        case 17:
            return "LAMBORGHINI";
        case 18:
            return "BUGATTI";
        case 19:
            return "YAMAHA";
        case 20:
            return "SUAMAE";
    }
    return NULL;
}
string comida(int indice){
    switch (indice) {
        case 1:
            return "MACARRAO";
        case 2:
            return "ARROZ";
        case 3:
            return "PANQUECA";
        case 4:
            return "MELANCIA";
        case 5:
            return "PESSEGO";
        case 6:
            return "PIZZA";
        case 7:
            return "HAMBURGUER";
        case 8:
            return "CENOURA";
        case 9:
            return "BETERRABA";
        case 10:
            return "SORVETE";
        case 11:
            return "SOPA";
        case 12:
            return "SUSHI";
        case 13:
            return "BOLO";
        case 14:
            return "TORTA";
        case 15:
            return "SUAMAE";
        case 16:
            return "GOIABA";
        case 17:
            return "ENSOPADO";
        case 18:
            return "SANDUICHE";
        case 19:
            return "MANTEIGA";
        case 20:
            return "CATCHUP";
    }
    return NULL;
}

bool testePalavraUsada(int indice){
    for (int i = 0; i < MAX_QTD_DE_PALAVRAS; i ++) {
        if (palavrasUsadas[i] == indice) {
            return true;
        }else if (palavrasUsadas[i] == 0){
            palavrasUsadas[i] = indice;
            break;
        }
    }
    return false;
}