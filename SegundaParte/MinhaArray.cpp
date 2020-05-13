//
//  MinhaArray.cpp
//  PalavrasEmbaralhadas
//
//  Created by Gabriel A. Dragoni on 5/11/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#include "MinhaArray.h"

char matriz[MAX_QTD_DE_PALAVRAS][20];

void MinhaArray::adicionarPalavra(string palavra){
    for (int i = 0; i < MAX_QTD_DE_PALAVRAS; i++) {
        if (matriz[i][0] == '\0') {
            for (int j = 0; j <= palavra.length(); j++) {
                matriz[i][j] = palavra[j];
            }
            break;
        }
    }
}

string MinhaArray::palavraNoIndice(int indice){
    string palavra;
    for (int j = 0; j < 20; j++) {
        if (matriz[indice][j] == '\0') return palavra;
        palavra += matriz[indice][j];
    }
    return palavra;
}

void MinhaArray::deletarPalavraNoIndice(int indice){
    for (int j = 0; j < 20; j++) {
        if (matriz[indice][j] == '\0') return;
        else matriz[indice][j] = '\0';
    }
}