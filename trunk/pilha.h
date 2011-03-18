class PILHA{
private:
	CARTA cartas[52];
	int tamanhoAtual;
public:
	PILHA();
	int getTamanho();
	CARTA getCarta( int );
	bool add( CARTA );
}; 
