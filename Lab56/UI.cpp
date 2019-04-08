#include "pch.h"
#include "Apartment.h"
#include "UI.h"
#include "teste.h"
#include<random>
using namespace std;

UI::UI()
{
}
void UI::app()
{
	string type2;
	string value3;
	string value4;
	teste();
	Logics logics =getLogics();
	Repo r = logics.getRepo();
	Setup(r);
	SetupRandom(r);
	int nr, less;
	while (true)
	{
		cout << "Press 0 for MENU" << endl;;
		cin >> nr;
		switch (nr)
		{
		case 0:
			cout << endl;
			cout << "Values : 0 -> 100000" << endl;
			cout << "Types : apa | caldura | gaz | electricitate" << endl;
			Menu();
			break;
		case 1:
			logics.addApart(); // add apartment
			break;
		case 2:
			addValue(r);
			break;
		case 3:
			ValueModifier(r);
		case 4:
			for (int i = 0; i <= r.getSize(); i++)
			{
				showCosts(r, i);
				cout << endl;
			}
			break;
		case 5:
			int v;
			cout << "Provide number : ";
			cin >> v;
			showCosts(r, v);
			break;
		case 6:
			cout << "Provide value : ";
			int value;
			cin >> value;
			showCostsHigher(r, value);
			cout << endl;
			break;
		case 7:
			cout << "Provide value : ";
			int value1;
			cin >> value1;
			showCostsEqual(r, value1);
			break;
		case 8:
			cout << "Provide the type : ";
			cin >> type2;
			sumType(r, type2);
			break;
		case 9:
			showTheMostCost(r);
			break;

		case 10:
			cout << "Provide type : " << endl;
			cin >> value3;
			sortType(r, value3);
			break;
		case 11:
			cout << "Provide type : " << endl;
			cin >> value4;
			filterType(r, value4);
			break;
		case 12:
			cout << "Provide value : " << endl;
			cin >> less;
			filterLess(r, less);
			break;

		case 13:
			r.Undo();
		default:
			break;
		}

	}
}
void UI::SetupRandom(Repo& r)
{
	random_device rd;
	mt19937 gen(rd()); 
	uniform_int_distribution<> dist(1, 300);
	for (int i = 0; i <= r.getSize(); i++)
	{
		r.getApart(i)->setApa(dist(gen));
		r.getApart(i)->setGaz(dist(gen));
		r.getApart(i)->setCaldura(dist(gen));
		r.getApart(i)->setElect(dist(gen));
	}
}
void UI::Setup(Repo &r)
{
	Apartment a0=Apartment(0);
	Apartment a1=Apartment(1);
	Apartment a2=Apartment(2);
	Apartment a3=Apartment(3);
	Apartment a4=Apartment(4);
	Apartment a5=Apartment(5);
	Apartment a6=Apartment(6);
	Apartment a7=Apartment(7);
	Apartment a8=Apartment(8);
	Apartment a9=Apartment(9);
	/*
	Apartment a10=Apartment(10);
	Apartment a11=Apartment(11);
	Apartment a12=Apartment(12);
	Apartment a13=Apartment(13);
	Apartment a14=Apartment(14);
	Apartment a15=Apartment(15);
	Apartment a16=Apartment(16);
	Apartment a17=Apartment(17);
	Apartment a18=Apartment(18);
	Apartment a19=Apartment(19);
	Apartment a20=Apartment(20);
	*/
	r.addApart(a0);
	r.addApart(a1);
	r.addApart(a2);
	r.addApart(a3);
	r.addApart(a4);
	r.addApart(a5);
	r.addApart(a6);
	r.addApart(a7);
	r.addApart(a8);
	r.addApart(a9);
	/*
	r.addApart(a10);
	r.addApart(a11);
	r.addApart(a12);
	r.addApart(a13);
	r.addApart(a14);
	r.addApart(a15);
	r.addApart(a16);
	r.addApart(a17);
	r.addApart(a18);
	r.addApart(a19);
	r.addApart(a20);
	*/
	cout << endl << endl << endl;
}

UI::~UI()
{
}

void UI::Menu()
{
	cout << "......MENU......" << endl;
	cout << "1. Create Apartment" << endl;
	cout << "2. Add Value" << endl;
	cout << "3. Modify Value" << endl;
	cout << "4. Show ALL Costs" << endl;
	cout << "5. Show Costs Individually" << endl;
	cout << "6. Show Costs Higher" << endl;
	cout << "7. Show Costs Equal" << endl;
	cout << "8. Show Sum type" << endl;
	cout << "9. Show the most cost" << endl;
	cout << "10. Sort type" << endl;
	cout << "11. Filter type" << endl;
	cout << "12. Filter value" << endl;
	cout << "13. UNDO" << endl;

}