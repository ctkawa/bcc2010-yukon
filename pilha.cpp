#include "pilha.h"
 
class PILHA{
private:
	CARTA cartas[52];
	int tamanhoMax;
	int tamanhoAtual;
public:
	PILHA();
	int getTamanho();
	CARTA getCarta( int );
	bool add( CARTA );
};

PILHA::PILHA(){
	tamanhoAtual = 0;
}

int PILHA::getTamanho(){
	return tamanhoAtual;
}

CARTA PILHA::getCarta( int posicao ){
	//cout << cartas[posicao] << endl;
	if(0<=posicao && posicao <=tamanhoAtual)
		return cartas[posicao];
	else
		return 0;
}

bool PILHA::add( CARTA c){
	if(tamanhoAtual < 52){
		cartas[tamanhoAtual] = c;
		tamanhoAtual++;
		return true;
	}
	else
		return false;
}

ostream &operator<<( ostream & out, PILHA p){
    cout << p.getTamanho();
	for(int carta=0; carta<p.getTamanho(); carta++)
		out << p.getCarta(carta) << endl;

	return out;
}
