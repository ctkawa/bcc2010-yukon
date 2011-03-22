#include <iostream>
#include "pilha.h"

using namespace std;

class MONTE {
private:
	PILHA pilha;
public:
	int getTamanho();
	CARTA getCarta( int );
	bool add( CARTA );
	bool remover( int );
	bool setVisivelTrue( int );
	bool receberCartas( MONTE, int );
};

ostream& operator<<(ostream&, MONTE);