#pragma once
#define Version 1.03
class Interface
{
public:
	Interface();
	~Interface();

	void Start();
	//Main Menu
	void MainMenu();

	//Child Menus
	void Movies();
	void Ratings();
	void Studios();
	void Users();

	//Movie's Child Menus
	void ListMovies();
	void EditMovies();
	void AddMovies();
	void DeleteMovies();

	//Rating's Child Menus
	void ListRatings();
	void EditRatings();
	void AddRatings();
	void DeleteRatings();

	//Studio's Child Menus
	void ListStudios();
	void EditStudios();
	void AddStudios();
	void DeleteStudios();

	//User's Child Menus
	void ListUsers();
	void EditUsers();
	void AddUsers();
	void DeleteUsers();
};

