#include <yukon.h>
#include <stdio.h>

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QMouseEvent>

class YUKON_GUI : public YUKON, public QApplication {
private:
	QMainWindow * window;
	void principal();
	QLabel * getImagemCarta(QWidget*, CARTA);
	
	int monteOrigem;
	int cartaOrigem;
	
public:
	YUKON_GUI(int, char **);
	int run();
	void status(char *);
	
	bool isSetDe();
	void setDe(int, int);
	void limpaDe();
	void movimenta(int);
	void movimentaParaFundacao();
	
	void novoJogo();
	
private slots:
	void coisa();
};

class GUI_PRINCIPAL : public QWidget {
private:
	YUKON_GUI * yukon;
public:
	GUI_PRINCIPAL( YUKON_GUI *, QWidget *);
	void mouseReleaseEvent( QMouseEvent * );
};

class GUI_CARTA : public QLabel {
private:
	YUKON_GUI * yukon;
	int monte;
	int ordem;
public:
	GUI_CARTA(YUKON_GUI *, QWidget*, int, int);
	void setCarta(CARTA *);
	void mouseReleaseEvent( QMouseEvent * );
};

class GUI_VAZIO : public QLabel {
private:
	YUKON_GUI * yukon;
	int monte;
	int ordem;
public:
	GUI_VAZIO(YUKON_GUI *, QWidget*, int);
	void mouseReleaseEvent( QMouseEvent * );
};

class GUI_FUNDACAO : public QWidget {
private:
	YUKON_GUI * yukon;
	FUNDACAO * fundacao;
public:
	GUI_FUNDACAO(YUKON_GUI *);
	void mouseReleaseEvent( QMouseEvent * );
};

class GUI_BOTAO : public QLabel{
private:
	YUKON_GUI * yukon;
	string funcao;
public:
	GUI_BOTAO(YUKON_GUI *, QWidget*, string);
	void mouseReleaseEvent( QMouseEvent * );
};
