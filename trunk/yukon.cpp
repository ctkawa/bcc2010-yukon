#include <iostream>
#include "carta.h"
#include "baralho.h"

using namespace std;

ostream &operator<<(ostream & out, CARTA c ){
	// imprime de acordo cm a visibilidade
	if(c.getVisivel())
		out << "[" << c.getNaipe() << ", " << c.getValor() << "]";
	else
		out << "[?, ?]";
	
	return out;
}


int main (){
	
	BARALHO b;
	CARTA a = b.getCartaRand();
	cout << a << endl;
	
	a.setVisivel(true);
	cout << a << endl;
	
	return 0;
}