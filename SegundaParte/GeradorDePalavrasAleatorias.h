//
//  GeradorDePalavrasAleatorias.h
//  PalavrasEmbaralhadas
//
//  Created by Gabriel A. Dragoni on 5/11/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#include "Constant.h"

typedef enum : int {            /*enum com temas possiveis*/
    NomeProprio,
    Animal,
    Veiculo,
    Comida,
    erro
} Tema;

class GeradorDePalavrasAleatorias{    
public:
    string palavraAleatoria(Tema tema); /*retorna palavra aleatoria por tema*/
};

