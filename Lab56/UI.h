#pragma once
#include "Logics.h"
class UI
{
private:
	Logics l;
public:
	UI();
	~UI();
	int Menu();
	Logics getLogics() { return l; }
};

