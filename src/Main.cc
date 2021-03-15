#include <iostream>
#include "SistemaComunicacao.h"

FILE *arquivo_entrada;

using namespace std;

int main(int argc, char* argv[]) {
 if (argc > 1){
        arquivo_entrada = fopen(argv[1], "rt");
        string nomeEntrada = argv[1];

        SistemaComunicacao* sistemaComunicacao = new SistemaComunicacao();
        sistemaComunicacao->ProcessaEntrada(nomeEntrada);
    
    }
    return 0;
}