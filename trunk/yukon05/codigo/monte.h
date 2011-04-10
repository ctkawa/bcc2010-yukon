#ifndef MONTE_H
#define MONTE_H

#include <iostream>
#include "pilha.h"

using namespace std;

class MONTE {
	friend class FUNDACAO;
private:
	int posicao;
	PILHA * pilha;
	void remover( int, bool& );
public:
	MONTE();
	MONTE(int);
	void setPosicao( int );
	int getPosicao();
	int getTamanho();
	CARTA * getCarta( int, bool& );
	void adicionar( CARTA *, bool& );
	void receberCartas( MONTE *, int, bool& );
	void esvaziar();
};

#endif