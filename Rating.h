#pragma once
#include <list>
#include "CommonData.h"

class User;
class Movie;
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

