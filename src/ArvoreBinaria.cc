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

Letra* ArvoreBinaria::Pesquisa(int valor){
    return PesquisaRecursivo(raiz, valor);
}

Letra* ArvoreBinaria::PesquisaRecursivo(TipoNo *no, int valor){
    Letra *aux = new Letra();

    if(no == NULL){
        aux->SetLetra('\0');
        return aux;
    }

    if(valor < no->letra->GetValorLetra()){
        return PesquisaRecursivo(no->esq, valor);
    } else if (valor > no->letra->GetValorLetra()){
        return PesquisaRecursivo(no->dir, valor);
    } else {
        //no->letra->Imprime();
        return no->letra;
    }
}

void ArvoreBinaria::Insere(Letra *item){
    InsereRecursivo(raiz, item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, Letra *item){
    if(p == NULL){
        p = new TipoNo();
        p->letra = item;
    } else {
        if(item->GetValorLetra() < p->letra->GetValorLetra()){
            InsereRecursivo(p->esq, item);
        } else {
            InsereRecursivo(p->dir, item);
        }
    }
}

void ArvoreBinaria::Remove(int valor){
    return RemoveRecursivo(raiz, valor);
}

void ArvoreBinaria::RemoveRecursivo(TipoNo* &no, int valor){
    TipoNo *aux = new TipoNo();

    if(no == NULL){
        throw("Letra não está presente");
    }

    if(valor < no->letra->GetValorLetra()){
        return RemoveRecursivo(no->esq, valor);
    } else if(valor > no->letra->GetValorLetra()){
        return RemoveRecursivo(no->dir, valor);
    } else {
        if(no->dir == NULL){
            aux = no;
            no = no->esq;
            free(aux);
        } else if(no->esq == NULL){
            aux = no;
            no = no->dir;
            free(aux);
        } else {
            Antecessor(no, no->esq);
        }
    }
}

void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo* &r){
    if(r->dir != NULL){
        Antecessor(q, r->dir);
        return;
    }

    q->letra = r->letra;
    q = r;
    r = r->esq;
    free(q);
}