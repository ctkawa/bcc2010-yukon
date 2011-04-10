#include "monte.h"

class FUNDACAO {
private:
	int montes[4];
public:
	FUNDACAO();
	int getMonte( int );
	void receberCarta( MONTE *, bool& );
	void esvaziar();
}; 
