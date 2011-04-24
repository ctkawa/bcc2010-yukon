#ifndef _PILHA_H_
#define _PILHA_H_

#include "carta.h"
#include <iostream>

class PILHA{
private:
	CARTA ** cartas;
	int tamMax;			//maximo de elemento que a pilha pode conter
	int tamanho;
public:
	PILHA( int );			//informar o tamanho maximo da pilha ao instanciar
	int getTamanho();		// retorna tamanho atual
	int getTamanhoMax();
	void empilha( CARTA * , bool&);
	CARTA * desempilha( bool& );
}; 

#endif
