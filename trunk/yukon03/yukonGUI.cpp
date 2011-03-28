#include "yukonGUI.h"

#include <iostream>
using namespace std;

YUKON_GUI::YUKON_GUI()
	: YUKON(), QObject()
{
	deMonte = -1;
	deCarta = -1;
}

int YUKON_GUI::run(int argc, char *argv[]){
	
	app = new QApplication(argc, argv);
	window = new QMainWindow();
	
	window->setGeometry(100, 100, 800, 600);
	
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
	
	QWidget *p = new QWidget(window);
	
	window->setCentralWidget(p);
	
	QHBoxLayout * hbox = new QHBoxLayout();
	p->setLayout(hbox);
	
	QWidget * w;
	GUI_CARTA * box;
	
	for(int i=0; i<7; i++){
		w = new QWidget();
		hbox->addWidget(w);
		
		for(int j=0; j<getMonteTam(i); j++){
			box = new GUI_CARTA(this, w, i, j);
			box->setCarta(getMonteCarta(i,j));
			box->show();
		}
	}
	
	GUI_FUNDACAO * fundacao = new GUI_FUNDACAO(this);
	hbox->addWidget(fundacao);
}

bool YUKON_GUI::isSetDe(){
	if(deMonte != -1 && deCarta != -1)
		return true;
	return false;
}

void YUKON_GUI::setDe(int monte, int carta){
	if(0<=monte && monte < 7 && 0<=carta && carta<=getMonteTam(monte)){
		deMonte = monte;
		deCarta = carta;
		
		char s[50];
		sprintf(s, "Selecinada carta %d do monte %d.", carta, monte);
		window->statusBar()->showMessage(s);
	}
}

void YUKON_GUI::limpaDe(){
	deMonte = -1;
	deCarta = -1;
}

void YUKON_GUI::movimenta(int monte){
	if(isSetDe()){
		if(mover(deMonte, deCarta, monte)){
			QString s = "Movido com sucesso";
			window->statusBar()->showMessage(s, 5000);
		} else
			window->statusBar()->showMessage("Movimento inválido", 5000);
		
		principal();
	}
	limpaDe();
}

void YUKON_GUI::coisa(){
	cout << "ops!";
}

// =============================

GUI_CARTA::GUI_CARTA(YUKON_GUI * y, QWidget * w, int m, int c)
	: QLabel(w)
{
	monte = m;
	ordem = c;
	yukon = y;
	
	setGeometry(0, ordem*20, 100, 100);
}

void GUI_CARTA::setCarta(CARTA c){
	
	if(c.getNaipe() && c.getValor()){
		char endereco[50];
		sprintf(endereco, "./figuras/classic-cards/%c%d.png", c.getNaipe(), c.getValor() );
		setPixmap(QPixmap(endereco));
	}
	else if( c.getCor() )
		setPixmap(QPixmap("./figuras/classic-cards/CostasRed.png"));
	else
		setPixmap(QPixmap("./figuras/classic-cards/CostasBlack.png"));
}

void GUI_CARTA::mouseReleaseEvent( QMouseEvent * ev){
	if (ev->button() == Qt::LeftButton){
		if(yukon->isSetDe())
			yukon->movimenta(monte);
		else
			yukon->setDe(monte, ordem);
	}
}

GUI_FUNDACAO::GUI_FUNDACAO(YUKON_GUI * y)
	: QWidget()
{
	yukon = y;
	
	char naipes[4];
	naipes[0] = 'C';
	naipes[1] = 'O';
	naipes[2] = 'E';
	naipes[3] = 'P';
	
	QVBoxLayout * vbox = new QVBoxLayout();
	this->setLayout(vbox);
	QLabel * c;
	
	for(int i=0; i<4; i++){
		c = new QLabel(this);
		if(yukon->getFundacao(i)){
			char s[50];
			sprintf(s, "./figuras/classic-cards/%c%d.png", naipes[i], yukon->getFundacao(i) );
			c->setPixmap(QPixmap(s));
		} else if(i<2){
			c->setPixmap(
				QPixmap("./figuras/classic-cards/CostasRed.png")
			);
		}
		else {
				c->setPixmap(
					QPixmap("./figuras/classic-cards/CostasBlack.png")
				);
		}
		vbox->addWidget(c);
	}
}
