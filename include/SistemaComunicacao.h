#ifndef SISTEMACOMUNICACAO_H
#define SISTEMACOMUNICACAO_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class SistemaComunicacao {
    public:
        SistemaComunicacao();
        ~SistemaComunicacao();
        
        void ProcessaEntrada(string nomeEntrada);
        void ProcessaLinha(string linha);

    private:
        int tamanhoPreenchido;
};

#endif