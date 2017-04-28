#pragma once
//#include <list>
#include "CommonData.h"

class Background;
class Comment;
class Database;
class Interface;
class Movie;
class Studio;
class User;

using namespace std;

class Rating
{
public:
	int RatingId;
	User *UserId;
	Movie* MovieId;
	float rating;
	int user_id;
	int movie_id;

	Rating(int RatingId, float rating, int user_id, int movie_id);
	Rating();
	~Rating();

};

