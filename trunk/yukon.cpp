#include <iostream>
#include "carta.h"
#include "baralho.h"
#include "pilha.h"

using namespace std;

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
		out << p.getCarta(carta) << " ";
	
	return out;
}


int main (){
	
	BARALHO baralho;
	PILHA pilhas[7];
	CARTA c;
	
	c = baralho.getCartaRand();
	c.setVisivel(true);
	pilhas[0].add(c);
	
	c = baralho.getCartaRand();
	c.setVisivel(true);
	pilhas[1].add(c);
	
	c = baralho.getCartaRand();
	c.setVisivel(true);
	pilhas[1].add(c);
	
	
	for(int pilha=0; pilha<7; pilha++)
		cout << pilhas[pilha] << endl << "-----" << endl;
	
	
	string comando;
	cout << ">> ";
	cin >> comando;
	
	return 0;
}
