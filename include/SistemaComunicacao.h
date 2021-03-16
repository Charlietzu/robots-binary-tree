#ifndef SISTEMACOMUNICACAO_H
#define SISTEMACOMUNICACAO_H

#include <fstream>
#include <iostream>
#include <string>

#include "ArvoreBinaria.h"

using namespace std;

class SistemaComunicacao {
    public:
        SistemaComunicacao();
        ~SistemaComunicacao();
        
        void ProcessaEntrada(string nomeEntrada, ArvoreBinaria *arvore);
        void ProcessaLinha(string linha, ArvoreBinaria *arvore);
};

#endif