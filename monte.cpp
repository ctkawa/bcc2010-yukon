
#include "monte.h"
 
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