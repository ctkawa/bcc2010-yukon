#include <yukon.h>

#include <QApplication>
#include <QMainWindow>

class YUKON_GUI : public YUKON {
private:
	QApplication * app;
	QMainWindow * window;
public:
	YUKON_GUI();
	int run(int, char **);
};
