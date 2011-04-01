#include "yukon.h"

class YUKON_CLI : public YUKON {
private:
	int interpretar(string);
	void imprimeCartas();
public:
	YUKON_CLI();
	int run();
};
