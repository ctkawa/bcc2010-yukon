#include <iostream>
#include <string>
#include <stdlib.h>
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


/*
mover
ajuda/sobre
*/

int interpretar(string cmd){
	string origem = cmd.substr(0,1);
	string destino = cmd.substr(2,1);
	cout <<"mv "<<origem<<" to "<<destino << endl;
	return 0;
}


int main (){

	BARALHO baralho;
	PILHA pilhas[7];
	CARTA c;
	
	int i,j;
	for(i=1;i<=6;i++){
       for(j=1;j<=i;j++){
          c=baralho.getCartaRand();
          pilhas[i].add(c);
       }
       for(j=1;j<=5;j++){
         c=baralho.getCartaRand();
         c.setVisivel(true);
         pilhas[i].add(c);    
      }
}  
    c=baralho.getCartaRand();
    c.setVisivel(true);      
    pilhas[0].add(c);

      
    
    /*
    c = baralho.getCartaRand();
	c.setVisivel(true);
	pilhas[0].add(c);
	
	c = baralho.getCartaRand();
	c.setVisivel(true);
	pilhas[1].add(c);
	
	c = baralho.getCartaRand();
	c.setVisivel(true);
	pilhas[1].add(c);0
	*/
	
	for(int pilha=0; pilha<7; pilha++)
		cout << pilhas[pilha] << endl << "-----" << endl;
	
	string comando;
	cout << ">> ";
	cin >> comando;

	interpretar(comando);


	return 0;
}
