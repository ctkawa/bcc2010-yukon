#include <iostream>
#include "codigo/yukonCLI.h"
#include "codigo/yukonGUI.h"

using namespace std;


int main (int argc, char *argv[]){
	
	cout << argc << endl;		// reconhecer argumentos de execucao
	for(int i=0; i<argc; i++)
		cout << argv[i] << endl;
	
	YUKON * y;
	
	if( argc > 1 && !strcmp(argv[1], "t") )	// escolher modo de execucao
		y = new YUKON_CLI();
	else
		y = new YUKON_GUI(argc, argv);
	
	return y->run();			// iniciar jogo

	cout << "Fechando jogo...";
}
