all:
	g++ -Wall -c carta.cpp -o carta.o
	g++ -Wall -c baralho.cpp -o baralho.o
	g++ -Wall -c pilha.cpp -o pilha.o
	g++ -Wall -c yukon.cpp -o yukon.o
	g++ -Wall -c monte.cpp -o monte.o
	g++ -Wall yukon.o carta.o baralho.o pilha.o monte.o -o yukon.linux

