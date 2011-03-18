#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "baralho.h"
#include "pilha.h"

using namespace std;

// sobrecarga da impressão
ostream &operator<<(ostream & out, CARTA c ){
	// imprime de acordo cm a visibilidade
	if(c.getVisivel())
		out << "[" << c.getNaipe() << ", " << c.getValor() << "]";
	else
		out << "[?, ?]";
	
	return out;
}

ostream &operator<<( ostream & out, PILHA p){
	for(int carta=0; carta<p.getTamanho(); carta++)
		out << p.getCarta(carta) << endl;
	
	return out;
}

//== MAIN ===========================================

int main(){

	BARALHO baralho;
	PILHA pilhas[7];

	CARTA c;
	c = baralho.getCartaRand();
	c.setVisivel(true);
	pilhas[0].add(c);
	cout << pilhas[0];

	for(int pilha=1; pilha<7; pilha++){
		int p;
		for(p=0; p<pilha; p++){
			c = baralho.getCartaRand();
			c.setVisivel(false);
			pilhas[pilha].add(c);
		}
		cout << "ops\n";
		for(p=0; p<5; p++){
			c = baralho.getCartaRand();
			c.setVisivel(true);
			pilhas[pilha].add(c);
		}

		cout << pilhas[pilha];
	}

	return 0;
}
