#pragma once
#include "Apartment.h"
class Repo
{
private:
	int size;
public:
	Apartment x[100];
	Repo() : size(0) {};
	void addApart(Apartment apart);
	Apartment* getApart(int pos);
	int getSize() { return this->size; }

	//void deleteApart(int pos) { delete &this->x[pos]; }
	~Repo();
};

