#include <yukon.h>

#include <QObject>
#include <QApplication>
#include <QMainWindow>
#include <qmenubar.h>
#include <QToolBar>
#include <qstatusbar.h>

class YUKON_GUI : public YUKON, public QObject {
private:
	QApplication * app;
	QMainWindow * window;
	void menu();
	void toolbar();
	void status();
public:
	YUKON_GUI();
	int run(int, char **);
	
public slots:
	void coisa(); 
};
