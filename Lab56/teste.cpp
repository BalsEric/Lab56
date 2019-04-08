#include "pch.h"
#include "Repo.h"
#include "Apartment.h"
#include "Logics.h"
#include<assert.h>
using namespace std;
void teste()
{
	Logics logics = Logics();
	Repo r = logics.getRepo();
	int nr=2;
	Apartment a = Apartment(2);
	r.addApart(a);
	assert(a.getApa() == 0); 
	cout << "Object Getter working!" << endl;
	a.setCaldura(100);
	assert(a.getCaldura() == 100);
	cout << "Object Setter working!" << endl;
	r.getApart(2)->setApa(52);
	assert(r.getApart(2)->getApa() == 52); 
	cout << "Repo Adding Obj working!" << endl;
	cout << "Repo on Obj Getter and Setter working!" << endl;
	Apartment a1 = Apartment(1);
	Apartment a2 = Apartment(3);
	Apartment a3 = Apartment(4);
	Apartment a4 = Apartment(5);

	r.addApart(a1);
	r.addApart(a2);
	r.addApart(a3);
	r.addApart(a4);
	assert(r.getSize() == 5);
	cout << "Repo Size Getter working!" << endl;
	assert(r.getApart(1)->getnrApart() == 1);
	cout << "Repo Obj Getter working!" << endl;
	r.getApart(3)->setApa(23);
	r.getApart(4)->setGaz(33);
	r.getApart(4)->setALL();
	r.getApart(3)->setALL();
	assert(r.getApart(3)->getApa() == 0);
	assert(r.getApart(4)->getGaz() == 0);
	assert(r.getApart(4)->getCaldura() == 0);
	cout << "Object SetterALL working!" << endl;



	cout << endl;
	cout << "Tests successfully finished" << endl;
	cout << endl;

}