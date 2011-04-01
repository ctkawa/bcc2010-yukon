#include "baralho.h"

BARALHO::BARALHO(){
	// seleciona semente randomica
	srand( time(NULL) );
	
	int carta, valor;
	
	valor = 0;
	for(carta=0; carta<52; carta++){
		cartas[carta].valor = carta%13 + 1;
		if(carta < 13) cartas[carta].naipe = 'O';
		else if(carta < 26) cartas[carta].naipe = 'C';
		else if(carta < 39) cartas[carta].naipe = 'P';
		else cartas[carta].naipe = 'E';
		valor++;
	}
	
	tamanhoAtual = 52;
}

CARTA BARALHO::getCartaRand(){
	// recebe valor inteiro aleatório menos que o tamanhoAtual
	int r = rand() % tamanhoAtual;
	// guarda o valor
	CARTA c = cartas[r];
	// remove carta
	removerCarta(r);
	// retorna carta guardada
	return c;
}

int BARALHO::removerCarta( int posicao ){
	// verifica validade de posicao
	if( posicao < 0 || posicao > tamanhoAtual )
		return 1;
	
	int carta;
	for(carta=posicao; carta<tamanhoAtual; carta++)
		// reposiciona as cartas
	cartas[carta] = cartas[carta + 1];
	tamanhoAtual--;
	
	return 0;
} 
