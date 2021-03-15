#include "SistemaComunicacao.h"
#include "ArvoreBinaria.h"
#include "Letra.h"

SistemaComunicacao::SistemaComunicacao(){
}

SistemaComunicacao::~SistemaComunicacao(){
}

void SistemaComunicacao::ProcessaEntrada(string nomeEntrada, ArvoreBinaria *arvore) {
	string linha;
	ifstream arquivo;
	arquivo.open(nomeEntrada, ios::in);
	
	while (getline(arquivo, linha)) {
        ProcessaLinha(linha, arvore);
	}
}

void SistemaComunicacao::ProcessaLinha(string linha, ArvoreBinaria *arvore){
	if(linha[0] == 'A'){
		int tamanho = linha.length();
		
		for(int i = 3; i < tamanho; i++){
			arvore->Insere(new Letra(linha[i]));
		}
	}
}