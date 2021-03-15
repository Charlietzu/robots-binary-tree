#ifndef LETRA_H
#define LETRA_H

#include <fstream>
#include <iostream>

using namespace std;

class Letra {
    public:
        Letra();
        ~Letra();
        
        void SetLetra(char letra);
        int GetValorLetra();
        char GetLetra();
        void Imprime();

    private:
        char letra;
};

#endif