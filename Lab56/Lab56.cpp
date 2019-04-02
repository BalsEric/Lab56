// Lab56.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include "Logics.h"
#include "teste.h"
#include "UI.h"

using namespace std;
int main()
{
	teste();
	UI ui = UI();
	Logics logics = ui.getLogics();
	Repo r = logics.getRepo();
	int nr;
	while (true)
	{
		nr = ui.Menu();
		switch (nr)
		{
		case 1:
			logics.addApart(); // add apartment
			break;
		case 2:
			addValue(r);
			break;
		case 3:
			ValueModifier(r);
		case 10:
			int v;
			cout << "Provide number";
			cin >> v;
			showCosts(r,v);
		default:
			break;
		}

	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
