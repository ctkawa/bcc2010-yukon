#include "fundacao.h"

FUNDACAO::FUNDACAO(){
	for(int i=0; i<4; i++)
		montes[i] = 0;
}

int FUNDACAO::getMonte( int monte ){
	return montes[monte];
}

bool FUNDACAO::addCarta( CARTA c ){
	if(c.getNaipe == 'C') montes[0]++;
	else if(c.getNaipe == 'O') montes[1]++;
	else if(c.getNaipe == 'E') montes[2]++;
	else if(c.getNaipe == 'P') montes[3]++;
	else return false;
	return true;
}

