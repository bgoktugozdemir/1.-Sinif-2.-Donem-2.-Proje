#include "Background.h"


Background::Background()
{
}

Background::Background(Database * dataBase)
{
	Datas = dataBase;
}


Background::~Background()
{
}

bool Background::SaveNewComment(Comment * newComment)
{
	Datas->Comments.push_back(newComment);
	return true;
}

bool Background::SaveNewMovie(Movie * newMovie)
{
	Datas->Movies.push_back(newMovie);
	return true;
}

bool Background::SaveNewRating(Rating * newRating)
{
	Datas->Ratings.push_back(newRating);
	return true;
}

bool Background::SaveNewStudio(Studio * newStudio)
{
	Datas->Studios.push_back(newStudio);
	return true;
}

bool Background::SaveNewUser(User * newUser)
{
	Datas->Users.push_back(newUser);
	return true;
}

bool Background::RemoveComment(int CommentId)
{/*
	Comment *oldComment = Datas->FindTheComment(CommentId);

	RemoveCommentInMovie(oldComment, oldComment->MovieId);

	RemoveCommentInUser(oldComment, oldComment->UserId);

	Datas->Comments.erase(find(Datas->Comments.begin(), Datas->Comments.end(), oldComment));

	delete oldComment;
	return true;
	*/
	Comment* deleteThis = Datas->FindTheComment(CommentId);
	if (deleteThis == NULL)	return false;
	Datas->Comments.remove(deleteThis);

	deleteThis->UserId = NULL;
	deleteThis->MovieId = NULL;
}

bool Background::RemoveMovie(int MovieId)
{
	/*
	Movie *oldMovie = Datas->FindTheMovie(MovieId);

	RemoveMovieInStudio(oldMovie, oldMovie->studio);

	list<Comment*>::iterator i;
	for (i = Comments.begin(); i != Comments.end(); i++)
	{
		RemoveCommentInMovie((*i), oldMovie);
	}

	list<Rating*>::iterator j;
	for (j = Ratings.begin(); j != Ratings.end(); j++)
	{
		RemoveRatingInMovie((*j), oldMovie);
	}

	Datas->Movies.erase(find(Datas->Movies.begin(), Datas->Movies.end(), oldMovie));
	return true;
	*/

	Movie* deleteThis = Datas->FindTheMovie(MovieId);
	if (deleteThis == NULL) return false;
	Datas->Movies.remove(deleteThis);

	deleteThis->studio = NULL;

	Datas->RemoveRelationCommentsHaveMovies(deleteThis);
	Datas->RemoveRelationRatingsHaveMovies(deleteThis);

	delete deleteThis;
	return true;
}

bool Background::RemoveRating(int RatingId)
{	
	/*
	Rating *oldRating = Datas->FindTheRating(RatingId);

	RemoveRatingInUser(oldRating, oldRating->UserId);
	RemoveRatingInMovie(oldRating, oldRating->MovieId);

	Datas->Ratings.erase(find(Datas->Ratings.begin(), Datas->Ratings.end(), oldRating));
	return true;
	*/

	Rating* deleteThis = Datas->FindTheRating(RatingId);
	if (deleteThis == NULL)	return false;
	Datas->Ratings.remove(deleteThis);

	deleteThis->UserId = NULL;
	deleteThis->MovieId = NULL;

	delete deleteThis;
	return true;
}

bool Background::RemoveStudio(int StudioId)
{
	/*
	Studio *oldStudio = Datas->FindTheStudio(StudioId);

	list<Movie*>::iterator i;

	for (i = Movies.begin(); i != Movies.end(); i++)
	{
		RemoveMovieInStudio((*i), oldStudio);
	}

	Datas->Studios.erase(find(Datas->Studios.begin(), Datas->Studios.end(), oldStudio));
	return true;
	*/
	Studio* deleteThis = Datas->FindTheStudio(StudioId);
	if (deleteThis == NULL) return false;
	Datas->Studios.remove(deleteThis);

	Datas->RemoveRelationMoviesHaveStudios(deleteThis);

	delete deleteThis;
	return true;
}

bool Background::RemoveUser(int UserId)
{
	/*
	User *oldUser = Datas->FindTheUser(UserId);

	list<Comment*>::iterator i;
	for (i = Comments.begin(); i != Comments.end(); i++)			//HEPSÝ ÝTERATOR'A ÇEVRÝLMELÝ
	{
		RemoveCommentInUser((*i), oldUser);
	}

	list<Rating*>::iterator j;
	for (j = Ratings.begin(); j != Ratings.end(); j++)
	{
		RemoveRatingInUser((*j), oldUser);
	}

	Datas->Users.erase(find(Datas->Users.begin(), Datas->Users.end(), oldUser));
	return true;
	*/
	User* deleteThis = Datas->FindTheUser(UserId);
	if (deleteThis == NULL) return false;
	Datas->Users.remove(deleteThis);

	Datas->RemoveRelationCommentsHaveUsers(deleteThis);
	Datas->RemoveRelationRatingsHaveUsers(deleteThis);
}

bool Background::SaveCommentInUser(Comment * comment, User * user)
{
	comment->UserId = user;
	user->comments.push_back(comment);
	return true;
}

bool Background::SaveCommentInMovie(Comment * comment, Movie * movie)
{
	comment->MovieId = movie;
	movie->comments.push_back(comment);
	return true;
}

bool Background::SaveMovieInStudio(Movie * movie, Studio * studio)
{
	movie->studio = studio;
	studio->movies.push_back(movie);
	return true;
}

bool Background::SaveRatingInUser(Rating * rating, User * user)
{
	rating->UserId = user;
	user->ratings.push_back(rating);
	return true;
}

bool Background::SaveRatingInMovie(Rating * rating, Movie * movie)
{
	rating->MovieId = movie;
	movie->ratings.push_back(rating);
	return true;
}

bool Background::RemoveCommentInUser(Comment * comment, User * user)
{
	comment->UserId;
	list<Comment*> &comments = user->comments;
	comments.erase(find(comments.begin(), comments.end(), comment));
	return true;
}

bool Background::RemoveCommentInMovie(Comment * comment, Movie * movie)
{
	comment->MovieId;
	list<Comment*> &comments = movie->comments;
	comments.erase(find(comments.begin(), comments.end(), comment));
	return true;
}

bool Background::RemoveMovieInStudio(Movie * movie, Studio * studio)
{
	movie->studio;
	list<Movie*> &movies = studio->movies;
	movies.erase(find(movies.begin(), movies.end(), movie));
	return true;
}

bool Background::RemoveRatingInUser(Rating * rating, User * user)
{
	rating->UserId;
	list<Rating*> &ratings = user->ratings;
	ratings.erase(find(ratings.begin(), ratings.end(), ratings));
	return true;
}

bool Background::RemoveRatingInMovie(Rating * rating, Movie * movie)
{
	rating->MovieId;
	list<Rating*> &ratings = movie->ratings;
	ratings.erase(find(ratings.begin(), ratings.end(), rating));
	return true;
}
