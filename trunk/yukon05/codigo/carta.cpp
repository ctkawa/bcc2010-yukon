#include "carta.h"

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

bool CARTA::setValor( int novoValor ){
	 // verifica se está entre 1 e 13
	 if( 0<novoValor && novoValor<=13){
		 valor = novoValor;
		 return true;
	}

	 // valor padrão para 1
	 valor = 1;
	 return false;
}

bool CARTA::setNaipe( char novoNaipe ){
	 // verifica se o naipe sugerido é válido
	 if( novoNaipe == 'C' || novoNaipe == 'P' || novoNaipe == 'E' || novoNaipe == 'O' ){
		 naipe = novoNaipe;
		 return true;
	 }

	 // valor padrão para copas
	 naipe = 'C';
	 return false;
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

 bool CARTA::setVisivel(){
	 visivel = true;
	 return visivel;
 }
 
bool CARTA::getCor(){
	 if( naipe == 'C' || naipe == 'O')
		 return true;
	 else
		 return false;
}

ostream &operator<<(ostream & out, CARTA c ){
	// imprime de acordo cm a visibilidade
	if(c.getVisivel()) {
		out << "[" ;
		if (c.getNaipe()=='C'){
			out << "♡";}			// se nao tiver visibilidade usar ♥ e ♦
			else if (c.getNaipe()=='O'){
				out << "♢";}
				else if (c.getNaipe()=='P'){
					out << "♣";}
					else if (c.getNaipe()=='E'){
						out << "♠";}
						else{
							cout << "tem algo errado na carta...";}
							if (c.getValor()!=10)
								out << " ";
							if (c.getValor()<=10)
								out << c.getValor() << "]";
							else {
								switch (c.getValor()){
								case(11):
									out << "J]";
									break;
								case(12):
									out << "Q]";
									break;
								case(13):
									out << "K]";
									break;
								}
							}
	} else
		out << "[?,?]";
	return out;
}


