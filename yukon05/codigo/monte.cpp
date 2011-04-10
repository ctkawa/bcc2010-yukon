#include "monte.h"
 
using namespace std;

MONTE::MONTE(){
	setPosicao(0);
	pilha = new PILHA(52);
}

MONTE::MONTE( int pos ){
	setPosicao(pos);
	pilha = new PILHA(52);
}

void MONTE::setPosicao(int pos){
	if(0<=pos && pos<7){
		posicao = pos;
	} else
		posicao = 0;
}

int MONTE::getPosicao(){
	return posicao;
}

int MONTE::getTamanho(){
	// O monte tem o mesmo tamanho que sua pilha interna
	 return pilha->getTamanho();
}

CARTA * MONTE::getCarta( int posicao, bool& ok ){
	
	bool okEmpilha, okDesempilha;
	int tamanhoOriginal = pilha->getTamanho()-1;
	
	if( 0<= posicao && posicao <= tamanhoOriginal ){
		PILHA pilhaAuxiliar(52);
		CARTA * cartaPedida, * cartaAuxiliar;
		int i = 0;
		
		// desempilha cartas acima da posição desejada
		for(i=tamanhoOriginal; i>posicao; i--){
			cartaAuxiliar = pilha->desempilha( okDesempilha );
			if(okDesempilha){
				pilhaAuxiliar.empilha( cartaAuxiliar, okEmpilha  );
				if(!okEmpilha){
					cout << "Erro ao empilhar carta.\n";
					exit(1);
				}
			} else {
				cout << "Erro ao desempilhar carta.\n";
				exit(1);
			}
		}
		
		// recebe a carta desejada e a reempilha
		cartaPedida = pilha->desempilha( okDesempilha );
		if(okDesempilha){
			pilha->empilha( cartaPedida, okEmpilha );
			if(!okEmpilha){
				cout << "Erro ao empilhar carta.\n";
				exit(1);
			}
		} else {
			cout << "Erro ao desempilhar carta.\n";
			exit(1);
		}
	
		// reempilha as cartas acima da posição desejada
		for(; i<tamanhoOriginal; i++){
			cartaAuxiliar = pilhaAuxiliar.desempilha( okDesempilha );
			if(okDesempilha){
				pilha->empilha( cartaAuxiliar, okEmpilha );
				if(!okEmpilha){
					cout << "Erro ao empilhar carta.\n";
					exit(1);
				}
			} else {
				cout << "Erro ao desempilhar carta.\n";
			}
		}
		
		ok = true;
		return cartaPedida;
	} else {
		ok = false;
		return NULL;
	}
}
 
void MONTE::adicionar( CARTA * carta, bool& ok){
	// Tenta adicionar a carta recebida diretamente na pilha
	pilha->empilha(carta, ok);
}

void MONTE::remover( int posicao, bool& ok ){
	bool okEmpilha, okDesempilha;
	
	if(0<= posicao && posicao < getTamanho()){
		 CARTA * cartaAuxiliar;
		 int i = 0;
		 
		// remove todas as cartas acima da posicao escolhida
		for(i=getTamanho()-1; i>=posicao; i--){
			pilha->desempilha( okDesempilha );
			if(!okDesempilha){
				cout << "Erro ao desempilhar.\n";
				exit(1);
			}
		}
		 
		// verifica se a pilha está vazia
		if(getTamanho() > 0){
			// faz as cartas do topo do monte ficarem sempre visíveis
			cartaAuxiliar = pilha->desempilha( okDesempilha );
			if(!okDesempilha){
				cout << "Erro ao desempilhar.\n";
				exit(1);
			} else {
				cartaAuxiliar->setVisivel();
				pilha->empilha( cartaAuxiliar, okEmpilha );
				if(!okEmpilha){
					cout << "Erro ao empilhar.\n";
					exit(1);
				}
			}
		}
		 
		ok = true;
	} else
		ok = false;
}
 
 void MONTE::receberCartas( MONTE * monteDaCarta, int posicaoDaCarta, bool& ok ){
	 //este monte recebe cartas de monte m a partir de pos p
	
	bool okGetcarta;
	bool okDesempilha, okEmpilha;
	
	// verifica se os montes são iguais
	if( monteDaCarta->getPosicao() == getPosicao() ){
		ok = false;
		return;
	}
	
	// verifica se o monte não está vazio
	if (0<getTamanho()){
		// testa as cartas
		
		CARTA * cartaNova = monteDaCarta->getCarta( posicaoDaCarta, okGetcarta );
		if(!okGetcarta){
			cout << "Erro ao obter carta de monte.\n";
			exit(1);
		}
		
		CARTA * cartaTopo = getCarta(getTamanho()-1,okGetcarta);
		if(!okGetcarta){
			cout << "Erro ao obter carta de monte.\n";
			exit(1);
		}
		
		if(cartaNova->getValor() == cartaTopo->getValor() - 1 &&
			cartaNova->getCor() != cartaTopo->getCor() )
		{
			for(int i=posicaoDaCarta; i<monteDaCarta->getTamanho(); i++){
				CARTA * cartaAuxiliar;
				cartaAuxiliar = monteDaCarta->getCarta(i, okGetcarta);
				if(!okGetcarta){
					cout << "Erro ao obter carta de monte.\n";
					exit(1);
				}
				adicionar(cartaAuxiliar,okEmpilha);
				if(!okEmpilha){
					cout << "Erro ao empilhar carta.\n";
					exit(1);
				}
			}
			bool ok;
			monteDaCarta->remover(posicaoDaCarta, okGetcarta);
			if(!okGetcarta){
				cout << "Erro ao remover cartas.\n";
				exit(1);
			}
			
			ok = true;
		} else
			ok = false;
	} else {
		CARTA * cNova = monteDaCarta->getCarta(posicaoDaCarta, okGetcarta);
		if(!okGetcarta){
			cout << "Erro ao tentar obter carta.\n";
		}
		
		if(cNova->getValor()==13){
			for(int i=posicaoDaCarta; i<monteDaCarta->getTamanho(); i++){
				CARTA * cartaAuxiliar = NULL;
				cartaAuxiliar = monteDaCarta->getCarta(i,okGetcarta);
				if(!okGetcarta){
					cout << "Erro ao tentar obter carta.\n";
				}
				
				pilha->empilha(cartaAuxiliar, okEmpilha);
				if(!okEmpilha){
					cout << "Erro ao empilhar carta.\n";
				}
			}
			monteDaCarta->remover(posicaoDaCarta, okDesempilha);
			if(!okDesempilha){
				cout << "Erro ao remover carta.\n";
			}
			ok = true;
		} else
			ok = false;
	}
}

void MONTE::esvaziar(){
	bool ok;
	while(getTamanho()){
		pilha->desempilha(ok);
		if(!ok){
			cout << "Erro ao esvaziar.\n";
			exit(1);
		}
	}
}
