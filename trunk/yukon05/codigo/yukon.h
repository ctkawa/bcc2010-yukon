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
	BARALHO * baralho;
	MONTE * montes;
	void embaralharCartas();
protected:
	FUNDACAO fundacao;
public:
	YUKON();
	virtual int run() = 0;
	MONTE * getMonte(int);
	int getMaxMonteTam();		// retorna o num carta de maior monte
	FUNDACAO * getFundacao();
	void novoJogo();
};

#endif
