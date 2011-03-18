#include <iostream>
#include "carta.h"
#include "baralho.h"
#include "monte.h"

using namespace std;

ostream &operator<<(ostream & out, CARTA c ){
	// imprime de acordo cm a visibilidade
	if(c.getVisivel())
		out << "[" << c.getNaipe() << ", " << c.getValor() << "]";
	else
		out << "[?, ?]";
	
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
int interpretar(string cmd){
	int origemp;	//pilha de origem
	int origemc;	//carta de origem
	int destino;	//pilha de destino

	int posvirg1 = cmd.find(",");	//posicao da 1a virgula
	int posvirg2 = cmd.rfind(",");	//posicao da 2a (ultima) virgula
	if ((posvirg1 != string::npos)&&(posvirg2 != string::npos)){	//se foi obtido posicao das duas virgulas, faca:
		origemp = atoi((cmd.substr(0,posvirg1)).data());
		origemc = atoi((cmd.substr(posvirg1+1,posvirg2-posvirg1)).data());
		destino = atoi((cmd.substr(posvirg2+1,cmd.size()-posvirg2)).data());
		
	}
	else{
		cout << "formato de comando incorreto!" << endl;
		return 1;
	}
	if (origemp>7||origemp<1||destino>8||destino<1) {
		cout << "origem ou destino é incorreto!";
		return 1;
	}
	if (pilhas[origemp].getTamanho()<1){
		cout <<　"monte não possui nenhuma carta!"
	}
	
	
	
	cout <<"Movendo carta "<<origemc<<" da pilha "<<origemp<<" para a pilha "<<destino << endl;
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


	// Primeira pilha
	c=baralho->getCartaRand();

    c.setVisivel(true);      
    pilhas[0].add(c);
     }

void imprimeCartas(BARALHO baralho, MONTE pilhas[7]){
     int i,j;
    //Verificar e CORRIGIR o tamanho mínimo de uma coluna e substituir o valor final de "i"
    for(i=0;i<=10;i++){
       for(j=0;j<=6;j++){
          if(pilhas[j].getTamanho()>= i+1)
             cout<<pilhas[j].getCarta(i) << "\t";
          else
              cout << "\t";
       }                  
       cout<<endl;
     
     }
}

int main (){

	BARALHO baralho;
	MONTE pilhas[7];
	
    embaralhaCartas(&baralho,&pilhas[0]);
    imprimeCartas(baralho,pilhas);
	
	string comando;
	cout << ">> ";
    	cin >> comando;
	interpretar(comando);
	

	return 0;
}
