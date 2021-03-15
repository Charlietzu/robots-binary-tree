#include "SistemaComunicacao.h"
#include "ArvoreBinaria.h"
#include "Letra.h"

SistemaComunicacao::SistemaComunicacao(){
}

SistemaComunicacao::~SistemaComunicacao(){
}

void SistemaComunicacao::ProcessaEntrada(string nomeEntrada) {
	string linha;
	ifstream arquivo;
	arquivo.open(nomeEntrada, ios::in);
	
	while (getline(arquivo, linha)) {
        ProcessaLinha(linha);
	}
}

void SistemaComunicacao::ProcessaLinha(string linha){
	if(linha[0] == 'A'){
		int tamanho = linha.length();
		ArvoreBinaria *arvore = new ArvoreBinaria();
		
		for(int i = 3; i < tamanho; i++){
			Letra* letra = new Letra();
			letra->SetLetra(linha[i]);
			letra->Imprime();
		}
	}
}