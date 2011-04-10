#include "baralho.h"

BARALHO::BARALHO(){
	// seleciona semente randomica
	srand( time(NULL) );
	
	int posicao, valor;
	
	valor = 0;
	for(posicao=0; posicao<52; posicao++){
		posicoes[posicao] = posicao;
		cartas[posicao].valor = posicao%13 + 1;
		if(posicao < 13) cartas[posicao].naipe = 'O';
		else if(posicao < 26) cartas[posicao].naipe = 'C';
		else if(posicao < 39) cartas[posicao].naipe = 'P';
		else cartas[posicao].naipe = 'E';
		valor++;
	}
	
	qtdPosicoes = 52;
}

CARTA * BARALHO::getCartaRand( bool& ok){
	if ( qtdPosicoes <= 0 ){
		ok = false;
		return 0;
	} else {
		// recebe valor inteiro aleatório menor que a qtdPosicoes
		int posicao = rand() % qtdPosicoes;
		CARTA * c = &cartas[posicoes[posicao]];
		
		// remove a posicao
		for(int i=posicao; i<qtdPosicoes-1; i++)
			posicoes[i] = posicoes[i + 1];
		qtdPosicoes--;
		
		// retorna o endereco da carta guardada
		ok = true;
		return c;
	}
}

CARTA * BARALHO::getCarta( int posicao ){
	return &cartas[posicao];
}

int BARALHO::getTamanho(){
	return qtdPosicoes;
}
