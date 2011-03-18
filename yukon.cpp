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
	cout << p.getTamanho();
	for(int carta=0; carta<p.getTamanho(); carta++)
		out << p.getCarta(carta) << endl;
	
	return out;
}


int main (){
	
	PILHA p;
	
	
	
	string comando;
	cout << ">> ";
	cin >> comando;
	
	return 0;
}
