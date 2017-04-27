#pragma once
//#include <iostream>
//#include <string>
//#include <list>
//#include "Comment.h"
//#include "Rating.h"
#include "CommonData.h"


using namespace std;

class Rating;
class Background;
class Comment;
class Database;
class Interface;
class Movie;
class Rating;
class Studio;

enum userType
{
	Administrator,
	Writer,
	MovieCritic,
	Member
};

class User
{
public:
	int UserId;
	userType UserType;
	string UserName;
	string UserPassword;
	string UserEmail;
	list <Comment*> comments;
	list <Rating*> ratings;

	User(int UserId, userType UserType, string UserName, string UserPassword, string UserEmail);
	User();
	~User();

};

