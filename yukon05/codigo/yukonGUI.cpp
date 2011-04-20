#include "yukonGUI.h"

#include <iostream>

#include <unistd.h>

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
	
	status("");
	principal();
	
	window->show();
	return exec();
}

void YUKON_GUI::status(QString texto = NULL){
	QStatusBar * sb = window->statusBar();
	sb->showMessage(texto);
}

void YUKON_GUI::principal(){
	
	bool ok;
	
	GUI_PRINCIPAL *p = new GUI_PRINCIPAL(this, window);
	
	window->setCentralWidget(p);
	
	QVBoxLayout * vbox = new QVBoxLayout();
	p->setLayout(vbox);
	
	// comandos
	
	QWidget * wComandos = new QWidget();
	vbox->addWidget(wComandos);
	
	QHBoxLayout * comHbox = new QHBoxLayout();
	wComandos->setLayout(comHbox);
	
	QLabel * lComNovo = new GUI_BOTAO(this, wComandos, "novo");
	lComNovo->setText("Novo");
	comHbox->addWidget(lComNovo);
	
	QLabel * lComSair = new GUI_BOTAO(this, wComandos, "sair");
	lComSair->setText("Sair");
	comHbox->addWidget(lComSair);
	
	// cartas
	
	QWidget * wCartas = new QWidget();
	vbox->addWidget(wCartas);
	
	QHBoxLayout * hbox = new QHBoxLayout();
	wCartas->setLayout(hbox);
	
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

void YUKON_GUI::novoJogo(){
	YUKON::novoJogo();
	principal();
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
		QString endereco = QCoreApplication::applicationDirPath();
		
		endereco.append("/figuras/classic-cards/");
		endereco.append(carta->getNaipe());
		char s[3];
		sprintf(s, "%d", carta->getValor());
		endereco.append(s);
		endereco.append(".png");
		setPixmap(QPixmap(endereco));
	}
	else {
		QString endereco = QCoreApplication::applicationDirPath();
		endereco.append("/figuras/classic-cards/CostasRed.png");
		setPixmap(QPixmap(endereco));
	}
	adjustSize();
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
	QString endereco = QCoreApplication::applicationDirPath();
	endereco.append("/figuras/classic-cards/vazio.png");
	setPixmap(QPixmap(endereco));
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
			QString endereco = QCoreApplication::applicationDirPath();
			endereco.append("/figuras/classic-cards/");
			endereco.append(naipes[i]);
			char s[3];
			sprintf(s, "%d", fundacao->getMonte(i) );
			endereco.append(s);
			endereco.append(".png");
			c->setPixmap(QPixmap(endereco));
		} else {
			QString endereco = QCoreApplication::applicationDirPath();
			endereco.append("/figuras/classic-cards/CostasRed.png");
			c->setPixmap(QPixmap(endereco));
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

//===================================================

GUI_BOTAO::GUI_BOTAO(YUKON_GUI * y, QWidget * w, string s)
: QLabel(w) {
	yukon = y;
	funcao = s;
}

void GUI_BOTAO::mouseReleaseEvent( QMouseEvent * ev){
	if( ev->button() == Qt::LeftButton){
		if(funcao == "novo"){
			yukon->novoJogo();
		} else if(funcao == "sair"){
			exit(0);
		}
	}
}
