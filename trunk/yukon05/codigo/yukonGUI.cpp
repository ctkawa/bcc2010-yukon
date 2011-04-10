#include "yukonGUI.h"

#include <iostream>
using namespace std;

YUKON_GUI::YUKON_GUI(int argc, char *argv[])
	: YUKON(), QApplication(argc, argv)
{
	monteOrigem = -1;
	cartaOrigem = -1;
}

int YUKON_GUI::run(){
	
	window = new QMainWindow();
	
	window->setGeometry(100, 100, 800, 600);
	
	menu();
	toolbar();
	status(NULL);
	principal();
	
	window->show();
	return exec();
}

void YUKON_GUI::menu(){
	QMenuBar * mb = window->menuBar();
	
	QMenu * menuArquivo = mb->addMenu("&Arquivo");
	
	QAction * acaoTamanho = new QAction("&Tamanho", this);
	connect(
		acaoTamanho, SIGNAL(triggered()),
		this, SLOT(coisa())
	);
	
	menuArquivo->addAction(acaoTamanho);
	
}

void YUKON_GUI::toolbar(){
	QToolBar * tb = window->addToolBar("Padrao");
	
	QAction * acaoNovo = new QAction("Novo", this);
	tb->addAction(acaoNovo);
}

void YUKON_GUI::status(char * texto = NULL){
	QStatusBar * sb = window->statusBar();
	
	sb->showMessage(texto);
}

void YUKON_GUI::principal(){
	
	bool ok;
	
	GUI_PRINCIPAL *p = new GUI_PRINCIPAL(this, window);
	
	window->setCentralWidget(p);
	
	QHBoxLayout * hbox = new QHBoxLayout();
	p->setLayout(hbox);
	
	QWidget * w;
	MONTE * monte;
	GUI_CARTA * carta;
	GUI_VAZIO * vazio;
	
	for(int i=0; i<7; i++){
		w = new QWidget();
		hbox->addWidget(w);
		
		vazio = new GUI_VAZIO(this, w, i);
		vazio->show();
		
		monte = getMonte(i);
		
		for(int j=0; j<monte->getTamanho(); j++){
			carta = new GUI_CARTA(this, w, i, j);
			carta->setCarta(monte->getCarta(j,ok));
			carta->show();
		}
	}
	
	GUI_FUNDACAO * fundacao = new GUI_FUNDACAO(this);
	hbox->addWidget(fundacao);
}

bool YUKON_GUI::isSetDe(){
	if(monteOrigem != -1 && cartaOrigem != -1)
		return true;
	return false;
}

void YUKON_GUI::setDe(int monte, int carta){
	MONTE * monteAuxiliar = getMonte(monte);
	if(0<=monte && monte < 7 && 0<=carta && carta<=monteAuxiliar->getTamanho()){
		monteOrigem = monte;
		cartaOrigem = carta;
		
		char s[50];
		sprintf(s, "Selecinada carta %d do monte %d.", carta, monte);
		window->statusBar()->showMessage(s);
	}
}

void YUKON_GUI::limpaDe(){
	monteOrigem = -1;
	cartaOrigem = -1;
}

void YUKON_GUI::movimenta(int monte){
	bool ok;
	
	if(isSetDe()){
		MONTE * monteAuxiliar = getMonte(monte);
		monteAuxiliar->receberCartas(getMonte(monteOrigem), cartaOrigem, ok);
		if(ok){
			QString s = "Movido com sucesso";
			window->statusBar()->showMessage(s, 5000);
		} else
			window->statusBar()->showMessage("Movimento inválido", 5000);
		
		principal();
	}
	limpaDe();
}

void YUKON_GUI::movimentaParaFundacao(){
	bool ok;
	if(isSetDe()){
		fundacao.receberCarta(getMonte(monteOrigem), ok);
		if(ok){
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

GUI_PRINCIPAL::GUI_PRINCIPAL( YUKON_GUI * y, QWidget * window)
	: QWidget(window)
{
	yukon = y;
}

void GUI_PRINCIPAL::mouseReleaseEvent( QMouseEvent * ev ){
	if (ev->button() == Qt::LeftButton){
		yukon->limpaDe();
		yukon->status(NULL);
	}
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

void GUI_CARTA::setCarta(CARTA * carta){
	
	if(carta->getNaipe() && carta->getValor()){
		char endereco[50];
		sprintf(endereco, "./figuras/classic-cards/%c%d.png", carta->getNaipe(), carta->getValor() );
		setPixmap(QPixmap(endereco));
	}
	else
		setPixmap(QPixmap("./figuras/classic-cards/CostasRed.png"));
}

void GUI_CARTA::mouseReleaseEvent( QMouseEvent * ev){
	if (ev->button() == Qt::LeftButton){
		if(yukon->isSetDe())
			yukon->movimenta(monte);
		else
			yukon->setDe(monte, ordem);
	}
}

// =============================

GUI_VAZIO::GUI_VAZIO(YUKON_GUI * y, QWidget * w, int m)
: QLabel(w)
{
	monte = m;
	ordem = 0;
	yukon = y;
	
	setGeometry(0, ordem*20, 100, 100);
	setPixmap(QPixmap("./figuras/classic-cards/vazio.png"));
}

void GUI_VAZIO::mouseReleaseEvent( QMouseEvent * ev){
	if (ev->button() == Qt::LeftButton){
		if(yukon->isSetDe())
			yukon->movimenta(monte);
	}
}

//==============================================

GUI_FUNDACAO::GUI_FUNDACAO(YUKON_GUI * y)
	: QWidget()
{
	yukon = y;
	fundacao = yukon->getFundacao();
	
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
		if(fundacao->getMonte(i)){
			char s[50];
			sprintf(s, "./figuras/classic-cards/%c%d.png", naipes[i], fundacao->getMonte(i) );
			c->setPixmap(QPixmap(s));
		} else {
			c->setPixmap(
				QPixmap("./figuras/classic-cards/CostasRed.png")
			);
		}

		vbox->addWidget(c);
	}
}


void GUI_FUNDACAO::mouseReleaseEvent( QMouseEvent * ev){
	if (ev->button() == Qt::LeftButton){
		if(yukon->isSetDe())
			yukon->movimentaParaFundacao();
	}
}

