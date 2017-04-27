//L�ST EKRANLARINDAK� ED�TLERDE SORUN VAR!

#pragma once
#define Version 1.07
#include "Database.h"
#include "Background.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

class Interface
{
public:
	Interface();
	Interface(Database * data, Background *background);
	~Interface();

	void Start();
	//Main Menu
	void MainMenu();

	//Child Menus
	void Comments();
	void Movies();
	void Ratings();
	void Studios();
	void Users();

	//Comment's Child Menus
	void ListComments();
	void EditComments(Comment *comment);
	void AddComments(); //CommentTime sorununa ��z�m bul.
	void DeleteComments();

	//Movie's Child Menus
	void ListMovies();
	void EditMovies(Movie *movie);
	void AddMovies();
	void DeleteMovies(); //Listeden Silmede Sorun Var

	//Rating's Child Menus
	void ListRatings();
	void EditRatings(Rating *rating);
	void AddRatings();
	void DeleteRatings();

	//Studio's Child Menus
	void ListStudios();
	void EditStudios(Studio *studio);
	void AddStudios();
	void DeleteStudios();

	//User's Child Menus
	void ListUsers();
	void EditUsers(User *user);
	void AddUsers();
	void DeleteUsers();

	void ShowComments(list<Comment*> &list);
	void ShowMovies(list<Movie*> &list);
	void ShowRatings(list<Rating*> &list);
	void ShowStudios(list<Studio*> &list);
	void ShowUsers(list<User*> &list);
private:
	Database *Datas;
	Background *Backgrounds;
};

