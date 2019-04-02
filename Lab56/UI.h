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
	int Menu();
	void SetupRandom(Repo& r);
	void Setup(Repo &r);
	Logics getLogics() { return l; }
};


