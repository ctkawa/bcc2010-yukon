#include "yukon.h"

YUKON::YUKON(){
	embaralhaCartas();
}

void YUKON::embaralhaCartas(){
	CARTA c;
	
	int i,j;
	for(i=1;i<=6;i++){
		for(j=1;j<=i;j++){
			c =baralho.getCartaRand();
			montes[i].add(c);
		}
		for(j=1;j<=5;j++){
			c=baralho.getCartaRand();
			c.setVisivel(true);
			montes[i].add(c); 
		} 
	}
	// Carta do primeiro monte
	c=baralho.getCartaRand();
	
	c.setVisivel(true);      
	montes[0].add(c);
}

int YUKON::novoJogo(){
	BARALHO nbaralho;
	MONTE nmontes;
	FUNDACAO nfundacao;
	baralho = nbaralho;
	for(int i=0; i<7;i++)
		montes[i] = nmontes;
	fundacao = nfundacao;
	embaralhaCartas();
	return 0;
}

int YUKON::getMonteTam(int monte){
	return montes[monte].getTamanho();
}

int YUKON::getMaxMonteTam(){
	int ret=0;
	int n=-1;
	for(int i=0; i<7;i++){
		if (getMonteTam(i)>ret){
			ret = getMonteTam(i);
			n = i;
		}
	}
	//cout <<"maxmont: n" << n;
	return ret;
}

CARTA YUKON::getMonteCarta(int monte, int carta){
	return montes[monte].getCarta(carta);
}

int YUKON::getFundacao(int monte){
	return fundacao.getMonte(monte);
}

bool YUKON::mover(int origemp, int origemc, int destino){
	if (origemp != destino) {
	if(montes[destino].receberCartas(montes[origemp],origemc))
		if(montes[origemp].remover(origemc))
			return true;
	}
	return false;
}

bool YUKON::moverParaFundacao(int origemp, int origemc){
	cout << montes[origemp].getTamanho() << endl;
	cout << origemc << endl;
	cout << "==\n";
	
	if(montes[origemp].getTamanho() -1 == origemc)
		if(fundacao.addCarta(montes[origemp].getCarta(origemc)))
			if(montes[origemp].remover(origemc))
				return true;
	return false;
}
