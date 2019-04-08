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
	Repo getRepo() { return this->repo;}
	~Logics();
};

void addValue(Repo &r);  
void setValue(Repo &r);
void ValueModifier(Repo &r);
void showCosts(Repo r,int value);  
void showCostsIndiv(Repo r);
void showCostsHigher(Repo r,int value); 
void showCostsEqual(Repo r, int value);
void sumType(Repo r, std::string type);
void showTheMostCost(Repo r);
void sortType(Repo r, std::string type);
void filterType(Repo& r, std::string type);
void filterLess(Repo& r, int value);