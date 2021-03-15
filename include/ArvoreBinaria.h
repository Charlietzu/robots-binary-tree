#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <fstream>
#include <iostream>
#include <string>

#include "Letra.h"
#include "TipoNo.h"

using namespace std;

class ArvoreBinaria {
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        
        void Insere(Letra item);
        void Caminho(int tipo);
        Letra Pesquisa(int valor);
        void Remove(int valor);
        void Limpa();

    private:
        void InsereRecursivo(TipoNo* &p, Letra item);
        void ApagaRecursivo(TipoNo* p);
        Letra PesquisaRecursivo(TipoNo* p, int valor);
        void RemoveRecursivo(TipoNo* &p, int valor);
        void Antecessor(TipoNo* q, TipoNo* &r);

        TipoNo* raiz;
};

#endif