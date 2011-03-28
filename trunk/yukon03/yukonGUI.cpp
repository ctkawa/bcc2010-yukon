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
	
	QWidget * principal = new QWidget();
	window->setCentralWidget(principal);
	
	QHBoxLayout * hbox = new QHBoxLayout();
	hbox->setSpacing(0);
	principal->setLayout(hbox);
	
	for(int i=0; i<7; i++){
		QWidget * w = new QWidget();
		hbox->addWidget(w);
		
		QVBoxLayout * vbox = new QVBoxLayout();
		w->setLayout(vbox);
		
		//QPoint p(0,0);
		for(int j=0; j<getMonteTam(i); j++){
			QWidget * w2 = new QWidget();
			vbox->addWidget(w2);
			w2->move(0, 0);
			
			QHBoxLayout * box = new QHBoxLayout();
			w2->setLayout(box);
			
			QLabel * naipe = new QLabel();
			naipe->setPixmap(
				QPixmap(QString("figuras/paus.png"))
			);
			box->addWidget(naipe);
			
			QLabel * valor = new QLabel();
			valor->setPixmap(
				QPixmap(QString("figuras/1p.png"))
			);
			box->addWidget(valor);
		}
	}
	
	QLabel * texto8 = new QLabel("Fundacao");
	hbox->addWidget(texto8);
}



void YUKON_GUI::coisa(){
	cout << "ops!";
}
