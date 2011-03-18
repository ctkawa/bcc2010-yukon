using namespace std;

class BARALHO{
private:
	CARTA cartas[52]; // espaço para todas as cartas
	int tamanhoAtual; // posição atual
	int removerCarta( int ); // remove uma carta
public:
	BARALHO(); // construtor
	CARTA getCartaRand(); // retira uma carta numa posição aleatória
};

