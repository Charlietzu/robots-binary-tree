#include "ArvoreBinaria.h"
#include "Letra.h"

ArvoreBinaria::ArvoreBinaria(){
    raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria(){
    Limpa();
}

void ArvoreBinaria::Limpa(){
    ApagaRecursivo(raiz);
    raiz = NULL;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
    if(p != NULL){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

Letra ArvoreBinaria::Pesquisa(int valor){
    return PesquisaRecursivo(raiz, valor);
}

Letra ArvoreBinaria::PesquisaRecursivo(TipoNo *no, int valor){
    Letra aux;

    if(no == NULL){
        aux.SetLetra('\0');
        return aux;
    }

    if(valor < no->letra.GetValorLetra()){
        return PesquisaRecursivo(no->esq, valor);
    } else if (valor > no->letra.GetValorLetra()){
        return PesquisaRecursivo(no->dir, valor);
    } else {
        no->letra.Imprime();
        return no->letra;
    }
}

void ArvoreBinaria::Insere(Letra item){
    InsereRecursivo(raiz, item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, Letra item){
    if(p == NULL){
        p = new TipoNo();
        p->letra = item;
    } else {
        if(item.GetValorLetra() < p->letra.GetValorLetra()){
            InsereRecursivo(p->esq, item);
        } else {
            InsereRecursivo(p->dir, item);
        }
    }
}