#include "pilha.h"

PILHA::PILHA( int tm ){
	tamMax = tm;
	tamanho = 0;
	cartas = new CARTA * [tamMax];
}

int PILHA::getTamanho(){
	return tamanho;
}

int PILHA::getTamanhoMax(){
	return tamMax;
}

void PILHA::empilha( CARTA * novaCarta, bool& ok ){
	if( tamanho < tamMax ){
		cartas[tamanho] = novaCarta;
		tamanho++;
		ok = true;
	} else
		ok = false;
}

CARTA * PILHA::desempilha( bool& ok ){
	if( 0 < tamanho ){
		CARTA * cartaNoTopo = cartas[tamanho-1];
		tamanho--;
		ok = true;
		return cartaNoTopo;
	} else {
		ok = false;
		return 0;
	}
}
