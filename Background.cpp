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
{
	Comment *oldComment = Datas->FindTheComment(CommentId);

	RemoveCommentInMovie(oldComment, oldComment->MovieId);

	RemoveCommentInUser(oldComment, oldComment->UserId);

	Datas->Comments.erase(find(Datas->Comments.begin(), Datas->Comments.end(), oldComment));

	delete oldComment;
	return true;
}

bool Background::RemoveMovie(int MovieId)
{
	Movie *oldMovie = Datas->FindTheMovie(MovieId);

	RemoveMovieInStudio(oldMovie, oldMovie->studio);

	list<Comment*> &comments = oldMovie->comments;
	int length = comments.size();
	for (int i = 0; i < length; i++)
	{
		RemoveCommentInMovie(comments[i], oldMovie);
	}

	list<Rating*> &ratings = oldMovie->ratings;
	length = ratings.size();
	for (int i = 0; i < length; i++)
	{
		RemoveRatingInMovie(ratings[i], oldMovie);
	}

	Datas->Movies.erase(find(Datas->Movies.begin(), Datas->Movies.end(), oldMovie));
	return true;
}

bool Background::RemoveRating(int RatingId)
{
	Rating *oldRating = Datas->FindTheRating(RatingId);

	RemoveRatingInUser(oldRating, oldRating->UserId);
	RemoveRatingInMovie(oldRating, oldRating->MovieId);

	Datas->Ratings.erase(find(Datas->Ratings.begin(), Datas->Ratings.end(), oldRating));
	return true;
}

bool Background::RemoveStudio(int StudioId)
{
	Studio *oldStudio = Datas->FindTheStudio(StudioId);

	list<Movie*> &movies = oldStudio->movies;
	int length = movies.size();
	for (int i = 0; i < length; i++)
	{
		RemoveMovieInStudio(movies[i], oldStudio);
	}

	Datas->Studios.erase(find(Datas->Studios.begin(), Datas->Studios.end(), oldStudio));
	return true;
}

bool Background::RemoveUser(int UserId)
{
	User *oldUser = Datas->FindTheUser(UserId);

	list<Comment*>::iterator i;
	for (i = Comments.begin(); i != Comments.end(); i++)			//HEPSÝ ÝTERATOR'A ÇEVRÝLMELÝ
	{
		RemoveCommentInUser(Comments(*i), oldUser);
	}

	list<Rating*> &ratings = oldUser->ratings;
	length = ratings.size();
	for (int i = 0; i < length; i++)
	{
		RemoveRatingInUser(ratings[i], oldUser);
	}

	Datas->Users.erase(find(Datas->Users.begin(), Datas->Users.end(), oldUser));
	return true;
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
