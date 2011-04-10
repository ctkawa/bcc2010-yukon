#include <stdlib.h>
#include <time.h>
#include "carta.h"

using namespace std;

class BARALHO{
private:
	CARTA cartas[52]; // espaço para todas as cartas usadas no jogo
	int posicoes[52]; // lista as posicoes válidas
	int qtdPosicoes; // quantidade de posicoes validas
public:
	BARALHO(); // construtor
	CARTA * getCartaRand( bool& ); // retira uma carta numa posição aleatória
	int getTamanho();
	void arrumar();
	CARTA * getCarta(int);
};

