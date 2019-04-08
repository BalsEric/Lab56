#include "pch.h"
#include "Repo.h"



Repo::~Repo()
{
}

void Repo::addApart(Apartment apart)
{
	this->x[this->size] = apart;
	this->size++;
	this->sizecopie = this->size;
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
void Repo::CopyFirst()
{
	for (int i = 0; i <= size; i++)
	{
		a[i]=this->x[i];
		//Apartment* a = &this->x[i];
		//a[i] = *a;
	}
}

void Repo::Undo()
{
	for (int i = 0; i <= size; i++)
	{
		Apartment* a = &this->a[i];
		x[i] = *a;
	}
	std::cout << "Successfully restored !" << std::endl;
}

