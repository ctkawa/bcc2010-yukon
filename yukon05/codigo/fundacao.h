#include "monte.h"

class FUNDACAO {
private:
	int montes[4];	// 0 significa que nao ha carta, 13 é K
public:
	FUNDACAO();
	int getMonte( int );
	void receberCarta( MONTE *, bool& );
	void esvaziar();
}; 
