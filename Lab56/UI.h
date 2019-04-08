#pragma once
#include "Logics.h"
#include "Repo.h"
class UI
{
private:
	Logics l;
public:
	UI();
	~UI();
	void Menu();
	void SetupRandom(Repo& r);
	void Setup(Repo &r);
	void app();
	Logics getLogics() { return l; }
};


