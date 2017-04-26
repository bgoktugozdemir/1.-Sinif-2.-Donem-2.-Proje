#include "Rating.h"



Rating::Rating(int RatingId, float rating)
{
	this->RatingId = RatingId;
	this->rating = rating;
}

Rating::Rating()
{
	this->RatingId = 0;
	this->rating = 0;
}


Rating::~Rating()
{
}
