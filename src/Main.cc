#include <iostream>
#include "SistemaComunicacao.h"
#include "ArvoreBinaria.h"

FILE *arquivo_entrada;

using namespace std;

int main(int argc, char* argv[]) {
 if (argc > 1){
        arquivo_entrada = fopen(argv[1], "rt");
        string nomeEntrada = argv[1];

        SistemaComunicacao* sistemaComunicacao = new SistemaComunicacao();
        ArvoreBinaria* arvore = new ArvoreBinaria();
        sistemaComunicacao->ProcessaEntrada(nomeEntrada, arvore);
    
    }
    return 0;
}