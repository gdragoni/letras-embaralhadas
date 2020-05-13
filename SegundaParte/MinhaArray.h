//
//  MinhaArray.h
//  PalavrasEmbaralhadas
//
//  Created by Gabriel A. Dragoni on 5/11/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#include "Constant.h"

class MinhaArray{
public:
    void   adicionarPalavra(string palavra);      /*adiciona palavra na array*/
    string palavraNoIndice(int indice);           /*get palavra da array por indice*/
    void   deletarPalavraNoIndice(int indice);    /*deleta palavra da array por indice*/
};

