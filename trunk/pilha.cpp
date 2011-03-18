#include "pilha.h"

PILHA::PILHA(){
	tamanhoAtual = 0;
}

int PILHA::getTamanho(){
	return tamanhoAtual;
}

CARTA PILHA::getCarta( int posicao ){
	cout << cartas[posicao] << endl;
	if(0<=posicao && posicao <=tamanhoAtual)
		return cartas[posicao];
	else
		return 0;
}

bool PILHA::add( CARTA c){
	if(tamanhoAtual < 52){
		cartas[tamanhoAtual] = c;
		tamanhoAtual++;
		return true;
	}
	else
		return false;
}

