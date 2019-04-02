#include "pch.h"
#include "Repo.h"



Repo::~Repo()
{
}

void Repo::addApart(Apartment apart)
{
	this->x[this->size] = apart;
	this->size++;
	std::cout << "Apartment Successfully added !" << std::endl;
}

Apartment* Repo::getApart(int pos)
{
	for(int i=0;i<size;i++)
		if (int(x[i].getnrApart()) == pos)
		{
			Apartment *a = &this->x[i];
			return a;
		}
}
