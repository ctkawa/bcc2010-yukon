#include "carta.h"

 bool CARTA::setValor( int v ){
	 // verifica se está entre 1 e 13
	 if( 0<v && v<=13){
		 valor = v;
		 return 0;
	 }

	 // valor padrão para 1
	 valor = 1;
	 return 1;
 }

 bool CARTA::setNaipe( char n ){
	 // verifia se o naipe sugerido é válido
	 if( n == 'C' || n == 'P' || n == 'E' || n == 'O' ){
		 naipe = n;
		 return 0;
	 }

	 // valor padrão para copas
	 naipe = 'C';
	 return 1;
 }

 CARTA::CARTA(){
	 setValor(1);
	 setNaipe('O');
	 visivel = false;
 }

 CARTA::CARTA( int val=1, char nai='O', bool vis=false){
	 setValor(val);
	 setNaipe(nai);
	 visivel = vis;
 }

 CARTA::CARTA( const CARTA &c ){
	 valor = c.valor;
	 naipe = c.naipe;
	 visivel = c.visivel;
 }

 CARTA CARTA::operator=( CARTA c ){
	 valor = c.valor;
	 naipe = c.naipe;
	 visivel = c.visivel;

	 return *this;
 }

 int CARTA::getValor(){
	 // retorna apenas se estiver visivel
	 if( visivel )
		 return valor;
	 else
		 return 0;
 }

 char CARTA::getNaipe(){
	 // retorna apenas se estiver visivel
	 if( visivel )
		 return naipe;
	 else
		 return 0;
 }

 bool CARTA::getVisivel(){
	 return visivel;
 }

 bool CARTA::setVisivel( bool v){
	 visivel = v;
	 return visivel;
 }

 bool CARTA::virar(){
	 // inverte a visibilidade
	 visivel = !visivel;
	 return visivel;
 }
 
 bool CARTA::getCor(){
	 if( naipe == 'C' || naipe == 'O')
		 return true;
	 else
		 return false;
}

