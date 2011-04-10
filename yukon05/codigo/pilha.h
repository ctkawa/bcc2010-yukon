#ifndef _PILHA_H_
#define _PILHA_H_

#include "carta.h"
#include <iostream>

class PILHA{
private:
	CARTA ** cartas;
	int tamMax;
	int tamanho;
public:
	PILHA( int );
	int getTamanho();
	int getTamanhoMax();
	void empilha( CARTA * , bool&);
	CARTA * desempilha( bool& );
}; 

#endif
