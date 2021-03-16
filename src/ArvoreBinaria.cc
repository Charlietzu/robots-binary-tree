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

void ArvoreBinaria::CodificaFrase(string frase){
    Letra *aux = new Letra();
    int tamanho = frase.length();
    
    for(int i = 0; i < tamanho; i++){
        aux->SetLetra(frase[i]);
        cout << 'x';
        Codifica(aux->GetValorLetra());
    }

    cout << endl;
}

void ArvoreBinaria::Codifica(int valor){
    CodificaRecursivo(raiz, valor);
}

void ArvoreBinaria::CodificaRecursivo(TipoNo *no, int valor){
    if(valor < no->letra->GetValorLetra()){
        cout <<  1;
        CodificaRecursivo(no->esq, valor);
    } else if (valor > no->letra->GetValorLetra()){
        cout << 0;
        CodificaRecursivo(no->dir, valor);
    } else {
        return;
    }
}

void ArvoreBinaria::DecodificaCodigo(string codigo, int valor){
    Decodifica(valor, codigo);
}

void ArvoreBinaria::Decodifica(int valor, string codigo){
    DecodificaRecursivo(raiz, valor, codigo);
}

void ArvoreBinaria::DecodificaRecursivo(TipoNo *no, int valor, string codigo){
    int tamanho = codigo.length();
    if(tamanho == valor){
        no->letra->Imprime();
        return;
    }
    if((codigo[valor] - '0') % 2 == 0){
        DecodificaRecursivo(no->dir, valor + 1, codigo);
    } else {
        DecodificaRecursivo(no->esq, valor + 1, codigo);
    }
}