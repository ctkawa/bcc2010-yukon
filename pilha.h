using namespace std;

class PILHA{
private:
	CARTA cartas[52];
	int tamanhoMax;
	int tamanhoAtual;
public:
	PILHA();
	int getTamanho();
	CARTA getCarta( int );
	bool add( CARTA );
}; 
