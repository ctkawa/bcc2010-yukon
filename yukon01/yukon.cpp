#include <iostream>
#include "carta.h"
#include "baralho.h"
#include "monte.h"
#include "fundacao.h"

using namespace std;

ostream &operator<<(ostream & out, CARTA c ){
	// imprime de acordo cm a visibilidade
	if(c.getVisivel()) {
		out << "[" ;
		if (c.getNaipe()=='C'){
		  out << "♡";}			// se nao tiver visivel usar ♥ e ♦
		else if (c.getNaipe()=='O'){
		  out << "♢";}
		else if (c.getNaipe()=='P'){
		  out << "♣";}
		else if (c.getNaipe()=='E'){
		  out << "♠";}
		else{
		  cout << "tem algo errado na carta...";}
		if (c.getValor()<10)
		  out << " ";
		out << c.getValor() << "]";
	} else
		out << "[?,?]";
	return out;
}

ostream &operator<<( ostream & out, MONTE p){
	for(int carta=0; carta<p.getTamanho(); carta++)
		out << p.getCarta(carta) << " ";
	
	return out;
}



/*
mover
ajuda/sobre
*/

//interpretacao e execucao de comando
//forma <pilha_origem>,<posicao_origem>,<pilha_destino>, em numero
/*
	retornos de interpretar:
	0 - interpretado correto
	1 - erro de interpretacao
	2 - comando ignorado
	3 - fechando jogo
*/
int interpretar(string cmd, MONTE *pilhas){
	
	if (cmd == "")
		return 2;
	if (cmd=="fechar")
		return 3;

	int origemp;	//pilha de origem
	int origemc;	//carta de origem
	int destino;	//pilha de destino

unsigned int pas not declared in this scosvirg1 = cmd.find(",");	//posicao da 1a virgula
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
	if (pilhas[origemp].getTamanho()<0)
		cout << "monte nao possui nenhuma carta!";
	if(origemp == origemc)
	   cout<< "Coluna de origem igual coluna de destino";
    else
	   if (pilhas[destino].receberCartas(pilhas[origemp],origemc)){
	      pilhas[origemp].remover(origemc);
	      cout <<"Movendo carta "<<origemc<<" da pilha "<<origemp<<" para a pilha "<<destino << endl;
	   } else
	       cout << "Esse movimento nao é possivel."<<endl;
	   
	
	
	/*cout << "pos1=" << posvirg1 << endl;
	cout << "pos2=" << posvirg2 << endl;*/
	return 0;
}

void embaralhaCartas(BARALHO *baralho, MONTE *pilhas){
     CARTA c;
	int i,j;
	for(i=1;i<=6;i++){
	  for(j=1;j<=i;j++){
	    c=baralho->getCartaRand();
	    pilhas[i].add(c);
          }
          for(j=1;j<=5;j++){
	    c=baralho->getCartaRand();
	    c.setVisivel(true);
	    pilhas[i].add(c); 
	  } 
	}
	// Carta da primeira pilha
	c=baralho->getCartaRand();

    c.setVisivel(true);      
    pilhas[0].add(c);
     }

void imprimeCartas(BARALHO baralho, MONTE pilhas[7], FUNDACAO fundacao){
	//impressão de número de colunas
	cout << "\t";
	for (int cnt=0;cnt<7;cnt++){
		cout << "__" << cnt << "__" << "\t";
	}
	cout << endl;

     int i,j;
    //Verificar e CORRIGIR o tamanho mínimo de uma coluna e substituir o valor final de "i"
    for(i=0;i<=10;i++){	// linha
	cout << "  " << i;
	if (i<10)
		cout << " ";
	cout << "|" << "\t";
       for(j=0;j<=6;j++){	// coluna
          if(pilhas[j].getTamanho()>= i+1)
             cout<<pilhas[j].getCarta(i) << "\t";
          else
              cout << "\t";
       }                  
       cout << "| " << i << endl;
     
     }
     
    if(fundacao.getMonte(0) == 0)
		cout << "[C,  ] ";
	else
		cout << "[C, " << fundacao.getMonte(0) << "] ";
	if(fundacao.getMonte(1) == 0)
		cout << "[O,  ] ";
	else
		cout << "[O, " << fundacao.getMonte(1) << "] ";
	if(fundacao.getMonte(2) == 0)
		cout << "[E,  ] ";
	else
		cout << "[E, " << fundacao.getMonte(2) << "] ";
	if(fundacao.getMonte(3) == 0)
		cout << "[P  ] ";
	else
		cout << "[P, " << fundacao.getMonte(3) << "] ";
	
	cout << endl;
}

int main (){

// variaveis
	BARALHO baralho;
	MONTE pilhas[7];
	FUNDACAO fundacao;
	string comando;
	int turno = 0;
	string mensagem = "Jogo começou";
	int estado = 1;
	int ret_interpretar;
	
// inicializacao de jogo
	embaralhaCartas(&baralho,&pilhas[0]);

	do {
		cout << "Turno: " << turno << "\t" << mensagem << endl;
		imprimeCartas(baralho,pilhas,fundacao);
		cout << endl << ">> ";
	    	cin >> comando;
		ret_interpretar = interpretar(comando,&pilhas[0]);
		switch (ret_interpretar){
			case 0:
				estado=1;
				mensagem == "Movendo...";
				break;
			case 1:
				estado=2;
				mensagem == "Erro de interpretação.";
				break;				
			case 3:
				cout << "Fechando jogo..." << endl;
				estado =0;
				break;

		}

	} while (estado != 0);

	return 0;
}

/*
para 'estado':
	0=fim do jogo
	1=comando interpretado
	2=comando incorreto
*/

