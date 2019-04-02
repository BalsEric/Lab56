#include<string>
#include<iostream>
#pragma once

class Apartment
{
//variabile
private:
	int nrApart;
	int gaz;
	int apa;
	int electricitate;
	int caldura;
//constructori
public:
	Apartment();
	Apartment(const Apartment &a);
	Apartment(int newNumber) : nrApart(newNumber) {
		gaz = 0;
		apa = 0;
		electricitate = 0;
		caldura = 0;
	};
	//operator=(Apartment a);
	~Apartment();
//getteri
public:
	int getnrApart() { return this->nrApart; }
	int getGaz() { return this->gaz; }
	int getApa() { return this->apa; }
	int getElect() { return this->electricitate; }
	int getCaldura() { return this->caldura; }
//setteri

	void setGaz(int newSum) { this->gaz = newSum; }
	void setApa(int newSum) { this->apa = newSum; }
	void setElect(int newSum) { this->electricitate = newSum; }
	void setCaldura(int newSum) { this->caldura = newSum; }
	void setALL() { this->gaz = 0; this->apa = 0; this->electricitate = 0; this->caldura = 0; }
	void setType(std::string s);

//external
	bool checkEqual(int value);
	void showAll();
	void showHiger(int value);
	void showEqual(int value);
	
};

