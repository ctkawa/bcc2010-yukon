#include "yukonGUI.h"

YUKON_GUI::YUKON_GUI()
	: YUKON()
{
	
}

int YUKON_GUI::run(int argc, char *argv[]){
	
	app = new QApplication(argc, argv);
	window = new QMainWindow();
	
	window->show();
	return app->exec();
}

