#ifndef _PILHA_H_
#define _PILHA_H_

#include "carta.h"

class PILHA{
private:
	CARTA cartas[52];
	int tamanhoAtual;
public:
	PILHA();
	int getTamanho();
	CARTA getCarta( int );
	bool add( CARTA );
	bool remover( int );
	bool setVisivelTrue( int );
}; 

#endif
