//
//  StringAd.cpp
//  PalavrasEmbaralhadas
//
//  Created by Gabriel A. Dragoni on 5/12/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#include "StringAd.h"

void escreve(string frase);

void StringAd::escreve(string frase){
    cout << frase;
}

string StringAd::leia(){
    string palavra;
    cin >> palavra;
    return palavra;
}

void StringAd::mostrarPalavra(string palavra){
    for (int i = 0; i < palavra.length()*4; i++) {
        if (i == 0) {
            escreve("=");
        }
        escreve("=");
    }
    escreve("\n");
    for (int i = 0; i < palavra.length(); i++) {
        if (i == 0) {
            escreve("| ");
        }
        cout << palavra[i] << " | ";
    }
    escreve("\n");
    for (int i = 0; i < palavra.length()*4; i++) {
        if (i == 0) {
            escreve("=");
        }
        escreve("=");
    }
}

string StringAd::palavraMaiuscula(string palavra){
    string palavraMaiuscula;
    for (int i = 0; i < palavra.length(); i ++) {
        palavraMaiuscula += toupper(palavra[i]);
    }
    return palavraMaiuscula;
}

string StringAd::palavraEmbaralhada(string palavra){
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

