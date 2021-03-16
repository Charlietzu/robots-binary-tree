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
        
        void Insere(Letra *item);
        Letra* Pesquisa(int valor);
        void Remove(int valor);
        void Limpa();
        void CodificaFrase(string frase);
        void DecodificaCodigo(string codigo, int valor);

    private:
        void InsereRecursivo(TipoNo* &p, Letra *item);
        void ApagaRecursivo(TipoNo* p);
        Letra* PesquisaRecursivo(TipoNo* p, int valor);
        void RemoveRecursivo(TipoNo* &p, int valor);
        void Antecessor(TipoNo* q, TipoNo* &r);
        void CodificaRecursivo(TipoNo* p, int valor);
        void Codifica(int valor);
        void Decodifica(int valor, string codigo);
        void DecodificaRecursivo(TipoNo* p, int valor, string codigo);

        TipoNo* raiz;
};

#endif