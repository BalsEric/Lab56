#include "pch.h"
#include<iostream>
#include<string>
#include "Logics.h"
#include "Repo.h"
using namespace std;

Logics::Logics()
{
}
Logics::~Logics()
{
}
void Logics::addApart()
{
	int nrapart;
	cout << "Provide Apart. Number ";
	cin >> nrapart;
	v[nrapart]++;
	if (v[nrapart] == 1)
	{
		Apartment apart = Apartment(nrapart);
		repo.addApart(apart);
	}
	else
		cout << "Apartment already created";
}

void addValue(Repo &r)
{
	r.CopyFirst();
	int nrApart=0, nrCheltuieli=0;
	string tip;
	string value;
	cout << endl;
	cout << "Provide : number type value "<<endl;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline (cin, value);
	nrApart = (value[0]-'0');
	if (isdigit(value[1]))
	{
		nrApart = nrApart * 10 + (value[1]-'0');
		unsigned i = 3;
		
		while (!isspace(value[i]))
		{
			tip = tip + value[i];
			i++;
		}
		i++;
		nrCheltuieli = value[i++] - '0';
		while (i < value.length())
		{
			nrCheltuieli = nrCheltuieli * 10 + (value[i]-'0');
			i++;
		}
	}
	else
	{
		unsigned i = 2;
		while (!isspace(value[i]))
		{
			tip = tip + value[i];
			i++;
		}
		i++;
		nrCheltuieli = value[i++] - '0';
		while (i < value.length())
		{
			nrCheltuieli = nrCheltuieli * 10 + (value[i]-'0');
			i++;
		}
	}
	if (tip == "gaz")
	{
		int var = r.getApart(nrApart)->getGaz() + nrCheltuieli;
		r.getApart(nrApart)->setGaz(var);
	}
	else
		if (tip == "apa")
		{
			int var = r.getApart(nrApart)->getApa() + nrCheltuieli;
			r.getApart(nrApart)->setApa(var);
		}
		else
			if (tip == "caldura")
			{
				int var = r.getApart(nrApart)->getCaldura()+nrCheltuieli;
				r.getApart(nrApart)->setCaldura(var);
			}
			else
				if (tip == "electricitate")
				{
					int var = r.getApart(nrApart)->getElect() + nrCheltuieli;
					r.getApart(nrApart)->setElect(var);
				}
				else
				{
					cout << "Nu exista aceasta optiune" << endl;
				}
	

}

void setValue(Repo &r)
{
	r.CopyFirst();
	int nrApart, nrCheltuieli;
	string tip;
	string value;
	cout << "Provide : number type with value "<<endl;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, value);

	nrApart = value[0] - '0';
	if (isdigit(value[1]))
	{
		nrApart = nrApart * 10 + (value[1] - '0');
		unsigned i = 3;

		while (!isspace(value[i]))
		{
			tip = tip + value[i];
			i++;
		}
		i += 4;
		nrCheltuieli = value[i++] - '0';
		while (i < value.length())
		{
			nrCheltuieli = nrCheltuieli * 10 + (value[i] - '0');
			i++;
		}
	}
	else
	{
		unsigned i = 2;
		while (!isspace(value[i]))
		{
			tip = tip + value[i];
			i++;
		}
		i += 4;
		nrCheltuieli = value[i++] - '0';
		while (i < value.length())
		{
			nrCheltuieli = nrCheltuieli * 10 + (value[i] - '0');
			i++;
		}
	}
	if (tip == "gaz")
	{
		r.getApart(nrApart)->setGaz(nrCheltuieli);
	}
	else
		if (tip == "apa")
		{
			r.getApart(nrApart)->setApa(nrCheltuieli);
		}
		else
			if (tip == "caldura")
			{
				r.getApart(nrApart)->setCaldura(nrCheltuieli);
			}
			else
				if (tip == "electricitate")
				{
					r.getApart(nrApart)->setElect(nrCheltuieli);
				}
				else
				{
					cout << "Nu exista aceasta optiune" << endl;
				}


}

void ValueModifier(Repo &r)
{
	r.CopyFirst();
	string value;
	int command,nr;
	cout << "---Modify MENU---" << endl;
	cout << "1. Eliminate Apart.'s costs " << endl << "2. Eliminate Apart.'s x->y costs" << endl << "3. Eliminate ALL Apart. type cost" << endl << "4. Replace Apart.'s type cost " << endl;
	cin >> command;
	if (command == 1)
	{
		cout << "Provide number " << endl;
		cin >> nr;
		r.getApart(nr)->setALL();
		cout << "Successfully" << endl;
	}
	else
		if (command == 2)
		{

			cout << "Provide number x to y " << endl;
			cout << "From : ";
			int x, y;
			cin >> x;
			cout << "To : ";
			cin >> y;
			for (int i = x; i <= y; i++)
			{
				r.getApart(i)->setALL();
			}
			cout << "Successfully" << endl;
		}
		else
			if (command == 3)
			{
				cout << "Provide the type : " << endl;
				string type;
				cin >> type;
				for (int i = 0; i < r.getSize(); i++)
				{
					r.getApart(i)->setType(type);
				}
				cout << "Successfully" << endl;
			}
			else
				if (command == 4)
				{

					setValue(r);
					cout << "Successfully" << endl;
				}

}

void showCosts(Repo r,int value)
{
	r.getApart(value)->showAll();
	std::cout << std::endl;
}

void showCostsIndiv(Repo r)
{
	int nr;
	cout << "Please provide Apart. Nr. " << endl;
	cin >> nr;
	r.getApart(nr)->showAll();
	std::cout << endl;
}

void showCostsHigher(Repo r, int value)
{
	for (int i = 0; i <= r.getSize(); i++)
	{
		if (r.getApart(i)->checkEqual2(value))
		{
			std::cout << "Apart. " << i << " has:" << std::endl;
			r.getApart(i)->showHiger(value);
			std::cout << std::endl;
		}
	}
}

void showCostsEqual(Repo r, int value)
{
	for (int i = 0; i < r.getSize(); i++)
	{
		if (r.getApart(i)->checkEqual(value))
		{
			std::cout << "Apart. " << i << " has:" << std::endl;
			r.getApart(i)->showEqual(value);
			std::cout << std::endl;
		}
		
		
	}
}

void sumType(Repo r, string tip)
{
	int sum = 0;
	if (tip == "gaz")
	{
		for (int i = 0; i < r.getSize(); i++)
		{
			sum += r.getApart(i)->getGaz();
		}
		std:: cout<< "The sum is : " << sum << std::endl;
	}
	else
		if (tip == "apa")
		{
			for (int i = 0; i < r.getSize(); i++)
			{
				sum += r.getApart(i)->getApa();
				
			}
			std:: cout<< "The sum is : " << sum << std::endl;
		}
		else
			if (tip == "caldura")
			{
				for (int i = 0; i < r.getSize(); i++)
				{
					sum += r.getApart(i)->getCaldura();
					
				}
				std:: cout<< "The sum is : " << sum << std::endl;
			}
			else
				if (tip == "electricitate")
				{
					for (int i = 0; i < r.getSize(); i++)
					{
						sum += r.getApart(i)->getElect();
					
					}
					std::cout << "The sum is : " << sum << std::endl;
				}
				else
				{
					cout << "Nu exista aceasta optiune" << endl;
				}
}
void maxim(int x[4])
{
	int maxi = 0;
	if ((x[0] >= x[1] && x[0] >= x[2] && x[0] >= x[3]))
	{
		cout << "The most cost is apa: " << x[0] << endl;
	}
	else
	if ((x[1] >= x[0] && x[1] >= x[2] && x[1] >= x[3]))
	{
		cout << "The most cost is caldura: " << x[1] << endl;
	}
	else
	if ((x[2] >= x[1] && x[2] >= x[0] && x[2] >= x[3]))
	{
		cout << "The most cost is electricitate: " << x[2] << endl;
	}
	else
	if ((x[3] >= x[1] && x[3] >= x[2] && x[3] >= x[0]))
	{
		cout << "The most cost is gas: " << x[3] << endl;
	}
}
void showTheMostCost(Repo r)
{
	int nr;
	cout << "Provide number " << endl;
	cin >> nr;
	int x[4] = { r.getApart(nr)->getApa(),r.getApart(nr)->getCaldura(),r.getApart(nr)->getElect(),r.getApart(nr)->getGaz() };
	maxim(x);
}

void sortType(Repo r, string type)
{
	Apartment* copie[10]; // MAYBE BUG
	for (int i = 0; i < r.getSize(); i++)
		copie[i] = r.getApart(i);
	if (type == "gaz")
	{
		int ok = 0;
		Apartment* aux;
		do
		{
			ok = 0;
			for (int j = 0; j < r.getSize()-1; j++)
			{
				if (copie[j]->getGaz() > copie[j + 1]->getGaz())
				{
					aux = copie[j];
					copie[j] = copie[j + 1];
					copie[j + 1] = aux;
					ok = 1;
				}
			}
		} while (ok == 1);
		for (int k = 0; k < r.getSize(); k++)
			cout << "Apart. " << copie[k]->getnrApart() << " has " << copie[k]->getGaz() << endl;
	}
	else
		if(type=="apa")
		{
			int ok = 0;
			Apartment* aux;
			do
			{
				ok = 0;
				for (int j = 0; j < r.getSize() - 1; j++)
				{
					if (copie[j]->getApa() > copie[j + 1]->getApa())
					{
						aux = copie[j];
						copie[j] = copie[j + 1];
						copie[j + 1] = aux;
						ok = 1;
					}
				}
			} while (ok == 1);
			for (int k = 0; k < r.getSize(); k++)
				cout << "Apart. " << copie[k]->getnrApart() << " has " << copie[k]->getApa() << endl;
		}
		else
			if(type=="caldura")
			{
				int ok = 0;
				Apartment* aux;
				do
				{
					ok = 0;
					for (int j = 0; j < r.getSize() - 1; j++)
					{
						if (copie[j]->getCaldura() > copie[j + 1]->getCaldura())
						{
							aux = copie[j];
							copie[j] = copie[j + 1];
							copie[j + 1] = aux;
							ok = 1;
						}
					}
				} while (ok == 1);
				for (int k = 0; k < r.getSize(); k++)
					cout << "Apart. " << copie[k]->getnrApart() << " has " << copie[k]->getCaldura() << endl;
			}
			else
				if(type=="electricitate")
				{
					int ok = 0;
					Apartment* aux;
					do
					{
						ok = 0;
						for (int j = 0; j < r.getSize() - 1; j++)
						{
							if (copie[j]->getElect() > copie[j + 1]->getElect())
							{
								aux = copie[j];
								copie[j] = copie[j + 1];
								copie[j + 1] = aux;
								ok = 1;
							}
						}
					} while (ok == 1);
					for (int k = 0; k < r.getSize(); k++)
						cout << "Apart. " << copie[k]->getnrApart() << " has " << copie[k]->getElect() << endl;
				}
	//delete[] copie;
		
}


void filterType(Repo& r, string type)
{
	r.CopyFirst();
	if (type == "gaz")
	{
		for (int i = 0; i < r.getSize(); i++)
		{

			r.getApart(i)->setApa(-1);
			r.getApart(i)->setCaldura(-1);
			r.getApart(i)->setElect(-1);
		}
	}
	else
		if (type == "apa")
		{
			for (int i = 0; i < r.getSize(); i++)
			{

				r.getApart(i)->setGaz(-1);
				r.getApart(i)->setCaldura(-1);
				r.getApart(i)->setElect(-1);
			}
		}
		else
			if (type == "caldura")
			{
				for (int i = 0; i < r.getSize(); i++)
				{

					r.getApart(i)->setApa(-1);
					r.getApart(i)->setGaz(-1);
					r.getApart(i)->setElect(-1);
				}
			}
			else
				if (type == "electricitate")
				{
					for (int i = 0; i < r.getSize(); i++)
					{

						r.getApart(i)->setApa(-1);
						r.getApart(i)->setCaldura(-1);
						r.getApart(i)->setGaz(-1);
					}
				}
	cout << "Successfully filtered!" << endl;
}

void filterLess(Repo& r, int value)
{
	r.CopyFirst();
	for (int i = 0; i < r.getSize(); i++)
	{
		if (r.getApart(i)->getApa() > value)
			r.getApart(i)->setApa(-1);
		if (r.getApart(i)->getCaldura() > value)
			r.getApart(i)->setCaldura(-1);
		if (r.getApart(i)->getElect() > value)
			r.getApart(i)->setElect(-1);
		if (r.getApart(i)->getGaz() > value)
			r.getApart(i)->setGaz(-1);
	}
	cout << "Filtered successfully" << endl;
}
