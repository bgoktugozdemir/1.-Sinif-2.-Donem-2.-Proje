#pragma once
//#include <iostream>
//#include <string>
//#include <list>
//#include "Movie.h"
#include "CommonData.h"

class Background;
class Comment;
class Database;
class Interface;
class Movie;
class Rating;
class User;

using namespace std;

class Studio
{
public:
	int StudioId;
	string StudioName;
	string StudioInfo;
	list <Movie*> movies;

	Studio(int StudioId, string StudioName, string StudioInfo);
	Studio();
	~Studio();

};

