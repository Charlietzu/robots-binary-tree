#ifndef TIPONO_H
#define TIPONO_H

#include "Letra.h"

using namespace std;

class TipoNo {
    public:
        TipoNo();

    private:
        Letra *letra;
        TipoNo *esq;
        TipoNo *dir;

    friend class ArvoreBinaria;
};

#endif