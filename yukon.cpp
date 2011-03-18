#include <iostream>
#include "carta.h"
#include "baralho.h"
#include "pilha.h"

using namespace std;

ostream &operator<<(ostream & out, CARTA c ){
	// imprime de acordo cm a visibilidade
	if(c.getVisivel())
		out << "[" << c.getNaipe() << ", " << c.getValor() << "]";
	else
		out << "[?, ?]";
	
	return out;
}


ostream &operator<<( ostream & out, PILHA p){
	for(int carta=0; carta<p.getTamanho(); carta++)
		out << p.getCarta(carta) << " ";
	
	return out;
}



/*
mover
ajuda/sobre
*/

//interpretacao e execucao de comando
//forma <origem>-<destino>, em numero
int interpretar(string cmd){
	
	int origem = atoi((cmd.substr(0,1)).data());
	int destino = atoi(cmd.substr(2,1).data());

	cout <<"mv "<<origem<<" to "<<destino << endl;
	return 0;
}


int main (){

	BARALHO baralho;
	PILHA pilhas[7];
	CARTA c;
	
	int i,j;
	for(i=1;i<=6;i++){
       for(j=1;j<=i;j++){
          c=baralho.getCartaRand();
          pilhas[i].add(c);
          }
             for(j=1;j<=5;j++){
         c=baralho.getCartaRand();
         c.setVisivel(true);
         pilhas[i].add(c); 
       } 
    }


	// Primeira pilha
	c=baralho.getCartaRand();

    c.setVisivel(true);      
    pilhas[0].add(c);


    //Verificar o tamanho máximo de uma coluna e substituir o "i"
    for(i=0;i<=10;i++){
       for(j=0;j<=6;j++){
          if(pilhas[j].getTamanho()>= i+1)
             cout<<pilhas[j].getCarta(i) << "\t";
          else
              cout << "\t";
       }                  
       cout<<endl;
    }
        
       
    

	
	string comando;
	cout << ">> ";
    cin >> comando;
	

	return 0;
}
