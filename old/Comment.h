#pragma once
//#include <iostream>
//#include <string>
//#include <list>
//#include <ctime>
//#include "User.h"
#include "CommonData.h"

class User;
class Movie;
class Background;
class Database;
class Interface;
class Movie;
class Rating;
class Studio;
class User;

using namespace std;

class Comment
{
public:
	int CommentId;
	time_t CommentTime;
	User* UserId;
	Movie* MovieId;
	string comment;
	int movie_id;
	int user_id;

	Comment();
	Comment(int CommentId, time_t CommentTime, string comment, int movie_id, int user_id);
	~Comment();
};


