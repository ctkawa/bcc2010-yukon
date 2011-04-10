#include "fundacao.h"

FUNDACAO::FUNDACAO(){
	esvaziar();
}

int FUNDACAO::getMonte( int monte ){
	if(0<=monte && monte <4)
		return montes[monte];
	return 0;
}

void FUNDACAO::receberCarta( MONTE * m, bool& ok ){
	bool okGetcarta;
	
	// pega a carta do topo
	CARTA *c = m->getCarta(m->getTamanho()-1, okGetcarta);
	
	if(okGetcarta){
		if(c->getNaipe() == 'C' && c->getValor() == montes[0] + 1){
			montes[0]++;
			m->remover(m->getTamanho()-1, okGetcarta);
		} else if(c->getNaipe() == 'O' && c->getValor() == montes[1] + 1){
			montes[1]++;
			m->remover(m->getTamanho()-1, okGetcarta);
		} else if(c->getNaipe() == 'E' && c->getValor() == montes[2] + 1){
			montes[2]++;
			m->remover(m->getTamanho()-1, okGetcarta);
		} else if(c->getNaipe() == 'P' && c->getValor() == montes[3] + 1){
			montes[3]++;
			m->remover(m->getTamanho()-1, okGetcarta);
		}
		
		if(!okGetcarta){
			cout << "Erro ao remover carta\n";
			exit(1);
		}
		ok = true;
	} else {
		ok = false;
	}
}

void FUNDACAO::esvaziar(){
	for(int i=0; i<4; i++)
		montes[i] = 0;
}