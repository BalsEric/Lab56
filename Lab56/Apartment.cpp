#include "pch.h"
#include<iostream>
#include <string>
#include "Apartment.h"


Apartment::Apartment()
{
	nrApart = 0;
	gaz = 0;
	apa = 0;
	electricitate = 0;
	caldura = 0;
}

Apartment::Apartment(const Apartment &a)
{
	this->apa = a.apa;
	this->caldura = a.caldura;
	this->electricitate = a.electricitate;
	this->gaz = a.gaz;
	this->nrApart = a.nrApart;
}


Apartment::~Apartment()
{
}

void Apartment::setType(std::string s)
{
	if (s == "gaz")
		setGaz(0);
	else
		if (s == "caldura")
			setCaldura(0);
		else
			if (s == "electricitate")
				setElect(0);
			else
				if (s == "apa")
					setApa(0);
				else
					std::cout << "Nu exista aceasta optiune" << std::endl;
}

void Apartment::showAll()
{
	std::cout << "Apart. " << nrApart <<":"<<std::endl;
	if(gaz!=-1)
		std::cout << "Gaz: " << getGaz()<<std::endl;
	if (apa != -1)
		std::cout << "Apa: " << getApa() << std::endl;
	if (caldura!= -1)
		std::cout << "Caldura: " << getCaldura() << std::endl;
	if (electricitate != -1)
		std::cout << "Electricitate: " << getElect() << std::endl;
}

void Apartment::showHiger(int value)
{ 
	if (getGaz() > value )
	{
		std::cout << "Gaz: " << getGaz() << std::endl;
	}

	if (getApa() > value)
	{
		std::cout << "Apa: " << getApa() << std::endl;
	}

	if (getCaldura() > value)
	{
		std::cout << "Cladura: " << getCaldura() << std::endl;
	}

	if (getElect() > value)
	{
		std::cout << "Electricitate: " << getElect() << std::endl;
	}

}

bool Apartment::checkEqual(int value)
{
	bool ok = false;
	if (getGaz() == value)
	{
		ok = true;
	}
	if (getApa() == value)
	{
		ok = true;

	}

	if (getCaldura() == value)
	{
		ok = true;

	}

	if (getElect() == value)
	{
		ok = true;

	}
	if (ok)
		return true;
	return false;
}

bool Apartment::checkEqual2(int value)
{
	bool ok = false;
	if (getGaz() > value)
	{
		ok = true;
	}
	if (getApa()> value)
	{
		ok = true;

	}

	if (getCaldura()> value)
	{
		ok = true;

	}

	if (getElect()>value)
	{
		ok = true;

	}
	if (ok)
		return true;
	return false;
}


void Apartment::showEqual(int value)
{
	std::cout << "Apart. " << nrApart << std::endl;
	if (getGaz() == value)
	{
		std::cout << "Gaz: " << getGaz() << std::endl;
	}

	if (getApa()== value)
	{

		std::cout << "Apa: " << getApa() << std::endl;
	}

	if (getCaldura() == value)
	{
		
		std::cout << "Caldura: " << getCaldura() << std::endl;
	}

	if (getElect() == value)
	{
		
		std::cout << "Electricitate: " << getElect() << std::endl;
	}
}


Apartment& Apartment::operator=(const Apartment& a)
{
	if (this != &a)
	{
		this->apa = a.apa;
		this->caldura = a.caldura;
		this->electricitate = a.electricitate;
		this->gaz = a.gaz;
		this->nrApart = a.nrApart;
	}
	return *this;
}
