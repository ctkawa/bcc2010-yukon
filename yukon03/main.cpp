#include <iostream>
#include "yukonCLI.h"
#include "yukonGUI.h"

using namespace std;


int main (int argc, char *argv[]){
	
	cout << argc << endl;
	for(int i=0; i<argc; i++)
		cout << argv[i] << endl;
	
	YUKON *y;
	
	if( argc > 1 && !strcmp(argv[1], "g") )
		y = new YUKON_GUI();
	else
		y = new YUKON_CLI();
	
	return y->run(argc, argv);
}