#include "Interface.h"
#include <iostream>
#include <conio.h>
using namespace std;

Interface::Interface()
{
	Start();
}


Interface::~Interface()
{
}

void Interface::Start()
{
	while (true)
	{
		MainMenu();
		char Selection;
		cin >> Selection;
		system("CLS");
		switch (Selection)
		{
		case 'a':
			Movies();
			break;
		case 'b':
			Ratings();
			break;
		case 'c':
			Studios();
			break;
		case 'd':
			Users();
			break;
		case '0':
			exit(0);
			break;
		default:
			Start();
			break;
		}
		system("CLS");
	}
}

void Interface::MainMenu()
{
	char yazi[40];
	sprintf(yazi, "title Welcome back to Movie System (v%.2f)", Version);
	system(yazi);
	cout << "Main Menu" << endl
		 << "a - Movies Menu" << endl
		 << "b - Ratings Menu" << endl
		 << "c - Studios Menu" << endl
		 << "d - Users Menu" << endl
	 	 << "0 - Exit" << endl
		 << "-----------------------------------" << endl
		 << "Please choose one of the options: ";
}

void Interface::Movies()
{
	cout << "Movies Menu" << endl
		 << "a - List Movies" << endl
		 << "b - Edit Movies" << endl
		 << "c - Add Movies" << endl
		 << "d - Delete Movies" << endl
		 << "0 - Go Back to Main Menu" << endl
		 << "-----------------------------------" << endl
		 << "Please choose one of the options: ";
		 
	char Selection = getch();
	//cin >> Selection;
	system("CLS");

	switch(Selection)
	{
	case 'a':
		ListMovies();
		break;
	case 'b':
		EditMovies();
		break;
	case 'c':
		AddMovies();
		break;
	case 'd':
		DeleteMovies();
		break;
	case '0':
		MainMenu();
		break;
	default:
		Movies();
		break;
	}
}

void Interface::Ratings()
{
	cout << "Rating Menu" << endl
		 << "a - List Ratings" << endl
		 << "b - Edit Ratings" << endl
		 << "c - Add Ratings" << endl
		 << "d - Delete Ratings" << endl
		 << "0 - Go Back to Main Menu" << endl
		 << "-----------------------------------" << endl
		 << "Please choose one of the options: ";

	char Selection = getch();
	//cin >> Selection;
	system("CLS");

	switch (Selection)
	{
	case 'a':
		ListRatings();
		break;
	case 'b':
		EditRatings();
		break;
	case 'c':
		AddRatings();
		break;
	case 'd':
		DeleteRatings();
		break;
	case '0':
		MainMenu();
		break;
	default:
		Ratings();
		break;
	}
}

void Interface::Studios()
{
	cout << "Studio Menu" << endl
		 << "a - List Studios" << endl
		 << "b - Edit Studios" << endl
		 << "c - Add Studios" << endl
		 << "d - Delete Studios" << endl
		 << "0 - Go Back to Main Menu" << endl
		 << "-----------------------------------" << endl
		 << "Please choose one of the options: ";

	char Selection = getch();
	//cin >> Selection;
	system("CLS");

	switch (Selection)
	{
	case 'a':
		ListStudios();
		break;
	case 'b':
		EditStudios();
		break;
	case 'c':
		AddStudios();
		break;
	case 'd':
		DeleteStudios();
		break;
	case '0':
		MainMenu();
		break;
	default:
		Studios();
		break;
	}
}

void Interface::Users()
{
	cout << "User Menu" << endl
		 << "a - List Users" << endl
		 << "b - Edit Users" << endl
		 << "c - Add Users" << endl
		 << "d - Delete Users" << endl
		 << "0 - Go Back to Main Menu" << endl
		 << "-----------------------------------" << endl
		 << "Please choose one of the options: ";

	char Selection = getch();
	//cin >> Selection;
	system("CLS");

	switch (Selection)
	{
	case 'a':
		ListUsers();
		break;
	case 'b':
		EditUsers();
		break;
	case 'c':
		AddUsers();
		break;
	case 'd':
		DeleteUsers();
		break;
	case '0':
		MainMenu();
		break;
	default:
		Users();
		break;
	}
}
