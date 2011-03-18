#include "fundacao.h"

FUNDACAO::FUNDACAO(){
	for(int i=0; i<4; i++)
		montes[i] = 0;
}

int FUNDACAO::getMonte( int monte ){
	if(0<=monte && monte <4)
		return montes[monte];
}

bool FUNDACAO::addCarta( CARTA c ){
	if(0<c.getValor() && c.getValor()<=13){
		if(c.getNaipe() == 'C' && c.getValor() == montes[0] + 1) montes[0]++;
		else if(c.getNaipe() == 'O' && c.getValor() == montes[1] + 1) montes[1]++;
		else if(c.getNaipe() == 'E' && c.getValor() == montes[2] + 1) montes[2]++;
		else if(c.getNaipe() == 'P' && c.getValor() == montes[3] + 1) montes[3]++;
		else return false;
	}
	return true;
}

