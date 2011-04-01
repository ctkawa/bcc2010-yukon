#include "pilha.h"
#include <iostream>


PILHA::PILHA(){
	tamanhoAtual = 0;
}

int PILHA::getTamanho(){
	return tamanhoAtual;
}

CARTA PILHA::getCarta( int posicao ){
	//cout << cartas[posicao] << endl;
	if(0<=posicao && posicao <=tamanhoAtual)
		return cartas[posicao];
	else
		return *(new CARTA);
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

bool PILHA::remover( int posicao ){
	if(0 <= posicao && posicao <= tamanhoAtual){
		tamanhoAtual = posicao;
		setVisivelTrue(tamanhoAtual);
		return true;
	} else
		return false;
}

bool PILHA::setVisivelTrue( int posicao ){
	if(0 <= posicao && posicao <= tamanhoAtual){
		cartas[posicao - 1].setVisivel(true);
		return true;
	} else
		return false;
}