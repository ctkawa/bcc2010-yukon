
#include "monte.h"
#include <iostream>
 
using namespace std;


 
int MONTE::getTamanho(){
	 return pilha.getTamanho();
}
 
CARTA MONTE::getCarta( int posicao ){
	return pilha.getCarta(posicao);
}
 
 bool MONTE::add( CARTA c ){
	 return pilha.add(c);
 }
 
 bool MONTE::remover( int posicao ){
	 return pilha.remover(posicao);
 }
 
 bool MONTE::setVisivelTrue( int posicao ){
	 return pilha.setVisivelTrue(posicao);
 }
 
 bool MONTE::receberCartas( MONTE m, int posicao ){
	 CARTA cNova = m.getCarta(posicao);
	 CARTA cTopo = pilha.getCarta(pilha.getTamanho()-1);
	 
	 if(cNova.getValor() == cTopo.getValor() - 1 &&
		 cNova.getCor() != cTopo.getCor() )
	 {
		 for(int i=posicao; i<m.getTamanho(); i++)
			 pilha.add(m.getCarta(i));
		 return true;
	 }
	 
	 return false;
}

ostream &operator<<( ostream & out, MONTE p){
	for(int carta=0; carta<p.getTamanho(); carta++)
		out << p.getCarta(carta) << " ";
	
	return out;
}
