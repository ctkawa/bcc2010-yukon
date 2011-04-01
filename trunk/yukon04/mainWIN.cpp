#include <iostream>
#include "yukonCLI.h"

using namespace std;

int main (int argc, char *argv[]){
	
	cout << argc << endl;		// reconhecer argumentos de execucao
	for(int i=0; i<argc; i++)
		cout << argv[i] << endl;
	
	YUKON * y;
	y = new YUKON_CLI(); // executar modo texto
	
	
	return y->run();			// iniciar jogo

	cout << "Fechando jogo...";
}
