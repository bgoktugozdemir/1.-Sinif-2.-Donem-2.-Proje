#pragma once
#include <algorithm>
#include "Database.h"
#include "CommonData.h"
using namespace std;

class Background
{
public:
	Background();
	Background(Database *dataBase);
	~Background();

	Database *Datas;
	list<Comment*> Comments;
	list<Movie*> Movies;
	list<Rating*> Ratings;
	list<Studio*> Studios;
	list<User*> Users;

	bool SaveNewComment(Comment *newComment);
	bool SaveNewMovie(Movie *newMovie);
	bool SaveNewRating(Rating *newRating);
	bool SaveNewStudio(Studio *newStudio);
	bool SaveNewUser(User *newUser);

	bool RemoveComment(int CommentId);
	bool RemoveMovie(int MovieId);
	bool RemoveRating(int RatingId);
	bool RemoveStudio(int StudioId);
	bool RemoveUser(int UserId);

	//ÝLÝÞKÝLER
	bool SaveCommentInUser(Comment *comment, User *user);
	bool SaveCommentInMovie(Comment *comment, Movie *movie);
	bool SaveMovieInStudio(Movie *movie, Studio *studio);
	bool SaveRatingInUser(Rating *rating, User *user);
	bool SaveRatingInMovie(Rating *rating, Movie *movie);

	bool RemoveCommentInUser(Comment *comment, User *user);
	bool RemoveCommentInMovie(Comment *comment, Movie *movie);
	bool RemoveMovieInStudio(Movie *movie, Studio *studio);
	bool RemoveRatingInUser(Rating *rating, User *user);
	bool RemoveRatingInMovie(Rating *rating, Movie *movie);

};

