#include <yukon.h>
#include <stdio.h>

#include <QObject>
#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QMouseEvent>

class YUKON_GUI : public YUKON, public QObject {
private:
	QApplication * app;
	QMainWindow * window;
	void menu();
	void toolbar();
	void status();
	void principal();
	QLabel * getImagemCarta(QWidget*, CARTA);
	
	int deMonte;
	int deCarta;
	
public:
	YUKON_GUI();
	int run(int, char **);
	
	bool isSetDe();
	void setDe(int, int);
	void limpaDe();
	void movimenta(int);
	
public slots:
	void coisa(); 
};

class GUI_CARTA : public QLabel {
private:
	YUKON_GUI * yukon;
	int monte;
	int ordem;
public:
	GUI_CARTA(YUKON_GUI *, QWidget*, int, int);
	void setCarta(CARTA);
	void mouseReleaseEvent( QMouseEvent * );
};
