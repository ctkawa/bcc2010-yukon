#ifndef YUKON_H
#define YUKON_H

#include <iostream>
#include "carta.h"
#include "baralho.h"
#include "monte.h"
#include "fundacao.h"

using namespace std;

class YUKON {
private:
	BARALHO baralho;
	MONTE montes[7];
	FUNDACAO fundacao;
	void embaralhaCartas();
public:
	YUKON();
	virtual int run() = 0;
	int getMonteTam(int);		// retorna o num carta de um certo monte
	int getMaxMonteTam();		// retorna o num carta de maior monte
	CARTA getMonteCarta(int, int);
	int getFundacao(int);
	bool mover(int, int, int);
};

#endif
