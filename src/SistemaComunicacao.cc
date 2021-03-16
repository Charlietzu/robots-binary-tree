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
	int tamanho = linha.length();
	if(linha[0] == 'A'){
		for(int i = 3; i < tamanho; i++){
			arvore->Insere(new Letra(linha[i]));
		}
	} else if(linha[0] == 'C'){
		string frase = "";
		for(int i = 3; i < tamanho; i++){
			frase += linha[i];
		}
		arvore->CodificaFrase(frase);
	} else if(linha[0] == 'D'){
		string codigo = "";
		for(int i = 4; i < tamanho; i++){
			if(linha[i] != 'x') {
				codigo += linha[i];
				if(i == (int)tamanho - 1){
					arvore->DecodificaCodigo(codigo, 0);
					codigo = "";
				}
			} else if (linha[i] == 'x') {
				arvore->DecodificaCodigo(codigo, 0);
				codigo = "";
			}
		}
		cout << endl;
	}
}