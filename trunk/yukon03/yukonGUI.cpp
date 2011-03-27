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
	principal->setLayout(hbox);
	
	QLabel * texto1 = new QLabel("Monte 1");
	hbox->addWidget(texto1);
	
	QLabel * texto2 = new QLabel("Monte 2");
	hbox->addWidget(texto2);
	
	QLabel * texto3 = new QLabel("Monte 3");
	hbox->addWidget(texto3);
	
	QLabel * texto4 = new QLabel("Monte 4");
	hbox->addWidget(texto4);
	
	QLabel * texto5 = new QLabel("Monte 5");
	hbox->addWidget(texto5);
	
	QLabel * texto6 = new QLabel("Monte 6");
	hbox->addWidget(texto6);
	
	QLabel * texto7 = new QLabel("Monte 7");
	hbox->addWidget(texto7);
	
	QLabel * texto8 = new QLabel("Fundacao");
	hbox->addWidget(texto8);
}

void YUKON_GUI::coisa(){
	cout << "ops!";
}
