#include "pch.h"
#include "UI.h"
using namespace std;

UI::UI()
{
}


UI::~UI()
{
}

int UI::Menu()
{
	int nr;
	cout << "......MENU......" << endl;
	cout << "1. Create Apartment" << endl;
	cout << "2. Add Value" << endl;
	cout << "3. Modify Value" << endl;
	//cout << "4. Show ALL Costs" << endl;
	//cout << "5. Show Costs Individually" << endl;
	cout << "10. Show Costs" << endl;

	cin >> nr;
	return nr;
}