//
//  StringAd.h
//  PalavrasEmbaralhadas
//
//  Created by Gabriel A. Dragoni on 5/12/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#include "Constant.h"

class StringAd{
public:
    void   escreve(string frase);               /*cout*/
    string leia();                              /*cin de string*/
    void   mostrarPalavra(string palavra);      /*mostra (cout) palavra com design definido*/
    string palavraMaiuscula(string palavra);    /*Passa todas as letras da palavra para maiusculo*/
    string palavraEmbaralhada(string palavra);  /*Embaralha a palavra passada como parametro*/
};
