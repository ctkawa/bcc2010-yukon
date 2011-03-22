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
	int getMonteTam(int);
	CARTA getMonteCarta(int, int);
	int getFundacao(int);
	bool mover(int, int, int);
};
