#include "yukon.h"

YUKON::YUKON(){
	// constroi montes
	montes = new MONTE[7];
	for(int i=0; i<7; i++)
		montes[i].setPosicao(i);
	
	embaralharCartas();
}

void YUKON::embaralharCartas(){
	baralho = new BARALHO();
	CARTA * c;
	bool ok;
	
	// carta do primeiro monte
	c = baralho->getCartaRand(ok);
	if(!ok){
		cout << "Erro ao embaralhar cartas.\n";
		exit(1);
	}
	
	c->setVisivel();      
	montes[0].adicionar(c, ok);
	if(!ok){
		cout << "Erro ao embaralhar cartas.\n";
		exit(1);
	}
	
	// cartas dos outros montes
	int i,j;
	for(i=1; i<=6; i++){
		for(j=1;j<=i;j++){
			c = baralho->getCartaRand(ok);
			if(!ok){
				cout << "Erro ao embaralhar cartas.\n";
				exit(1);
			}
			
			montes[i].adicionar(c, ok);
			if(!ok){
				cout << "Erro ao embaralhar cartas.\n";
				exit(1);
			}
		}
		for(j=1;j<=5;j++){
			c = baralho->getCartaRand(ok);
			if(!ok){
				cout << "Erro ao embaralhar cartas.\n";
				exit(1);
			}
			c->setVisivel();
			montes[i].adicionar(c, ok);
			if(!ok){
				cout << "Erro ao embaralhar cartas.\n";
				exit(1);
			}
		} 
	}
}

void YUKON::novoJogo(){
	fundacao.esvaziar();
	for(int i=0; i<7; i++)
		montes[i].esvaziar();
	embaralharCartas();
}

MONTE * YUKON::getMonte(int monte){
	return &montes[monte];
}

int YUKON::getMaxMonteTam(){
	int maximo = 0;
	
	for(int monte=0; monte<7; monte++){
		if (montes[monte].getTamanho() > maximo){
			maximo = montes[monte].getTamanho();
		}
	}
	
	return maximo;
}

FUNDACAO * YUKON::getFundacao(){
	return &fundacao;
}