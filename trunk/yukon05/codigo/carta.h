#ifndef _CARTA_H_
#define _CARTA_H_

#include <iostream>
#include <stdlib.h>

using namespace std;
 
 class CARTA{
	 // o construtor de BARALHO precisa de acesso direto para modificar as cartas
	 friend class BARALHO;
 private:
	 int valor; // 1 a 13 onde 11 = J, 12 = Q e 13 = K, interpretados pela interface
	 char naipe; // C (copas), P (paus), E (espadas), O (ouros)
	 bool visivel;
	 bool setValor( int ); // valida atribuição
	 bool setNaipe( char ); // valida atribuição
 public:
	 CARTA(); // construtor
	 CARTA( int, char, bool ); // construtor
	 CARTA( const CARTA& ); // construtor de cópia
	 CARTA operator=( CARTA ); // sobrecarga da atribuição
	 int getValor();
	 char getNaipe();
	 bool getVisivel();
	 bool setVisivel(); // torna visivel
	 bool getCor(); // 0 = preto, 1 = vermelho
 };
 
ostream& operator<<(ostream&, CARTA);
 
#endif


