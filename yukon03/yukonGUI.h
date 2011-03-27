#include <yukon.h>

#include <QObject>
#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QWidget>
#include <QBoxLayout>
#include <QLabel>

class YUKON_GUI : public YUKON, public QObject {
	
private:
	QApplication * app;
	QMainWindow * window;
	void menu();
	void toolbar();
	void status();
	void principal();
public:
	YUKON_GUI();
	int run(int, char **);
	
public slots:
	void coisa(); 
};
