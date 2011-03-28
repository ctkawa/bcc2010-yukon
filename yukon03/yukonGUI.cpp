#include "yukonGUI.h"

#include <iostream>
using namespace std;

YUKON_GUI::YUKON_GUI()
	: YUKON(), QObject()
{

}

int YUKON_GUI::run(int argc, char *argv[]){
	
	app = new QApplication(argc, argv);
	window = new QMainWindow();
	
	menu();
	toolbar();
	status();
	principal();
	
	window->show();
	return app->exec();
}

void YUKON_GUI::menu(){
	QMenuBar * mb = window->menuBar();
	
	QMenu * menuArquivo = mb->addMenu("&Arquivo");
	
	QAction * acaoTamanho = new QAction("&Tamanho", app);
	connect(
		acaoTamanho, SIGNAL(triggered()),
		this, SLOT(coisa())
	);
	
	menuArquivo->addAction(acaoTamanho);
	
}

void YUKON_GUI::toolbar(){
	QToolBar * tb = window->addToolBar("Padrao");
	
	QAction * acaoNovo = new QAction("Novo", app);
	tb->addAction(acaoNovo);
}

void YUKON_GUI::status(){
	QStatusBar * sb = window->statusBar();
	
	sb->showMessage("Status Bar");
}

void YUKON_GUI::principal(){
	
	QFrame * principal = new QFrame();
	window->setCentralWidget(principal);
	
	QHBoxLayout * hbox = new QHBoxLayout();
	principal->setLayout(hbox);
	
	QWidget * w;
	QLabel * box;
	
	for(int i=0; i<7; i++){
		w = new QWidget();
		hbox->addWidget(w);
		
		for(int j=0; j<getMonteTam(i); j++){
			
			box = getImagemCarta(w, getMonteCarta(i,j));
			box->setGeometry(0, j*20, 30, 30);
			box->show();
		}
	}
	
	QLabel * texto8 = new QLabel("Fundacao");
	hbox->addWidget(texto8);
}


QLabel * YUKON_GUI::getImagemCarta(QWidget *w, CARTA c){
	QHBoxLayout * box = new QHBoxLayout();
	
	QLabel * naipe = new QLabel(w);
	
	if(c.getNaipe() == 'P')
		naipe->setPixmap(
			QPixmap("figuras/paus.png").scaled(30,30)
		);
	else if(c.getNaipe() == 'E')
		naipe->setPixmap(
			QPixmap("figuras/espadas.png").scaled(30,30)
		);
	else if(c.getNaipe() == 'C')
		naipe->setPixmap(
			QPixmap("figuras/copas.png").scaled(30,30)
		);
	else if(c.getNaipe() == 'O')
		naipe->setPixmap(
			QPixmap("figuras/ouros.png").scaled(30,30)
		);
	else
		naipe->setPixmap(
			QPixmap("figuras/0p.png").scaled(30,30)
		);
	
	box->addWidget(naipe);
	
	QLabel * valor = new QLabel();
	
	char s[50] = "" ;
	sprintf(s, "figuras/%dp.png", c.getValor());
	
	valor->setPixmap(
		QPixmap(s).scaled(30,30)
	);
	box->addWidget(valor);
			
	return naipe;
}

void YUKON_GUI::coisa(){
	cout << "ops!";
}
