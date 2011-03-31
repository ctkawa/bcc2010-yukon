#include "yukonCLI.h"

YUKON_CLI::YUKON_CLI()
	: YUKON()
{
	
}

int YUKON_CLI::run(){
	
	int estado = 1;
	string comando;
	string mensagem = "Jogo começou";
	
	do {
	
		imprimeCartas();
		cout << endl << ">> ";
		cin >> comando;
		switch( interpretar(comando) ){
			case 0:
				estado=1;
				mensagem = "Movendo...";
				break;
			case 1:
				estado=2;
				mensagem = "Erro de interpretação.";
				break;
			case 3:
				estado=0;
				cout << "Fechando jogo..." << endl;
				break;
		}
	} while (estado != 0);
	
	return 0;
}

void YUKON_CLI::imprimeCartas(){
	
	//impressão de número de colunas
	cout << "\t";
	for (int cnt=0;cnt<7;cnt++){
		cout << "__" << cnt << "__" << "\t";
	}
	cout << endl;
	
	int i,j;
	//Verificar e CORRIGIR o tamanho mínimo de uma coluna e substituir o valor final de "i"
	for(i=0;i<=10;i++){
		cout << "  " << i; // linha
		if (i<10)
			cout << " ";
		cout << "|" << "\t";
		for(j=0;j<=6;j++){
			if(getMonteTam(j) >= i+1)
				cout << getMonteCarta(j,i) << "\t";
			else
				cout << "\t";
		}                  
		cout << "|" << i << endl;
		
	}
	
	if(getFundacao(0) == 0)
		cout << "[♡,  ] ";
	else
		cout << "[♡, " << getFundacao(0) << "] ";
	if(getFundacao(1) == 0)
		cout << "[♢,  ] ";
	else
		cout << "[♢, " << getFundacao(1) << "] ";
	if(getFundacao(2) == 0)
		cout << "[♠,  ] ";
	else
		cout << "[♠, " << getFundacao(2) << "] ";
	if(getFundacao(3) == 0)
		cout << "[♣  ] ";
	else
		cout << "[♣, " << getFundacao(3) << "] ";
	
	cout << endl;
}

/*
 * m *over
 * ajuda/sobre
 */

//interpretacao e execucao de comando
//forma <pilha_origem>,<posicao_origem>,<pilha_destino>, em numero
int YUKON_CLI::interpretar(string cmd){
	
	if (cmd == "")
		return 2;
	if (cmd=="fechar")
		return 3;
	
	int origemp;	//pilha de origem
	int origemc;	//carta de origem
	int destino;	//pilha de destino
	
	unsigned int posvirg1 = cmd.find(",");	//posicao da 1a virgula
	unsigned int posvirg2 = cmd.rfind(",");	//posicao da 2a (ultima) virgula
	if ((posvirg1 != string::npos)&&(posvirg2 != string::npos)){	//se foi obtido posicao das duas virgulas, faca:
		origemp = atoi((cmd.substr(0,posvirg1)).data());
		origemc = atoi((cmd.substr(posvirg1+1,posvirg2-posvirg1)).data());
		destino = atoi((cmd.substr(posvirg2+1,cmd.size()-posvirg2)).data());
		
	}
	else{
		cout << "formato de comando incorreto!" << endl;
		return 1;
	}
	
	if (origemp>7||origemp<0||destino>8||destino<0) {
		cout << "origem ou destino e incorreto!" << endl;
		return 1;
	}
	if (getMonteTam(origemp)<0)
		cout << "monte nao possui nenhuma carta!";
	if(origemp == origemc)
		cout<< "Coluna de origem igual coluna de destino";
	else
		if (mover(origemp, origemc, destino)){
			cout <<"Movendo carta "<<origemc<<" da pilha "<<origemp<<" para a pilha "<<destino << endl;
		} else
			cout << "Esse movimento nao eh possivel."<<endl;
		
		
		
		/*cout << "pos1=" << posvirg1 << endl;
		 * cout << "pos2=" << posvirg2 << endl;*/
		return 0;
}
