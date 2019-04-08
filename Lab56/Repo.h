#pragma once
#include "Apartment.h"
class Repo
{
private:
	int size;
	int sizecopie;
public:
	Apartment x[100];
	Apartment a[100];
	Repo() : size(0), sizecopie(0) { CopyFirst(); };
	void CopyFirst();
	void Undo();
	void addApart(Apartment apart);
	Apartment* getApart(int pos);
	int getSize() { return this->size; }
	void deleteApart(int pos) { delete& this->x[pos]; }
	~Repo();
};

