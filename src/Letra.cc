#include "Letra.h"

Letra::Letra(){
    letra = '\0';
}

Letra::Letra(char valor){
    letra = valor;
}

Letra::~Letra(){}

void Letra::SetLetra(char valor){
    letra = valor;
}

int Letra::GetValorLetra(){
    if(letra == '-' || letra == ' '){
        return -1;
    } else {
        return letra - 64;
    }
}

char Letra::GetLetra(){
    return letra;
}

void Letra::Imprime(){
    cout << "Letra: " << letra << " - Posicao: " << GetValorLetra() << endl;
}