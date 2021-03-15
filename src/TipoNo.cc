#include "TipoNo.h"

TipoNo::TipoNo(){
    esq = NULL;
    dir = NULL;
    Letra *letra = new Letra();
    letra->SetLetra('\0');
}