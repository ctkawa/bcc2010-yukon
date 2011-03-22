#include "yukonCLI.h"

YUKON_CLI::YUKON_CLI(){
	imprimeCartas();
	
	string comando;
	cout << ">> ";
	cin >> comando;
	
	interpretar(comando);
	imprimeCartas();
}



void YUKON_CLI::imprimeCartas(){
	
	int i,j;
	//Verificar e CORRIGIR o tamanho mínimo de uma coluna e substituir o valor final de "i"
	for(i=0;i<=10;i++){
		for(j=0;j<=6;j++){
			if(yukon.getMonteTam(j) >= i+1)
				cout << yukon.getMonteCarta(j,i) << "\t";
			else
				cout << "\t";
		}                  
		cout<<endl;
		
	}
	
	if(yukon.getFundacao(0) == 0)
		cout << "[C,  ] ";
	else
		cout << "[C, " << yukon.getFundacao(0) << "] ";
	if(yukon.getFundacao(1) == 0)
		cout << "[O,  ] ";
	else
		cout << "[O, " << yukon.getFundacao(1) << "] ";
	if(yukon.getFundacao(2) == 0)
		cout << "[E,  ] ";
	else
		cout << "[E, " << yukon.getFundacao(2) << "] ";
	if(yukon.getFundacao(3) == 0)
		cout << "[P  ] ";
	else
		cout << "[P, " << yukon.getFundacao(3) << "] ";
	
	cout << endl;
}

/*
 * m *over
 * ajuda/sobre
 */

//interpretacao e execucao de comando
//forma <pilha_origem>,<posicao_origem>,<pilha_destino>, em numero
int YUKON_CLI::interpretar(string cmd){
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
	if (yukon.getMonteTam(origemp)<0)
		cout << "monte nao possui nenhuma carta!";
	if(origemp == origemc)
		cout<< "Coluna de origem igual coluna de destino";
	else
		if (yukon.mover(origemp, origemc, destino)){
			cout <<"Movendo carta "<<origemc<<" da pilha "<<origemp<<" para a pilha "<<destino << endl;
		} else
			cout << "Esse movimento nao eh possivel."<<endl;
		
		
		
		/*cout << "pos1=" << posvirg1 << endl;
		 * cout << "pos2=" << posvirg2 << endl;*/
		return 0;
}
