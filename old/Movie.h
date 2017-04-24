#pragma once
#include <string>
#include <list>
#include "Studio.h"
#include "Comment.h"

using namespace std;
class Studio;
class Rating;
class Movie
{
public:
	int MovieId;
	string MovieTitle;
	string MovieGenre;
	string MovieReleaseYear;
	string MovieLanguage;
	float MovieRating;
	string MovieCensorship;
	string MovieStory;
	unsigned int MovieBudget;
	Studio *studio;
	list <Comment*> comments;
	list <Rating*> ratings;


	Movie(int MovieId, string MovieTitle, string MovieGenre, string MovieReleaseYear, string MovieLanguage, float MovieRating, string MovieCensorship, string MovieStory, unsigned int MovieBudget);
	Movie();
	~Movie();

};

