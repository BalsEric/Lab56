#pragma once

#include "Apartment.h"
#include "Repo.h"
#include<string>
class Logics  // CONTROLLER
{
private:
	Repo repo;
public:
	int v[100] = { 0 };
	Logics();
	void addApart();
	Repo getRepo() { return this->repo; }
	~Logics();
};

void addValue(Repo &r);  // Menu
void setValue(Repo &r);
void ValueModifier(Repo &r); // Menu - mini menu
void showCosts(Repo r,int value);  // Menu
void showCostsIndiv(Repo r); //Menu
void showCostsHigher(Repo r,int value); // Menu
void showCostsEqual(Repo r, int value); // menu
void sumType(Repo r, std::string type); // menu
void showTheMostCost(Repo r); // menu
//void sortType(Repo r, std::string type);