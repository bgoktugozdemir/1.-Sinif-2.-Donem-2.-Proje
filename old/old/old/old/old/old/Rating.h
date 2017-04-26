#pragma once
#include <list>

class User;
class Movie;
class Rating
{
public:
	int RatingId;
	User *UserId;
	Movie* MovieId;
	float rating;

	Rating(int RatingId, float rating);
	Rating();
	~Rating();

};

