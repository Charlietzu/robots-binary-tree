#include <iostream>
#include "SistemaComunicacao.h"
#include "ArvoreBinaria.h"

using namespace std;

int main(int argc, char* argv[]) {
 if (argc > 1){
        string nomeEntrada = argv[1];

        SistemaComunicacao* sistemaComunicacao = new SistemaComunicacao();
        ArvoreBinaria* arvore = new ArvoreBinaria();
        sistemaComunicacao->ProcessaEntrada(nomeEntrada, arvore);
        
        delete sistemaComunicacao;
        delete arvore;
    }
    return 0;
}