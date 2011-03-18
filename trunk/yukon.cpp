#include <iostream>
#include <stdlib.h>
#include <time.h>

// editei
// editei x2

using namespace std;

//== CARTA ===========================================

class CARTA{
	// o construtor de BARALHO precisa de acesso direto para modificar as cartas
	friend class BARALHO;
private:
	int valor; // 1 a 13 onde 11 = J, 12 = Q e 13 = K, interpretados pela interface
	char naipe; // C (copas), P (paus), E (espadas), O (ouros)
	bool visivel;
	bool setValor( int ); // valida atribuição
	bool setNaipe( char ); // valida atribuição
public:
	CARTA( int, char, bool ); // construtor
	CARTA( const CARTA& ); // construtor de cópia
	CARTA operator=( CARTA ); // sobrecarga da atribuição
	int getValor();
	char getNaipe();
	bool getVisivel();
	bool setVisivel( bool ); // seleciona a visibilidade
	bool virar(); // troca a visibilidade
};

bool CARTA::setValor( int v ){
	// verifica se está entre 1 e 13
	if( 0<v && v<=13){
		valor = v;
		return 0;
	}

	// valor padrão para 1
	valor = 1;
	return 1;
}

bool CARTA::setNaipe( char n ){
	// verifia se o naipe sugerido é válido
	if( n == 'C' || n == 'P' || n == 'E' || n == 'O' ){
		naipe = n;
		return 0;
	}

	// valor padrão para copas
	naipe = 'C';
	return 1;
}

CARTA::CARTA( int val=1, char nai='O', bool vis=false){
	setValor(val);
	setNaipe(nai);
	visivel = vis;
}

CARTA::CARTA( const CARTA &c ){
	valor = c.valor;
	naipe = c.naipe;
	visivel = c.visivel;
}

CARTA CARTA::operator=( CARTA c ){
	valor = c.getValor();
	naipe = c.getNaipe();
	visivel = c.getVisivel();

	return *this;
}

int CARTA::getValor(){
	// retorna apenas se estiver visivel
	if( visivel )
		return valor;
	else
		return 0;
}

char CARTA::getNaipe(){
	// retorna apenas se estiver visivel
	if( visivel )
		return naipe;
	else
		return 0;
}

bool CARTA::getVisivel(){
	return visivel;
}

bool CARTA::setVisivel( bool v){
	visivel = v;
	return visivel;
}

bool CARTA::virar(){
	// inverte a visibilidade
	visivel = !visivel;
	return visivel;
}


// sobrecarga da impressão
ostream &operator<<(ostream & out, CARTA c ){
	// imprime de acordo cm a visibilidade
	if(c.getVisivel())
		out << "[" << c.getNaipe() << ", " << c.getValor() << "]";
	else
		out << "[?, ?]";

	return out;
}

//== BARALHO ===========================================

class BARALHO{
private:
	CARTA cartas[52]; // espaço para todas as cartas
	int tamanhoAtual; // posição atual
	int removerCarta( int ); // remove uma carta
public:
	BARALHO(); // construtor
	CARTA getCartaRand(); // retira uma carta numa posição aleatória
};

BARALHO::BARALHO(){
	int carta, valor;

	valor = 0;
	for(carta=0; carta<52; carta++){
		cartas[carta].valor = carta%13 + 1;
		if(carta < 13) cartas[carta].naipe = 'O';
		else if(carta < 26) cartas[carta].naipe = 'C';
		else if(carta < 39) cartas[carta].naipe = 'P';
		else cartas[carta].naipe = 'E';
		valor++;
	}

	tamanhoAtual = 51;
}

CARTA BARALHO::getCartaRand(){
	// seleciona semente
	srand( time(NULL) );
	// recebe valor inteiro aleatório menos que o tamanhoAtual
	int r = rand() % tamanhoAtual;
	// guarda o valor
	CARTA c = cartas[r];
	// remove carta
	removerCarta(r);
	// retorna carta guardada
	return c;
}

int BARALHO::removerCarta( int posicao ){
	// verifica validade de posicao
	if( posicao < 0 || posicao > tamanhoAtual )
		return 1;

	int carta;
	for(carta=posicao; carta<tamanhoAtual; carta++)
		// reposiciona as cartas
		cartas[carta] = cartas[carta + 1];
	tamanhoAtual--;

	return 0;
}

//== PILHA ===========================================

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

PILHA::PILHA(){
	tamanhoAtual = 0;
}

int PILHA::getTamanho(){
	return tamanhoAtual;
}

CARTA PILHA::getCarta( int posicao ){
	cout << cartas[posicao] << endl;
	if(0<=posicao && posicao <=tamanhoAtual)
		return cartas[posicao];
	else
		return 0;
}

bool PILHA::add( CARTA c){
	if(tamanhoAtual < 52){
		cartas[tamanhoAtual] = c;
		tamanhoAtual++;
		return true;
	}
	else
		return false;
}

ostream &operator<<( ostream & out, PILHA p){
	for(int carta=0; carta<p.getTamanho(); carta++)
		out << p.getCarta(carta) << endl;

	return out;
}

//== MAIN ===========================================

int main(){

	BARALHO baralho;
	PILHA pilhas[7];

	CARTA c;
	c = baralho.getCartaRand();
	c.setVisivel(true);
	pilhas[0].add(c);
	cout << pilhas[0];

	for(int pilha=1; pilha<7; pilha++){
		int p;
		for(p=0; p<pilha; p++){
			c = baralho.getCartaRand();
			c.setVisivel(false);
			pilhas[pilha].add(c);
		}
		cout << "ops\n";
		for(p=0; p<5; p++){
			c = baralho.getCartaRand();
			c.setVisivel(true);
			pilhas[pilha].add(c);
		}

		cout << pilhas[pilha];
	}

	return 0;
}
